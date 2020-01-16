#include "InferencePage.hpp"
#include "DeviceHandler.hpp"
#include "Device.hpp"
#include "DispatchManager.hpp"

DeviceHandler::DeviceHandler(InferencePage page) {}

/**
 * Calculates new prediction.
 */ 
void DeviceHandler::onAction(){
	std::vector<Device> devices = DispatchManager::getAvailableDevices();
	page.setDevices(devices);
	page.update();
}