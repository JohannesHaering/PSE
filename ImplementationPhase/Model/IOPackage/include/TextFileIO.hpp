#ifndef TEXT_FILE_IO_H
#define TEXT_FILE_IO_H
#include "Data.hpp"
#include "FileIO.hpp"
#include <string>

class TextFileIO : public FileIO
{
public:
    Data<std::string> readFile(std::string path);
    bool writeFile(std::string path, Data<std::string> data);
};
#endif