#ifndef TEXT_FILE_IO_H
#define TEXT_FILE_IO_H
#include "Data.h"
#include "FileIO.h"

class TextFileIO : public FileIO{
    public:
        Data<string> readFile(string path);
        bool writeFile(string path, Data<string> data);
};
#endif