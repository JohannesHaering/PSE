#ifndef IMAGE_FACADE_H_
#define IMAGE_FACADE_H_

#include "ModelFacade.hpp"
#include "MatrixDefine.hpp"

#include <opencv2/opencv.hpp>
#include <string>
#include <list>
#include <vector>

class ImageFacade : public ModelFacade {
public:
	std::vector<float> getImageGreyScale(std::string path, int width, int height, int channelNumb);
	cv::Mat getImage(std::string path, int width, int height, int channelNumb);
	std::list<cv::Mat> getImages(std::list<std::string> paths, int width, int height, int channelNumb);
	std::list<cv::Mat> getImagesFromTxtFile(std::string path, int width, int height, int channelNumb);
	cv::Mat getImageFromCamera(int deviceId, int width, int height, int channelNumb);
	std::list<cv::Mat> getImagesFromVideo(std::string path, int width, int height, int channelNumb);
	std::vector<MatrixDefine::TENSOR(float)> getImages(std::string directory, int batchSize, int width, int height);
	MatrixDefine::TENSOR createImageTensor(std::vector<cv::Mat> images, int width, int height);
	bool writeImage(std::string path, cv::Mat image);
	bool writeImages(std::list<std::string> paths, std::list<cv::Mat> images);
};
#endif
