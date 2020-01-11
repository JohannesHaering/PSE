#include "Data.hpp"
#include "TextFileIO.hpp"
#include "MultipleTextFileIO.hpp"
#include <string>
#include <list>


Data<std::list<std::string>> MultipleTextFileIO::readFile(std::list<std::string> paths) {
    std::list<std::string> rawData;
    for(std::list<std::string>::iterator it=paths.begin(); it != paths.end(); ++it){
        rawData.push_back(FileIO::readPureFile(*it));
    }
    return Data(rawData);
}

bool MultipleTextFileIO::writeFile(std::list<std::string> paths, Data<std::list<std::string>> data) {
    std::list<std::string> output = data.getData();
    if(paths.size() != output.size()){
        return false;
    }

    auto pathIterator = paths.begin();
    auto outputIterator = output.begin();
    for(;pathIterator != paths.end();){
        auto success = writePureFile(*pathIterator, *outputIterator);
        if(!success) {
            return false;
        }
        ++pathIterator;
        ++outputIterator;
    }

    return true;
}