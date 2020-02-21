#ifndef HIGH_PERFORMANCE_MODE_H_
#define HIGH_PERFORMANCE_MODE_H_

#include <string>
#include <list>
#include "Mode.hpp"

class HighPerformanceMode : public Mode{
	public:
		HighPerformanceMode();
		std::pair<float, float> calculate(std::list<Device> deviceList, int imageAmount);
		std::list<std::tuple<DeviceType, NeuralNetworkAdapter, TENSOR(float), std::vector<std::string>>> getImageDistribution(std::list<std::string> imageList) override;

};
#endif
