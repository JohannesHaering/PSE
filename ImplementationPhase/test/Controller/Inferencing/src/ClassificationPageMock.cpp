#ifndef CLASS_MOCK_H_
#define CLASS_MOCK_H_
#include "InferencePageAdapter.hpp"

class ClassificationPageMock : public InferencePageAdapter {

public:
	bool getShowResults()
	{
		return showResults;
	}
	bool getSaveResults()
	{
		return saveResults;
	}
	void setShowResults(bool enable)
	{
		showResults = enable;
	}
	void setSaveResults(bool enable)
	{
		saveResults = enable;
	}

private:
	bool showResults;
	bool saveResults;

};

#endif
