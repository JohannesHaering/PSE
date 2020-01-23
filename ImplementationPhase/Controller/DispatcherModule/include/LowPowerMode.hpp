#ifndef LOW_POWER_MODE_H_
#define LOW_POWER_MODE_H_

#include <string>
#include <list>

class LowPowerMode : public Mode{
	public:
		std::pair<float, float> calculate(std::list<Device> deviceList, int imageAmount);
		std::list<std::tuple<Device, std::list<NeuralNetwork>, std::list<cv::Mat>>> Mode::getImageDistribution(std::list<cv::mat> imageList) override; 
};
#endif
