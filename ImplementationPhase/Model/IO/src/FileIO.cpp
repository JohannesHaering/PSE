#include "../include/Data.hpp"
#include "../include/FileIO.hpp"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

template <typename Data>

class FileIO{
    public:
        static FileIO getInstance() {
            if(singleton == null) {
                singleton = FileIO();
            }
            return singleton;
        }
        virtual bool writeFile(string path, Data data) {
            ofstream file(path);
            string output = to_string(Data.getData());
            file << output;
            file.close;
            return true;
        }
        virtual Data readFile(string path);
    protected:
        virtual string readPureFile(string path) {
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
    private:
        static FileIO singleton;
        FileIO() {

        }
};