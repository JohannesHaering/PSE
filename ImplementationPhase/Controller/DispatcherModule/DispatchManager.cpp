

class DispatchManager 
{
	private:
		DispatchManager();	
	        // Stop the compiler generating methods of copy the object
		DispatchManager(DispatchManager const& copy); //not implemented
		DispatchManager& operator=(DispatchManager const& copy); //not implemented
		Mode mode;
		list<Device> deviceList;
		list<NeuralNetwork> neuralNetworkList;
		map<Device,Channel> deviceChannelMap;

	public:
		static DispatchManager& getInstance() {
			static DispatchManager instance;
			return instance;
		}	
		void setMode(Mode operatingMode) {
			this.mode = operatingMode;
		}
		Mode getMode() {
			return mode;
		}
		list<Mode> getModeList() {
			return NULL//TODO;
		}
		void setNeuralNetworkList(list<NeuralNetwork> neuralNetworkList) {
			this.neuralNetworkList = neuralNetworkList;
		}
		list<NeuralNetwork> getNeuralNetworkList() {
			return neuralNetworkList;
		}
		ResultManager dispatchImages(list<image> imageList) {
			//TODO
		}
}
