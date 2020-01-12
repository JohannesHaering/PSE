#include <list>
#include <map>

#include "Mode.h"

class DispatchManager 
{
	private:
		DispatchManager();	
	        // Stop the compiler generating methods of copy the object
		DispatchManager(DispatchManager const& copy); //don't implement!
		DispatchManager& operator=(DispatchManager const& copy); //don't implement!
		Mode mode;
		std::list<Device> deviceList;
		std::map<Device,Channel> deviceChannelMap;

	public:
		static DispatchManager& getInstance(); 
		void setMode(Mode operatingmode);
		Mode getMode();
		std::list<Mode> getModeList();
		void setNeuralNetworkList(std::list<NeuralNetwork> neuralNetworkList);
		std::list<NeuralNetwork> getNeuralNetworkList();
		ResultManager dispatchImages(std::list<image> imageList);
}
