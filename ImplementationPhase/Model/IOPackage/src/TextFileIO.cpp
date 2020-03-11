#include "Data.hpp"
#include "FileIO.hpp"
#include "TextFileIO.hpp"
#include <string>
#include <iostream>
#include <fstream>

Data<std::string> TextFileIO::readFile(std::string path)
{
    if (path == "")
        return Data<std::string>("");
    int length = path.length();
	  if (length == 0)
		  return Data<std::string>("");
    
    if (path[length - 1] != 't' || path[length - 2] != 'x' || path[length - 3] != 't' || path[length - 4] != '.')
    {
        return Data<std::string>("");
    }

    Data<std::string> data = Data<std::string>(FileIO::readPureFile(path));
    return data;
}

bool TextFileIO::writeFile(std::string path, Data<std::string> data)
{
    if (path == "")
        return false;
    if (data.getData() == "")
        return false;

    int length = path.length();
	  if (length == 0)
		  return false;
    if (path[length - 1] != 't' || path[length - 2] != 'x' || path[length - 3] != 't' || path[length - 4] != '.')
    {
        return false;
    }

    bool success = FileIO::writePureFile(path, data.getData());
    return success;
}
