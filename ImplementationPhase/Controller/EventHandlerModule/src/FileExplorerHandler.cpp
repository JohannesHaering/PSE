#include "ViewFacade.hpp"
#include "EventHandler.hpp"
#include "FileExplorerHandler.hpp"
#include <string>
#include <vector>


/*
 * Calls the view to open a fileexplorer and gives those to the corresponding object.
 */
void FileExplorerHandler::onAction(){
    std::cout<<"Got this far\n";
    try {
        std::cout<<"Before the end\n";
        std::vector<std::string> res = fetchDirectory();
        std::cout<<"But in the end\n";
        sendDirectory(res);
    }
    catch (const std::invalid_argument& ia)
    {
        std::cout<<"Cougth it?\n";
        page->showError(ia.what());
    }
}


