#include <list>
#include <utility>

//#include <opencv2/opencv.hpp>
class Mode {
	private:
 		string modeName;
		std::list<Device> deviceList;
		std::list<NeuralNetwork> neuralNetworkList;
		std::list<cv::Mat> imageList;
	public: 
		Mode();
		std::string getModeName();
		void setAllowedDeviceList(std::list<Device> deviceList);
		void setNeuralNetworkList(std::list<NeuralNetwork> neuralNetworkList);
		void setImageList(std::list<Image> imageList);
		std::list<Device, std::list<NeuralNetwork>, std::list<image>> getImageDistribution()
	protected:
		virtual std::pair<float, float> calculate(std::list<Device> deviceList, int imgAmount) = 0; #abstract class
}
