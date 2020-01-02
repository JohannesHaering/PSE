

class DispatchManager 
{
	private:
		DispatchManager();	
	        // Stop the compiler generating methods of copy the object
		DispatchManager(DispatchManager const& copy); //not implemented
		DispatchManager& operator=(DispatchManager const& copy); //not implemented
		Mode mode;
		list<Device> deviceList;
		map<Device,Channel> deviceChannelMap;

	public:
		static DispatchManager& getInstance() {
			static DispatchManager instance;
			return instance;
		}	
		void setMode(Mode operatingmode);
		Mode getMode();
		list<Mode> getModeList();
		void setNeuralNetworkList(list<NeuralNetwork> neuralNetworkList);
		list<NeuralNetwork> getNeuralNetworkList();
		ResultManager dispatchImages(list<image> imageList);
}
