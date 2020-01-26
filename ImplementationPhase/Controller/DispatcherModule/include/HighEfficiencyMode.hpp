#ifndef HIGH_EFFICIENCY_MODE_H_
#define HIGH_EFFICIENCY_MODE_H_

#include <string>
#include "Mode.hpp"
#include <list>

class HighEfficiencyMode : public Mode{
	public:
		HighEfficiencyMode();
		std::pair<float, float> calculate(std::list<Device> deviceList, int imageAmount);
    protected:
		std::list<std::tuple<Device, std::list<NeuralNetworkAdapter>, std::list<cv::Mat>>> getImageDistribution(std::list<cv::Mat> imageList) override;
};
#endif
