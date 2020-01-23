#ifndef FILE_IO_H_
#define FILE_IO_H_

#include <string>

class FileIO
{
protected:
    virtual std::string readPureFile(std::string path);
    virtual bool writePureFile(std::string path, std::string output);
};
#endif
