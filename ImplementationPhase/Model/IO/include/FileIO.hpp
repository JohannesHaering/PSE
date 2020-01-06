#include "Data.hpp"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class FileIO {
    public:
        static FileIO getInstance();
        string readFile(string path);
        bool writeFile(string path, Data data);
        ~FileIO();
    private:
        static FileIO singleton;
        FileIO();
};