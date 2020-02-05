#include "DetectionDataFacade.hpp"
#include "ModelFacade.hpp"
#include "DetectionData.hpp"
#include "MultipleTextFileIO.hpp"
#include "DetectionDataParser.hpp"

#include <string>
#include <list>

DetectionData DetectionDataFacade::loadDetectionData(std::string directory){
    std::list<std::string> files = ModelFacade::readDirectory(directory);
    std::list<std::string> txtFiles = std::list<std::string>();
    // Filter for .txt files
    for (auto it = files.begin(); it != files.end(); ++it)
    {
        int length = it->length();
        if ((*it).at(length - 1) == 't' && (*it).at(length - 2) == 'x' && (*it).at(length - 3) == 't' && (*it).at(length - 4) == '.')
        {
            txtFiles.push_back(*it);
        }
    }

    std::list<std::string> filesContent = MultipleTextFileIO().readFile(txtFiles).getData();
    DetectionData data = DetectionDataParser().parse(filesContent);
    return data;
}
