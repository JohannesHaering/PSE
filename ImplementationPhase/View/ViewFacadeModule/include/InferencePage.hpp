class InferencePage {
    public: 
        void nextNeuralNetworkButtonEnable(bool enable);
        void prevNeuralNetworkButtonEnable(bool prevenable);

        void nextImageEnable(bool enable);
        void prevImageEnable(bool prevenable);

        std::string getOperatingMode();
        std::vector<std::string> getDevices();
        std::string getInputMode();
        std::string getNeuralNetworkPath();
        bool getShowResults();
        bool getSaveResults();
        int getImageAmount();
        std::vector<std::string> getInputPathes();
        std::vector<std::string> getAppendResult();
        void setPowerPrediction(int amount);
        void setPerformancePrediction(int amount);
        void showPage(bool flag);
        void startButtonEnable(bool flag);
        void setResult(Result result);
        std::vector<std::string> getPlatforms();
        void update();
		void setActive(bool flag);
};