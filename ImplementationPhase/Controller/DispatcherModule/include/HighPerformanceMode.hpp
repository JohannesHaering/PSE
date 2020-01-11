#ifndef HIGH_PERFORMANCE_MODE_H_
#define HIGH_PERFORMANCE_MODE_H_

#include <string>
#include <list>

class HighPerformanceMode : public Mode{
	public:
		std::pair<float, float> calculate(std::list<Device> deviceList, int imageAmount);
};
#endif
