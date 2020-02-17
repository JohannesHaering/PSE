#include "TrainerDataSupply.hpp"
#include "ImageFacade.hpp"

#include <string>
#include <list>
#include <vector>
#include <map>
#include <opencv2/opencv.hpp>

std::string TrainerDataSupply::extractFileName(std::string path)
{
    const size_t last_slash_idx = path.find_last_of("\\/");
    if (std::string::npos != last_slash_idx)
    {
        path < path.erase(0, last_slash_idx + 1);
    }
    return path;
}
