#include "Distributor.hpp"
#include "FileExplorerHandler.hpp"
#include "viewfacade.h"
#include "inferencepageadapter.h"
#include "InputImageHandler.hpp"
#include <stdexcept>

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
	try {
		ViewFacade view = ViewFacade::getInstance();
		int mode = page.getInputMode();
		// normaler mode
		if (mode == 0)
		{
			return page.getDirectories(validformatsmanual);
		}
		// text file
		else if (mode == 1) {
			return view.getDirectories(validformatstxt);
		}
	}
	catch (const std::invalid_argument& ia)
	{
		view.exceptionText("Invalid image");
	}

}
