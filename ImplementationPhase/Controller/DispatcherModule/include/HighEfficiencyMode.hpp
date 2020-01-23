#ifndef HIGH_EFFICIENCY_MODE_H_
#define HIGH_EFFICIENCY_MODE_H_

#include <string>
#include <list>

class HighEfficiencyMode : public Mode{
	public:
		std::pair<float, float> calculate(std::list<Device> deviceList, int imageAmount);
		std::list<std::tuple<Device, std::list<NeuralNetwork>, std::list<cv::Mat>>> Mode::getImageDistribution(std::list<cv::mat> imageList) override; 
};
#endif
