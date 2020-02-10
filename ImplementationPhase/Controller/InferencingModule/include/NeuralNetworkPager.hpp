#ifndef NEURAL_NETWORK_PAGER_H_
#define NEURAL_NETWORK_PAGER_H_

#include "Pager.hpp"
#include "InferencePageAdapter.hpp"

class NeuralNetworkPager : public Pager {

    public:
        NeuralNetworkPager(int maxPage, InferencePageAdapter *page);

    private: 
        void disable();   
        
};
#endif