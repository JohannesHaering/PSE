#ifndef RESULT_H_
#define RESULT_H_
#include <string>

using namespace std;

class Result {
	public:
		Result(string imageID, string neuralNetworkID);
		string GetImageID();
		string GetNeuralNetworkID();
	
	//private:
	protected:
		string imageID;
		string neuralNetworkID;
};
#endif
