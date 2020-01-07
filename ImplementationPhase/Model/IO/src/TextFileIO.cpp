
#include "../include/Data.hpp"
#include "../include/FileIO.hpp"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class TextFileIO : public FileIO {
    public:
        bool writeFile(string path, Data data){
            auto success = FileIO::writeFile(path, data);     
            return success;       
        }
};
