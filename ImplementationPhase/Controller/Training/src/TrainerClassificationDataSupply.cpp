#include "TrainerClassificationDataSupply.hpp"
#include "ClassificationResult.hpp"
#include "ClassificationDatasetFacade.hpp"
#include "TrainerDataSupply.hpp"
#include "Result.hpp"
#include "MNISTDataParser.hpp"
#include "EvenNotEvenDatasetParser.hpp"
#include "ImageFacade.hpp"
#include "DataType.hpp"

#include <string>
#include <list>
#include <map>
#include <opencv2/opencv.hpp>

TrainerClassificationDataSupply::TrainerClassificationDataSupply(std::string directory, int width, int height, int channels, int batchSize)
{
	ImageFacade imageFacade = ImageFacade();
	std::list<std::string> files = imageFacade.readDirectory(directory);
	int i = 0;
	for (auto it = files.begin(); it != files.end(); ++it)
	{
		std::string filename = TrainerDataSupply::extractFileName(*it);
		std::string fileExtension = filename.substr(filename.find_last_of(".") + 1);
		if (fileExtension.compare("jpg") || fileExtension.compare("png") || fileExtension.compare("bmp"))
		{

		}
	}
}

TrainerClassificationDataSupply::TrainerClassificationDataSupply(DATATYPE type, int batchSize)
{
	if (type == DATATYPE::EVENNOTEVEN)
	{
		EvenNotEvenDatasetParser* parser = new EvenNotEvenDatasetParser();
	}
	if (type == DATATYPE::MNIST)
	{
		 mnistDataParser = new MNISTDataParser(batchSize);		
	}
}

TENSOR(float) TrainerClassificationDataSupply::getTrainingBatchInput(int numb) {
	return mnistDataParser->parseTraining();
}

TENSOR(float) TrainerClassificationDataSupply::getTrainingBatchOutput(int numb) {
	return mnistDataParser->parseTrainingLabel();
}

TENSOR(float) TrainerClassificationDataSupply::getTestBatchInput(int numb) {
	return mnistDataParser->parseTest();
}

TENSOR(float) TrainerClassificationDataSupply::getTestBatchOutput(int numb) {
	return mnistDataParser->parseTestLabel();
}
