#include <string>
#include "device.h"

Device::Device(std::string type, std::string name, long ram, double performance) :
    type(type), name(name), ram(ram), performance(performance) {}

std::string Device::getType() { return type; }

std::string Device::getName() { return name; }

long Device::getRAM() { return ram; }

double Device::getPerformance() { return performance; }
