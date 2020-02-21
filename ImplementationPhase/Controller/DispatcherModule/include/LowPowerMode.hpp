#ifndef LOW_POWER_MODE_H_
#define LOW_POWER_MODE_H_

#include <string>
#include <list>
#include "Mode.hpp"
class LowPowerMode : public Mode{
	public:
		LowPowerMode();
		std::pair<float, float> calculate(std::list<Device> deviceList, int imageAmount);
		std::list<std::tuple<DeviceType, NeuralNetworkAdapter, TENSOR(float), std::vector<std::string>>> getImageDistribution(std::list<std::string> imageList) override;
};
#endif
