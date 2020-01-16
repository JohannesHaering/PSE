#ifndef NEURAL_NETWORK_PAGER_H_
#define NEURAL_NETWORK_PAGER_H_

#include "Pager.hpp"
#include "InferencePage.hpp"

class NeuralNetworkPager : public Pager {

    public:
        NeuralNetworkPager(int maxPage, InferencePage page);

    private: 
        void disable();   
        
};
#endif