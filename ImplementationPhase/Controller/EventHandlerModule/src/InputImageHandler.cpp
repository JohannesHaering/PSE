#include "Distributor.hpp"
#include "FileExplorerHandler.hpp"
#include "ViewFacade.hpp"
#include "InferencePage.hpp"
#include "InputImageHandler.hpp"

/**
 * Creates a InputImageHandler.
 * Parameters:
 * -Distributor distributor: The distributor to set the images to.
 */
InputImageHandler::InputImageHandler(Distributor distributor) : distributor(distributor) { }

/**
 * Sets the image directories of the distributor.
 * Parameters:
 * -std::vector<std::string> directories: The image directories
 */
void InputImageHandler::sendDirectory(std::vector<std::string> directories)
{
    distributor.setInput(directories);
}   

std::vector<std::string> InputImageHandler::fetchDirectory() 
{
	ViewFacade view = ViewFacade::getInstance();
    std::string mode = page.getInputMode();
    if (mode.compare("Manual") == 0) 
    {
		return view.getDirectories(validformatsmanual);
    } 
    else if (mode.compare("Textfile") == 0) {
		return view.getDirectories(validformatstxt);
    }

}
