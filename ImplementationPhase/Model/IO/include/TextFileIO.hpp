#include "Data.hpp"
#include "StringData.hpp"
#include "MultipleStringData.hpp"
#include "ImageData.hpp"
#include "MultipleImageData.hpp"
#include "VideoData.hpp"
#include "FileIO.hpp"

class TextFileIO : public FileIO{
    public:
        Data readFile(string path);
        bool writeFile(string path, Data data);
};