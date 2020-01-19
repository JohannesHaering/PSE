#ifndef SAVE_RESULT_HANDLER_H_
#define SAVE_RESULT_HANDLER_H_

#include "InferencingDistributor.hpp"
#include "NeuralNetworkPager.hpp"
#include "ImagePager.hpp"
#include "EventHandler.hpp"
#include "InferencePageAdapter.hpp"

class SaveResultHandler : public EventHandler {

    public:
        SaveResultHandler(InferencingDistributor distributor, NeuralNetworkPager nnpager, ImagePager ipager, InferencePageAdapter page);
		SaveResultHandler();
        void onAction();

    protected: 
        InferencingDistributor distributor;
        NeuralNetworkPager nnpager;
        ImagePager ipager;
		InferencePageAdapter page;

};
#endif