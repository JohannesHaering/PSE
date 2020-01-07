#include "../include/Data.h"
#include "../include/FileIO.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

FileIO FileIO::getInstance() {
    if(&singleton == 0) {
        singleton = FileIO();
    }
    return singleton;
}
string FileIO::readPureFile(string path) {
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
bool FileIO::writePureFile(string path, string output){
    ofstream file(path);
    file << output;
    file.close();
    return true;
}