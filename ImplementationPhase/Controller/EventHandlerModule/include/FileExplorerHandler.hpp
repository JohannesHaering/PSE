#ifndef FILE_EXPLORER_HANDLER_H_
#define FILE_EXPLORER_HANDLER_H_

#include "ViewFacade.hpp"
#include "EventHandler.hpp"
#include <string>
#include <vector>

class FileExplorerHandler : public EventHandler {

    public: 
        void onAction();

    protected:  
        std::vector<std::string> fetchDirectory();
        virtual void sendDirectory(std::vector<std::string>);
		FileExplorerHandler();
        ViewFacade view;

};
#endif