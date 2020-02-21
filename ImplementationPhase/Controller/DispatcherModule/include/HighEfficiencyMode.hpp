#ifndef HIGH_EFFICIENCY_MODE_H_
#define HIGH_EFFICIENCY_MODE_H_

#include <string>
#include "Mode.hpp"
#include <list>

class HighEfficiencyMode : public Mode{
	public:
		HighEfficiencyMode();
		std::pair<float, float> calculate(std::list<Device> deviceList, int imageAmount);
		std::list<std::tuple<DeviceType, NeuralNetworkAdapter, TENSOR(float), std::vector<std::string>>> getImageDistribution(std::list<std::string> imageList) override;
};
#endif
