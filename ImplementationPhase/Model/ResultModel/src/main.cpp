#include <iostream>
#include <string>
#include "ResultManager.hpp"
#include "ClassificationResult.hpp"
#include "DetectionResult.hpp"
#include "ClassProbability.hpp"
//#include "Result.hpp"

using namespace std;

int main(int argc, char **argv) {
	list<ClassProbability> CPList;
	CPList.push_back(ClassProbability("HAUS", 0.4));
	CPList.push_back(ClassProbability("BERG", 0.3));
	ClassificationResult first("FOO1", "BAR", CPList);
	Result second("FOO2", "BAR");
	list<Result> resultList({first,second});
	ResultManager mgr(resultList);
	std::cout << first.GetImageID() << endl;
	cout << mgr.getSingleResult("FOO1", "BAR")->GetImageID();
	//cout << mgr.getSingleResult("FOO", "BAR")->GetImageID();
	list<Result> imgResList = mgr.getResultsByImage("FOO1");
	list<Result> NNResList = mgr.getResultsByNeuralNetwork("BAR");

	return 1;
};
