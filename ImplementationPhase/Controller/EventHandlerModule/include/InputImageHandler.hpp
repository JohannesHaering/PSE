#ifndef INPUT_IMAGE_HANDLER_H_
#define INPUT_IMAGE_HANDLER_H_

#include "Distributor.hpp"
#include "FileExplorerHandler.hpp"
#include "InferencePageAdapter.hpp"

class InputImageHandler : public FileExplorerHandler {

    public:
        InputImageHandler(Distributor *distributor);

    private:
        std::vector<std::string> validformatsmanual = {"jpg", "png"};
		std::vector<std::string> validformatstxt = {"txt"};
        Distributor *distributor;

    protected:
        void sendDirectory(std::vector<std::string> dir);
        std::vector<std::string> fetchDirectory();

};
#endif
