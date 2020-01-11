#ifndef MULTIPLE_TEXT_FILE_IO
#define MULTIPLE_TEXT_FILE_IO

#include "Data.hpp"
#include "TextFileIO.hpp"
#include <string>
#include <list>

class MultipleTextFileIO : public FileIO
{
public:
    Data<std::list<std::string>> readFile(std::list<std::string> paths);
    bool writeFile(std::list<std::string> paths, Data<std::list<std::string>> data);
};
#endif