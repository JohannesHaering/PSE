#include "../include/Data.h"
#include "../include/TextFileIO.h"
#include "../include/MultipleTextFileIO.h"
#include <string>
#include <list>

using namespace std;


Data<list<string>> MultipleTextFileIO::readFile(list<string> paths) {
    list<string> rawData;
    for(list<string>::iterator it=paths.begin(); it != paths.end(); ++it){
        rawData.push_back(FileIO::readPureFile(*it));
    }
    return Data(rawData);
}

bool MultipleTextFileIO::writeFile(list<string> paths, Data<list<string>> data) {
    list<string> output = data.getData();
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