#ifndef HIGH_PERFORMANCE_MODE_H_
#define HIGH_PERFORMANCE_MODE_H_

#include <string>
#include <list>
#include "Mode.hpp"

class HighPerformanceMode : public Mode{
	public:
		HighPerformanceMode();
		std::pair<float, float> calculate(std::list<Device> deviceList, int imageAmount);

    protected:
		std::list<std::tuple<Device, std::list<NeuralNetworkAdapter>, std::list<cv::Mat>>> getImageDistribution(std::list<cv::Mat> imageList) override;
};
#endif
