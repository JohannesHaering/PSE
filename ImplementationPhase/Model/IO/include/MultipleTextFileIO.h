#ifndef MULTIPLE_TEXT_FILE_IO
#define MULTIPLE_TEXT_FILE_IO

#include "Data.h"
#include "TextFileIO.h"
#include <string>
#include <list>

using namespace std;

class MultipleTextFileIO : public FileIO {
    public:
        Data<list<string>> readFile(list<string> paths);
        bool writeFile(list<string> paths, Data<list<string>> data);
};
#endif