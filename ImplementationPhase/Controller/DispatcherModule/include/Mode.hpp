#ifndef MODE_H_
#define MODE_H_

#include <list>
#include <string>
#include <utility>
#include <tuple>

#include <opencv2/opencv.hpp>
#include "NeuralNetworkAdapter.hpp"
class Mode {
	private:
 		std::string modeName;
		std::list<Device> deviceList;
		std::list<NeuralNetworkAdapter> neuralNetworkList;
	public: 
		std::string getModeName();
		void setAllowedDeviceList(std::list<Device> deviceList);
		std::list<Device> getAllowedDeviceList();
		void setNeuralNetworkAdapterList(std::list<NeuralNetworkAdapter> neuralNetworkList);
		std::list<NeuralNetworkAdapter> getNeuralNetworkAdapterList();
	protected:
		Mode(std::string modeName);
		virtual std::list<std::tuple<Device, std::list<NeuralNetworkAdapter>, std::list<cv::Mat>>> getImageDistribution(std::list<cv::Mat>) = 0;
};
#endif
