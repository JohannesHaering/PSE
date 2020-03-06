#include "EventHandler.hpp"
#include "Inferencer.hpp"
#include "StartHandler.hpp"

/**
 * Creates a StartHandler.
 * Parameters:
 * -Inferencer inferencer: The inferencer to start the process of.
 */
StartHandler::StartHandler(Inferencer *inferencer) : inferencer(inferencer) { }

/**
 * Starts the process of the referenced inferencer.
 */
void StartHandler::onAction()
{
    try {
    inferencer->startProcess();
	  }
    catch (const std::invalid_argument& ia)
	  {
        inferencer->getPage()->showError(ia.what());
    }
}
