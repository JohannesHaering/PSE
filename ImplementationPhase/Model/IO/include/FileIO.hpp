#ifndef FILE_IO_H
#define FILE_IO_H

#include <string>

class FileIO
{
public:
    static FileIO getInstance();

protected:
    virtual std::string readPureFile(std::string path);
    virtual bool writePureFile(std::string path, std::string output);

private:
    static FileIO singleton;
};
#endif
