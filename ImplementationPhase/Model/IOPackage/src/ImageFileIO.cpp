#include "ImageFileIO.hpp"

#include <string>
#include <iostream>
#include <opencv2/opencv.hpp>

Data<cv::Mat> ImageFileIO::readFile(std::string path)
{
    if(!isImageFile(path)){
        cv::Mat mat;
        return Data<cv::Mat>(mat);
    }       

    auto image = cv::imread(path, cv::IMREAD_COLOR);
    return Data<cv::Mat>(image);
}

bool ImageFileIO::writeFile(Data<cv::Mat> image, std::string path)
{
	if (!isImageFile(path))
		return false;

    cv::Mat imageRaw = image.getData();
    if(imageRaw.empty())
        return false;
        
    cv::imwrite(path, imageRaw);
    return true;
}

bool ImageFileIO::isImageFile(std::string path)
{
    int length = path.length();
    if (path[length - 1] == 'p' && path[length - 2] == 'm' && path[length - 3] == 'b' && path[length - 4] == '.')
    {
        return true;
    }
    if (path[length - 1] == 'g' && path[length - 2] == 'p' && path[length - 3] == 'j' && path[length - 4] == '.')
    {
        return true;
    }
    if (path[length - 1] == 'g' && path[length - 2] == 'n' && path[length - 3] == 'p' && path[length - 4] == '.')
    {
        return true;
    }

    return false;
}