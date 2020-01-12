#include "ClassificationDatasetFacade.hpp"
#include "ModelFacade.hpp"
#include "FileIO.hpp"
#include "MultipleTextFileIO.hpp"
#include "ClassificationResult.hpp"
#include "ClassificationDatasetParser.hpp"

#include <string>
#include <list>

std::list<ClassificationResult> ClassificationDatasetFacade::loadDataset(std::string directory)
{
    std::list<std::string> files = ModelFacade::readDirectory(directory);
    std::list<std::string> txtFiles;
    // Filter for .txt files
    for (auto it = files.begin(); it != files.end(); ++it)
    {
        int length = (*it).length;
        if ((*it)[length - 1] == 't' && (*it)[length - 2] == 'x' && (*it)[length - 3] == 't' && (*it)[length - 4] == '.')
        {
            txtFiles.push_back(*it);
        }
    }

    std::list<std::string> filesContent = MultipleTextFileIO().readFile(txtFiles).getData();

    std::list<ClassificationResult> dataset;
    for (auto it = filesContent.begin(); it != filesContent.end(); ++it)
    {
        dataset.push_back(ClassificationDatasetParser().parse(*it));
    }

    return dataset;
}