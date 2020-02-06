#include "ModelFacade.hpp"
#include "ImageFileIO.hpp"
#include "MultipleImageFileIO.hpp"
#include "VideoFileIO.hpp"
#include "CameraHandler.hpp"
#include "VideoHandler.hpp"
#include "ImageParserWithSizing.hpp"
#include "ImageFacade.hpp"

#include <opencv2/opencv.hpp>
#include <string>
#include <list>
#include <vector>

cv::Mat ImageFacade::getImage(std::string path, int width, int height, int channelNumb)
{
    cv::Mat image = ImageFileIO().readFile(path).getData();
    cv::Mat parsedImage;
    if(width != 0)
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

bool ImageFacade::writeImages(std::list<std::string> paths, std::list<cv::Mat> images){
    return MultipleImageFileIO().writeFile(Data<std::list<cv::Mat>>(images), paths);
}

std::vector<float> ImageFacade::getImageGreyScale(std::string path, int width, int height, int channels) {
    cv::Mat image = ImageFileIO().readFile(path).getData();
    std::vector<float> parsed = ImageParserWithSizing(width, height, channels).parseFloatsGreyScale(image);
    return parsed;
}
