#include "TrainerDataSupply.hpp"
#include "ImageFacade.hpp"

#include <string>
#include <list>
#include <vector>
#include <map>
#include <opencv2/opencv.hpp>

TrainerDataSupply::TrainerDataSupply(std::list<std::string> ids, std::string directory, int width, int height, int channels)
{
    ImageFacade facade = ImageFacade();
    std::list<std::string> files = facade.readDirectory(directory);
    for (auto it = files.begin(); it != files.end(); ++it)
    {
        std::string filename = extractFileName(*it);
        std::string fileExtension = filename.substr(filename.find_last_of(".") + 1);
        if (fileExtension.compare("jpg") || fileExtension.compare("png") || fileExtension.compare("bmp"))
        {
            ids.push_back(filename);
            images[filename] = facade.getImage(*it, width, height, channels);
        }
    }
    size = images.size();
}

std::list<std::string> TrainerDataSupply::getDataIds() { return ids; }

cv::Mat TrainerDataSupply::getImage(std::string id) { return images[id]; }

std::string TrainerDataSupply::extractFileName(std::string path)
{
    const size_t last_slash_idx = path.find_last_of("\\/");
    if (std::string::npos != last_slash_idx)
    {
        path < path.erase(0, last_slash_idx + 1);
    }
    return path;
}

int TrainerDataSupply::getSize(){ return size; }
