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
        virtual std::vector<std::string> fetchDirectory() = 0;
        virtual void sendDirectory(std::vector<std::string>) = 0;
        InferencePageAdapter *page;

};
#endif
