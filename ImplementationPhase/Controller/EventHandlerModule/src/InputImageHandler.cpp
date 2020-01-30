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
        InferencePageAdapter* page = static_cast<InferencePageAdapter*>(distributor->getPage());
        std::cout<<"fetching\n";
		int mode = page->getInputMode();
        std::cout<<"fetchin2\n";

		// normaler mode
        if (mode == 1)
		{
            return page->getFilesFromExplorer(validformatstxt);
		}
		// text file
        else {
            return page->getFilesFromExplorer(validformatsmanual);
		}
}
