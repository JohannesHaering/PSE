#include "data.hpp"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

template <typename Data>

class FileIO{
    private:
        static FileIO singleton;
        FileIO() {

        }
    public:
        static FileIO getInstance() {
            if(singleton == null) {
                singleton = FileIO();
            }
            return singleton;
        }

        string readFile(string path) {
            ifstream file(path);
            string output = "";
            string temp;

            while(getline(file, temp)) {
                output += temp;
                output += "\n";
            }

            file.close();

            return output;
        }

        bool writeFile(string path, Data data);

        ~FileIO() {

        }
};