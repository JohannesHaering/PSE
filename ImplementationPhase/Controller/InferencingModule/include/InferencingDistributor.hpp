#ifndef INFERENCING_DISTRIBUTOR_H_
#define INFERENCING_DISTRIBUTOR_H_

#include "Distributor.hpp"
#include "viewfacade.h"
#include "DispatchManager.hpp"
#include "ResultManager.hpp"
#include "NeuralNetworkAdapter.hpp"
#include <vector>
#include "inferencepageadapter.h"

class InferencingDistributor : public Distributor {

	public:
		InferencingDistributor();
        void startProcess();
        void saveResult(std::string nn_id, std::string input_id, std::string path);
        void drawResult(std::string nn_id, std::string input_id);
        bool canStart();
        virtual void enableStart();

    protected: 
		InferencePageAdapter page;
        ResultManager resultManager;
        virtual void drawResult(Result result);

};
#endif
