#include "../include/Data.h"
#include "../include/FileIO.h"
#include "../include/TextFileIO.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

Data<string> TextFileIO::readFile(string path) {
    Data<string> data = Data<string>(FileIO::readPureFile(path));
    return data;
}

bool TextFileIO::writeFile(string path, Data<string> data){
    auto success = FileIO::writePureFile(path, data.getData());     
    return success;       
}
