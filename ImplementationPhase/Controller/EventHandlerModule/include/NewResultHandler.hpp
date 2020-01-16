#ifndef NEW_RESULT_HANDLER_H_
#define NEW_RESULT_HANDLER_H_

#include "InferencingDistributor.hpp"
#include "NeuralNetworkPager.hpp"
#include "ImagePager.hpp"
#include "SaveResultHandler.hpp"

class NewResultHandler : public SaveResultHandler {

    public: 
		NewResultHandler(InferencingDistributor distributor, NeuralNetworkPager nnpager, ImagePager ipager);
		NewResultHandler();
		void onAction();
};
#endif