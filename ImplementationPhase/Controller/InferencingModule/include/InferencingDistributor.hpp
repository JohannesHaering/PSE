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
        virtual void saveResult(int nn_id, int input_id, std::string path) = 0;
        virtual void drawResult(int nn_id, int input_id) = 0;
        bool canStart();
        virtual void enableStart() = 0;
        InferencePageAdapter* getPage() override;

    protected: 
		InferencePageAdapter* page;
    ResultManager resultManager;

};
#endif
