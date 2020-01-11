#include "Data.hpp"
#include "FileIO.hpp"
#include "TextFileIO.hpp"
#include <string>
#include <iostream>
#include <fstream>

Data<std::string> TextFileIO::readFile(std::string path) {
    Data<std::string> data = Data<std::string>(FileIO::readPureFile(path));
    return data;
}

bool TextFileIO::writeFile(std::string path, Data<std::string> data){
    auto success = FileIO::writePureFile(path, data.getData());     
    return success;       
}
