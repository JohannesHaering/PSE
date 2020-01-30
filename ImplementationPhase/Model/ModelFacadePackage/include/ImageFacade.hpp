#ifndef IMAGE_FACADE_H_
#define IMAGE_FACADE_H_

#include "ModelFacade.hpp"

#include <opencv2/opencv.hpp>
#include <string>
#include <list>

class ImageFacade : public ModelFacade {
    public:
        cv::Mat getImage(std::string path, int width, int height, int channelNumb);
//		cv::Mat getImage(std::string path);
        std::list<cv::Mat> getImages(std::list<std::string> paths, int width, int height, int channelNumb);
//		std::list<cv::Mat> getImages(std::list<std::string> paths);
        std::list<cv::Mat> getImagesFromTxtFile(std::string path, int width, int height, int channelNumb);
        cv::Mat getImageFromCamera(int deviceId,  int width, int height, int channelNumb);
        std::list<cv::Mat> getImagesFromVideo(std::string path, int width, int height, int channelNumb);
        bool writeImage(std::string path, cv::Mat image);
        bool writeImages(std::list<std::string> paths, std::list<cv::Mat> images);
};
#endif
