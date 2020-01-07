#ifndef FILE_IO_H
#define FILE_IO_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class FileIO {
    public:
        static FileIO getInstance();
    protected:
        virtual string readPureFile(string path);
        virtual bool  writePureFile(string path, string output);
    private:
        static FileIO singleton;
        FileIO() {

        }
};
#endif
