#ifndef MODE_H_
#define MODE_H_

#include <list>
#include <string>
#include <utility>
#include <tuple>

#include <opencv2/opencv.hpp>

#include "NeuralNetworkAdapter.hpp"
#include "Device.hpp"
#include "DeviceType.hpp"

class Mode {
	public: 
		std::string getModeName();
		void setAllowedDeviceList(std::list<Device> deviceList);
		std::list<Device> getAllowedDeviceList();
		void setNeuralNetworkList(std::list<NeuralNetworkAdapter> neuralNetworkList);
		std::list<NeuralNetworkAdapter> getNeuralNetworkList();
		virtual std::list<std::tuple<DeviceType, NeuralNetworkAdapter, TENSOR(float), std::vector<std::string>>> getImageDistribution(std::list<std::string> imageList) = 0;
	protected:
		Mode(std::string modeName);
        std::string modeName;
        std::list<Device> deviceList;
        std::list<NeuralNetworkAdapter> neuralNetworkList;
};
#endif
