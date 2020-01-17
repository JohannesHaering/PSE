#include "ModelFacade.hpp"

#include <string>
#include <list>
#include <iostream>
#include <filesystem>

std::list<std::string> readDirectory(std::string directory)
{
    std::list<std::string> files;

    for (const auto &entry : std::filesystem::directory_iterator(directory))
        files.push_back(entry.path().string());

    return files;
}
