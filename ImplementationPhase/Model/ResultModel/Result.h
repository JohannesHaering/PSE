#include <string>

using namespace std;

class Result {
	public:
		Result(string imageID, string neuralNetworkID);
		string GetImageID();
		string GetNeuralNetworkID();
	
	private:
		string imageID;
		string neuralNetworkID;
}
