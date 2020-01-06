#include <string>

using namespace std;

class Result {
	public:
		Result(string imageID, string neuralNetworkID) : imageID(imageID), neuralNetworkID(neuralNetworkID) {}
		/*Result(string imageID, string neuralNetworkID) 
		{
			this.imageID = imageID;
			this.neuralNetworkID = neuralNetworkID
		}*/
		string GetImageID() {
			return imageID;
		}
		string GetNeuralNetworkID() {
			return neuralNetworkID;
		}
	
	private:
		string imageID;
		string neuralNetworkID;
};
