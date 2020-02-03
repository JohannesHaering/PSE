#include "ViewFacade.hpp"
#include "ResultManager.hpp"
#include "DispatchManager.hpp"
#include "PredictionHandler.hpp"
#include "PowerPredictorFromFile.hpp"
#include "PerformancePredictorFromFile.hpp"
#include "InferencePageAdapter.hpp"
#include <list>
#include <CL/cl2.hpp>

PredictionHandler::PredictionHandler(InferencePageAdapter *page) :
page(page),
powerPredictor(new PowerPredictorFromFile()),
performancePredictor(new PerformancePredictorFromFile())
{}

PredictionHandler::~PredictionHandler()
{
	delete powerPredictor;
	delete performancePredictor;
}

/**
 * Calculates new prediction.
 */
void PredictionHandler::onAction(){

	std::vector<Device> devices = page->getDevices();
	std::list<std::string> devicelist;

	for (std::vector<Device>::iterator it = devices.begin(); it != devices.end(); ++it) {
		devicelist.push_back(it->getName());
	}

	std::map<std::string, float> performancePredictionValues = performancePredictor->predict(devicelist);
	std::map<std::string, float> powerPredictionValues = powerPredictor->predict(devicelist);

	float performancePrediction = 0;
	float powerPrediction = 0;

	std::map<std::string, float>::iterator it;
    for ( it = performancePredictionValues.begin(); it != performancePredictionValues.end(); ++it )
    {
			performancePrediction += it->second;
    }

	// std::map<std::string, float>::iterator it;
    for ( it = powerPredictionValues.begin(); it != powerPredictionValues.end(); ++it )
    {
		powerPrediction += it->second;
	}

	performancePrediction = this->test();

    page->setPerformancePrediction(performancePrediction);
    page->setPowerPrediction(powerPrediction);

    page->update();
}

float PredictionHandler::test() {
	// Setup OpenCl
	glGetDeviceIDs(NULL, CL_DEVICE_TYPE_CPU, 1, &device, NULL);
	auto context = clCreateContext(NULL, 1, &device, NULL, NULL, NULL);
	auto queue = clCreateCommandQueue(context, device, (cl_command_queue_properties)0, NULL);

	char *code = {
		"kernel void calc(global float *data) {\n"
		"   int id = get_global_id(0);\n"
		"   data[id] = 10 * 4.2f;\n"
		"}\n"
	};

	auto program = clCreateProgramWithSourceCode(context, 1, (const char**)&code, NULL, NULL);
	clBuildProgram(program, 0, NULL, NULL, NULL, NULL);
	auto kernel = clCreateKernel(program, "calc", NULL);

	auto buffer = clCreateKernel(context, CL_MEM_READ_WRITE, DATA_SIZE, NULL, NULL);

	clEnqueueWriteBuffer(queue, buffer, CL_FALSE, 0, DATA_SIZE, data, 0, NULL, NULL);

	clSetKernelArg(kernel, 0, sizeof(buffer), &buffer);
	size_t global_dimensions[] = { LENGTH, 0, 0 };
	clEnqueueNDRangeKernel(queue, kernel, 1, NULL, global_dimensions, NULL, 0, NULL, NULL);

	clEnqueueReadBuffer(queue, buffer, CL_FALSE, 0, sizeof(cl_float)*LENGTH, data, 0, NULL, NULL);

	clFinish(queue);

	return data[0];
}
