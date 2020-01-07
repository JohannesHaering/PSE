#include "../include/Data.hpp"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class FileIO {
    public:
        static FileIO getInstance();
        Data readFile(string path);
        bool writeFile(string path, Data data);
    protected:
        string readPureFile(string path);
    private:
        static FileIO singleton;
        FileIO();
};