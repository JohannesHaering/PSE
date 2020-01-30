#include "Distributor.hpp"
#include "FileExplorerHandler.hpp"
#include "ViewFacade.hpp"
#include "InferencePageAdapter.hpp"
#include "InputImageHandler.hpp"
#include <stdexcept>

/**
 * Creates a InputImageHandler.
 * Parameters:
 * -Distributor distributor: The distributor to set the images to.
 */
InputImageHandler::InputImageHandler(Distributor *distributor) : distributor(distributor) { }

/**
 * Sets the image directories of the distributor.
 * Parameters:
 * -std::vector<std::string> directories: The image directories
 */
void InputImageHandler::sendDirectory(std::vector<std::string> directories)
{
    distributor->setInput(directories);
}   

std::vector<std::string> InputImageHandler::fetchDirectory()
{
        InferencePageAdapter* page = dynamic_cast<InferencePageAdapter*>(distributor->getPage());
        int mode = page->getInputMode();

        // normaler mode
        if (mode == 0) {
            return {page->getFileFromExplorer(validformatsmanual)};
        }

        if (mode == 2)
        {
            return page->getFilesFromExplorer(validformatstxt);
        }
        // text file
        else {
            // TODO
            return {page->getFileFromExplorer(validformatsmanual)};
        }
}
