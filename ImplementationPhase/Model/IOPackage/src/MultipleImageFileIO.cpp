#include "ImageFileIO.hpp"
#include "MultipleImageFileIO.hpp"
#include "Data.hpp"

#include <string>
#include <list>
#include <iostream>
#include <opencv2/opencv.hpp>

Data<std::list<cv::Mat>> MultipleImageFileIO::readFile(std::list<std::string> paths)
{
    std::list<cv::Mat> images;
    for (auto it = paths.begin(); it != paths.end(); ++it)
    {
        //images.push_back(ImageFileIO::readFile(*it)); //orig Johannes
        images.push_back(ImageFileIO().readFile(*it).getData());
    }
    return Data<std::list<cv::Mat>>(images);
}

bool MultipleImageFileIO::writeFile(Data<std::list<cv::Mat>> data, std::list<std::string> paths){
    auto images = data.getData();

    auto imagesIt = images.begin();
    auto pathsIt = paths.begin();

    bool success = true;
    for(; pathsIt != paths.end() || imagesIt != images.end(); ++imagesIt, ++pathsIt)
        success &= ImageFileIO().writeFile(Data(*imagesIt), *pathsIt);
    
    return success;
}

