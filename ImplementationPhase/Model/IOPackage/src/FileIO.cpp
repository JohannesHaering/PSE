#include "Data.hpp"
#include "FileIO.hpp"
#include <string>
#include <iostream>
#include <fstream>

std::string FileIO::readPureFile(std::string path)
{
    std::ifstream file(path);
    std::string output = "";
    std::string temp;

    while (getline(file, temp))
    {
        output += temp;
        output += "\n";
    }

    file.close();

    return output;
}
bool FileIO::writePureFile(std::string path, std::string output)
{
    std::ofstream file(path);
    file << output;
    file.close();
    return true;
}