#include "InputImageHandlerTrainer.hpp"
#include "TrainingPanel.hpp"

InputImageHandlerTrainer::InputImageHandlerTrainer(TrainingDistributor *distributor) : InputImageHandler(distributor){
    this->trainingdistributor = distributor;
    this->page = distributor->getPage();
}

std::vector<std::string> InputImageHandlerTrainer::fetchDirectory()
{
        TrainingPanel* page = trainingdistributor->getPage();
        return page->getFilesFromExplorer(validformatsmanual);
}

void InputImageHandlerTrainer::sendDirectory(std::vector<std::string> dir) {
    trainingdistributor->setInput(dir);
    trainingdistributor->enableStart();
}
