#ifndef INPUT_IMAGE_HANDLER_H_
#define INPUT_IMAGE_HANDLER_H_

#include "Distributor.hpp"
#include "FileExplorerHandler.hpp"
#include "inferencepageadapter.h"

class InputImageHandler : public FileExplorerHandler {

    public:
        InputImageHandler(Distributor distributor);
		InputImageHandler();
        void onAction();

    private:
        std::vector<std::string> validformatsmanual = {"jpg", "png"};
		std::vector<std::string> validformatstxt = {"txt"};
        Distributor distributor;
		InferencePageAdapter page;

    protected:
        void sendDirectory(std::vector<std::string> dir);
        std::vector<std::string> fetchDirectory();

};
#endif
