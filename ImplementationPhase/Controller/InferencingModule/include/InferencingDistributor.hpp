#ifndef INFERENCING_DISTRIBUTOR_H_
#define INFERENCING_DISTRIBUTOR_H_

#include "Distributor.hpp"
#include "ViewFacade.hpp"
#include "DispatchManager.hpp"
#include "ResultManager.hpp"
#include "NeuralNetworkAdapter.hpp"
#include <vector>
#include "InferencePageAdapter.hpp"

class InferencingDistributor : public Distributor {

	public:
        virtual void startProcess() = 0;
        virtual void saveResult(std::string nn_id, std::string input_id, std::string path) = 0;
        virtual void drawResult(std::string nn_id, std::string input_id) = 0;
        bool canStart();
        virtual void enableStart() = 0;

    protected: 
		InferencePageAdapter* page;
        ResultManager resultManager;

};
#endif
