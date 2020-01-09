#include <opencv2/opencv.hpp>
class Mode {
	private:
 		string modeName;
		list<Device> deviceList;
		list<NeuralNetwork> neuralNetworkList;
		list<cv::Mat> imageList;
	public: 
		Mode();
		string getModeName();
		void setAllowedDeviceList(list<Device> deviceList);
		void setNeuralNetworkList(list<NeuralNetwork> neuralNetworkList);
		void setImageList(list<Image> imageList);
		list<Device, list<NeuralNetwork>, list<image>> getImageDistribution()
	protected:
		virtual std::pair<float, float> calculate(list<Device> deviceList, int imgAmount) = 0; #abstract class
}
