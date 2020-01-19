#include <string>
#include <vector>
#include "NeuralNetworkAdapter.hpp"
#include "TopologyPage.hpp"
#include "TrainingPage.hpp"
#include "InferencePageAdapter.hpp"
#include "Result.hpp"

class ViewFacade {
    public: 
        
        static ViewFacade getInstance(){}

        std::vector<std::string> getDirectories(std::vector<std::string> filetypes){}

		static InferencePageAdapter getClassificationPage() {
			return InferencePageAdapter
			();
		}
		std::string getOperatingModeClassification() { return ""; }
        std::string getDevicesClassification(){ return ""; }
        std::string getInputModeClassification(){ return ""; }
        std::string getNeuralNetworkPathClassification(){ return ""; }
		bool getShowResultsClassification() { return true; }
        bool getSaveResultsClassification(){ return true; }
		int getImageAmountClassification() { return 0; }
		std::vector<std::string> getInputPathesClassification() {
			return { "" };
		}
        std::vector<std::string> getAppendResultClassification(){ return { "" }; }
		void setPowerPredictionClassification(int amount) { }
        void setPerformancePredictionClassification(int amount){}
        void showPageClassification(bool flag){}
        void startButtonEnableClassification(bool flag){}
        void nextNeuralNetworkButtonEnableClass(bool flag){}
        void prevNeuralNetworkButtonEnableClass(bool flag){}
        void nextImageButtonEnableClass(bool flag){}
        void prevImageButtonEnableClass(bool flag){}
        void setResultClassification(Result result){}
        std::vector<std::string> getPlatformsClassification(){ return { "" }; }

		std::string getOperatingModeDetection() { return ""; }
        std::string getDevicesDetection(){ return ""; }
        std::string getInputModeDetection(){ return ""; }
        std::string getNeuralNetworkPathDetection(){ return ""; }
		bool getShowResultsDetection() { return true; }
		bool getSaveResultsDetection() { return true; }
		int getImageAmountDetection() { return 0; }
        std::vector<std::string> getInputPathesDetection(){ return { "" }; }
        std::vector<std::string> getAppendResultDetection(){ return { "" }; }
        void setPowerPredictionDetection(int amount){}
        void setPerformancePredictionDetection(int amount){}
        void showPageDetection(bool flag){}
        void startButtonEnableDetection(bool flag){}
        void nextNeuralNetworkButtonEnableDetection(bool flag){}
        void prevNeuralNetworkButtonEnableDetection(bool flag){}
        void nextImageButtonEnableDetection(bool flag){}
        void prevImageButtonEnableDetection(bool flag){}
        void setResultDetection(Result result){}

		static TrainingPage getTrainingPage() { return TrainingPage(); }
        void newTrainingFinished(std::vector<float> pointsArrayTest, std::vector<float> pointsArrayTraining){}
		float getLearningRate() { return 0.f; }
		float getPrecision() { return 0.f; }
		std::string getName() { return ""; }
		std::string getLearningMode() { return ""; }
        void startButtonEnableTraining(bool flag){}

		static TopologyPage getTopologyPage() { return TopologyPage(); }
        void topologyChanged(NeuralNetworkAdapter neuralNetworkAdapter){}
        void startButtonEnableTopology(bool flag){}

        void update(){}


};