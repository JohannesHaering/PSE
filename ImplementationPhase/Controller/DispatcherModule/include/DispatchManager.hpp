#ifndef DISPATCHER_MANAGER_H_
#define DISPATCHER_MANAGER_H_

#include "NeuralNetworkAdapter.hpp"
#include "Mode.hpp"
#include "Channel.hpp"
#include "ResultManager.hpp"

#include <opencv2/opencv.hpp>

#include <list>
#include <map>
#include <vector>


class DispatchManager 
{
	private:
		DispatchManager();	
	        // Stop the compiler generating methods of copy the object
		DispatchManager(DispatchManager const& copy); //don't implement!
		DispatchManager& operator=(DispatchManager const& copy); //don't implement!
		Mode& mode;
		std::list<Device> deviceList;
		std::list<NeuralNetworkAdapter> neuralNetworkList;
		std::map<Device,Channel> deviceChannelMap;

	public:
		static DispatchManager& getInstance(); 
		void setMode(Mode& operatingmode);
		Mode& getMode();
		std::list<Mode> getModeList();
		void setNeuralNetworkList(std::list<NeuralNetworkAdapter> neuralNetworkList);
		std::list<NeuralNetworkAdapter> getNeuralNetworkList();
		ResultManager dispatchImages(std::list<cv::Mat> imageList);
		static std::vector<Device> getAvailableDevices();
};
#endif
