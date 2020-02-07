#ifndef NEW_RESULT_HANDLER_H_
#define NEW_RESULT_HANDLER_H_

#include "InferencingDistributor.hpp"
#include "NeuralNetworkPager.hpp"
#include "ImagePager.hpp"
#include "SaveResultHandler.hpp"

class UpdateResultHandler : public SaveResultHandler {

    public: 
		UpdateResultHandler(InferencingDistributor* distributor, NeuralNetworkPager* nnpager, ImagePager* ipager);
		void onAction();
};
#endif