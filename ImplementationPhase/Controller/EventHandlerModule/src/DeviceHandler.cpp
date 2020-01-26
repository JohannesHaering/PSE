#include "InferencePageAdapter.hpp"
#include "DeviceHandler.hpp"
#include "Device.hpp"
#include "DispatchManager.hpp"
#include <vector>

DeviceHandler::DeviceHandler(InferencePageAdapter* page) : page(page) {}

/**
 * Calculates new prediction.
 */ 
void DeviceHandler::onAction(){
	std::vector<Device> devices = DispatchManager::getAvailableDevices();
	std::vector<Device>* dev = new std::vector<Device>;
	for (std::vector<Device>::iterator it = devices.begin(); it != devices.end(); ++it) {
		dev->push_back(*it);
	}
	dev->push_back(devices.front());
	page->setDevices(dev);
	page->update();
}