#include "ModelFacade.hpp"
#include "ImageFileIO.hpp"
#include "MultipleImageFileIO.hpp"
#include "VideoFileIO.hpp"
#include "CameraHandler.hpp"
#include "VideoHandler.hpp"
#include "ImageParserWithSizing.hpp"
#include "ImageFacade.hpp"
#include "MatrixDefine.hpp"

#include <opencv2/opencv.hpp>
#include <string>
#include <list>
#include <vector>

cv::Mat ImageFacade::getImage(std::string path, int width, int height, int channelNumb)
{
	cv::Mat image = ImageFileIO().readFile(path).getData();
	cv::Mat parsedImage;
	if (width != 0)
		parsedImage = ImageParserWithSizing(width, height, channelNumb).parse(image);
	else
		parsedImage = image;
	return parsedImage;
}

std::list<cv::Mat> ImageFacade::getImages(std::list<std::string> paths, int width, int height, int channelNumb)
{
	std::list<cv::Mat> images;
	for (auto it = paths.begin(); it != paths.end(); ++it)
	{
		images.push_back(getImage(*it, width, height, channelNumb));
	}
	return images;
}

std::vector<TENSOR(float)> ImageFacade::getImages(std::string directory, int batchSize, int width, int height) {
	std::list<std::string> paths = ModelFacade::readDirectory(directory);
	std::vector<std::vector<float>> images = std::vector<std::vector<float>>();

	for (std::list<std::string>::iterator it = paths.begin(); it != paths.end(); ++it)
		images.push_back(getImageGreyScale(*it, width, height, 1));

	std::vector<TENSOR(float)> tensors = std::vector<TENSOR(float)>();

	int batch = 0;
	std::vector<std::vector<std::vector<std::vector<float>>>> tensor = std::vector<std::vector<std::vector<std::vector<float>>>>();
	for (int i = 0; i < images.size(); i++) {
		std::vector<std::vector<std::vector<float>>> v = std::vector<std::vector<std::vector<float>>>();
		std::vector<std::vector<float>> image = std::vector<std::vector<float>>();
		for (int y = 0; y < height; y++) {
			std::vector<float> row = std::vector<float>();
			for (int x = 0; x < width; x++) {
				row.push_back(images[i][x + y * width]);
			}
			image.push_back(row);
		}
		v.push_back(image);
		tensor.push_back(v);

		if (i % batchSize == 0 && batchSize > 0) {
			tensors.push_back(tensor);
			tensor = std::vector<std::vector<std::vector<std::vector<float>>>>();
		}
	}

	return tensors;
}

std::list<cv::Mat> ImageFacade::getImagesFromTxtFile(std::string path, int width, int height, int channelNumb)
{
	std::list<std::string> paths = ModelFacade::readDirectory(path);
	return getImages(paths, width, height, channelNumb);
}

cv::Mat ImageFacade::getImageFromCamera(int deviceId, int width, int height, int channelNumb)
{
	auto cameraHandler = CameraHandler(deviceId, 30);
	cv::Mat capturedImage = cameraHandler.getNextFrame();
	cv::Mat parsedCapturedImage = ImageParserWithSizing(width, height, channelNumb).parse(capturedImage);
	return parsedCapturedImage;
}

std::list<cv::Mat> ImageFacade::getImagesFromVideo(std::string path, int width, int height, int channelNumb)
{
	auto video = VideoFileIO().readFile(path).getData();
	auto videoHandler = VideoHandler(1);
	std::list<cv::Mat> frames = videoHandler.handleVideo(video);
	std::list<cv::Mat> parsedFrames;
	for (auto it = frames.begin(); it != frames.end(); ++it)
	{
		parsedFrames.push_back(ImageParserWithSizing(width, height, channelNumb).parse(*it));
	}
	return parsedFrames;
}

bool ImageFacade::writeImage(std::string path, cv::Mat image)
{
	return ImageFileIO().writeFile(Data<cv::Mat>(image), path);
}

bool ImageFacade::writeImages(std::list<std::string> paths, std::list<cv::Mat> images) {
	return MultipleImageFileIO().writeFile(Data<std::list<cv::Mat>>(images), paths);
}

std::vector<float> ImageFacade::getImageGreyScale(std::string path, int width, int height, int channels) {
	cv::Mat image = ImageFileIO().readFile(path).getData();
	std::vector<float> parsed = ImageParserWithSizing(width, height, channels).parseFloatsGreyScale(image);
	return parsed;
}

TENSOR(float) ImageFacade::createImageTensor(std::vector<cv::Mat> images, int width, int height){
	TENSOR(float) tensor = TENSOR(float)(images.size(), MATRIX_3D(float)(1, MATRIX_2D(float)(height, std::vector<float>(width))));

	for (int i = 0; i < images.size(); i++) {
		std::vector<float> image = ImageParserWithSizing(width, height, 1).parseFloatsGreyScale(images[i]);
    std::cout<<image.size()<<std::endl;   
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
	      tensor[i][0][y][x] = image[y * width + x];
      }
		}
	}

	return tensor;
}
