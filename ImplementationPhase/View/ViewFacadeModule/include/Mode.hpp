#include "NeuralNetworkAdapter.hpp"
#include "Device.hpp"

class Mode {

    public:
		void setAllowedDeviceList(std::vector<Device> deviceList);
		void setNeuralNetworkList(std::vector<NeuralNetworkAdapter> neuralNetworkList);
		void setImageList(std::vector<std::string> imageList);
		void setModeName(std::string);

};