#include "ViewFacade.hpp"
#include "EventHandler.hpp"
#include "FileExplorerHandler.hpp"
#include <string>
#include <vector>
#include <stdexcept>

/*
 * Calls the view to open a fileexplorer and gives those to the corresponding object.
 */
void FileExplorerHandler::onAction(){
    try {
        std::vector<std::string> res = fetchDirectory();
        if (res.size() == 0) {
          throw std::invalid_argument( "Nothing chosen" );
        }
        sendDirectory(res);
    }
    catch (const std::invalid_argument& ia)
    {
        page->showError(ia.what());
    }
}


