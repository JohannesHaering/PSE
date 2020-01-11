#include <string>
class Device {
	private:
		std::string name;
		std::string type;
		long ram;
		double performance;
	public:
		Device(std::string type, std::string name, long ram, double performance);
		std::string getType();
		std::string getName();
		long getRAM();
		double getPerformance();
};
