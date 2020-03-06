#include "ViewFacade.hpp"
#include "EventHandler.hpp"
#include "FileExplorerHandler.hpp"
#include <string>
#include <vector>

/*
 * Calls the view to open a fileexplorer and gives those to the corresponding object.
 */
void FileExplorerHandler::onAction(){
    try {
        std::vector<std::string> res = fetchDirectory();
        std::cout << "jop" << std::endl;
        if (res.size() == 0) {
          std::cout << "lul" << std::endl;
          throw std::invalid_argument( "Nothing chosen" );
          std::cout << "lul?" << std::endl;
        }
        sendDirectory(res);
    }
    catch (const std::invalid_argument& ia)
    {
        page->showError(ia.what());
    }
}


