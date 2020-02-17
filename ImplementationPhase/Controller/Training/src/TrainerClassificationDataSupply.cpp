#include "TrainerClassificationDataSupply.hpp"
#include "ClassificationResult.hpp"
#include "ClassificationDatasetFacade.hpp"
#include "TrainerDataSupply.hpp"
#include "Result.hpp"
#include "MNISTDataParser.hpp"
#include "EvenNotEvenDatasetParser.hpp"
#include "ImageFacade.hpp"

#include <string>
#include <list>
#include <map>
#include <opencv2/opencv.hpp>

TrainerClassificationDataSupply::TrainerClassificationDataSupply(std::string directory, int width, int height, int channels) : TrainerDataSupply(directory, width, height, channels)
{
	ClassificationDatasetFacade facade = ClassificationDatasetFacade();
	dataSet = facade.loadDataset(directory);
	for (auto it = dataSet.begin(); it != dataSet.end(); ++it)
	{
		dataMap[(*it).getImageID()] = &*it;
	}
	auto probabilities = (*(dataSet.begin())).getProbabilities();
	for (auto it = probabilities.begin(); it != probabilities.end(); ++it)
	{
		classnames.push_back((*it).getClassName());
	}
}

TrainerClassificationDataSupply::TrainerClassificationDataSupply(DATATYPE type)
{
	if (type == DATATYPE::EVENNOTEVEN)
	{
		EvenNotEvenDatasetParser* parser = new EvenNotEvenDatasetParser();

		std::vector<cv::Mat> images = parser->parseDataset();
		std::vector<std::vector<float>> labels = parser->parseDatasetLabel();

		int i = 0;
		std::vector<std::vector<float>>::iterator labelIt = labels.begin();
		for (std::vector<cv::Mat>::iterator it _ = images.begin(); it != images.end(); ++it)
		{
			this->images.insert(std::pair<std::string, cv::Mat>(std::to_string(i), *it));
			classnames.push_back(std::to_string(i));

			ClassificationResult result = createResult(i, *labelIt);
			dataMap.insert(std::pair<std::string, ClassificationResult*>(std::to_string(i), *result));

			++i;
			++labelIt;
		}

		splitData();
	}
	if (type == DATATYPE::MNIST)
	{
		MNISTDataParser* parser = new MNISTDataParser();

		std::vector<cv::Mat> testImages = parser->parseTest();
		std::vector<std::vector<float>> testLabels = parser->parseTestLabel();
		std::vector<cv::Mat> trainingImages = parser->parseTraining();
		std::vector<std::vector<float>> trainingLabels = parser->parseTrainingLabel();

		int i = 0;
		std::vector<std::vector<float>>::iterator labelIt = trainingLabels.begin();
		for (std::vector<cv::Mat>::iterator it = trainingImages.begin(); it != trainingImages.end(); ++it)
		{
			images.insert(std::pair<std::string, cv::Mat>(std::to_string(i), *it));
			classnames.push_back(std::to_string(i));

			ClassificationResult result = createResult(i, *labelIt);
			dataSet.push_back(result);
			dataSetTraining.push_back(*result);
			dataMap.insert(std::pair<std::string, ClassificationResult*>(std::to_string(i), *result));

			++i;
			++labelIt;
		}

		labelIt = testLabels.begin();
		for (std::vector<cv::Mat>::iterator it = testImages.begin(); it != testImages.end(); ++it)
		{
			images.insert(std::pair<std::string, cv::Mat>(std::to_string(i), *it));
			classnames.push_back(std::to_string(i));

			ClassificationResult result = createResult(i, *labelIt);
			dataSet.push_back(result);
			dataSetTraining.push_back(*result);
			dataMap.insert(std::pair<std::string, ClassificationResult*>(std::to_string(i), *result));

			++i;
			++labelIt;
		}
	}
}

ClassificationResult TrainerClassificationDataSupply::createResult(int i, std::vector<float> label)
{
	std::list<ClassProbability> probabilities = std::list<ClassProbability>();
	int j = 0;
	for (std::vector<float>::iterator it = label.begin(); it != label.end(); ++i)
	{
		probabilities.push_back(ClassProbability(std::to_string(j), *it));
		j++;
	}
	return ClassificationResult(std::to_string(i), "", probabilities);
}

std::vector<float> TrainerClassificationDataSupply::getOutputVector(std::string id)
{
	ClassificationResult current = *dataMap[id];
	return createOutputVector(current);
}

std::vector<float> TrainerClassificationDataSupply::createOutputVector(ClassificationResult result)
{
	std::vector<float> output;
	auto probabilities = result.getProbabilities();
	// The output vector must have its output always on the same position for the same class
	// The results aren't nessescarry sorted in the same manner
	for (auto it = probabilities.begin(); it != probabilities.end(); ++it)
	{
		for (auto idIt = classnames.begin(); idIt != classnames.end(); ++it)
		{
			if ((*it).getClassName == *idIt)
			{
				output.push_back((*it).getProbability());
			}
		}
	}
	return output;
}

void TrainerClassificationDataSupply::splitData()
{
	auto it = dataSet.begin();
	for (int i = 0; i < dataSet.size(); ++i, ++it)
	{
		if (i < dataSet.size() * TRAINING_PART)
		{
			dataSetTraining.push_back(&*it);
		}
		else
		{
			dataSetTest.push_back(&*it);
		}
	}
}

int TrainerClassificationDataSupply::getAmountClasses()
{
	return classnames.size();
}

TENSOR(float) TrainerClassificationDataSupply::getTrainingBatchInput(int batchSize, int numb, int width, int height) {
	TENSOR(float) tensor;
	std::vector<cv::Mat> batch = std::vector<cv::Mat>();

	for (int i = 0; i < batchSize; i++) {
		batch.push_back(TrainerDataSupply::images[TrainerDataSupply::ids[i + numb * batchSize]]);
	}

	tensor = ImageFacade().createImageTensor(batch, width, height);
	return tensor;
}

TENSOR(float) TrainerClassificationDataSupply::getTrainingBatchOutput(int batchSize, int numb) {
	TENSOR(float) tensor = TENSOR(float);
	std::vector<ClassificationResult> batch = std::vector<ClassificationResult>();

	for (int i = 0; i < batchSize; i++) {
		std::vector<std::vector<std::vector<float>>> v = std::vector<std::vector<std::vector<float>>>();
		std::vector<std::vector<float>> v1 = std::vector<std::vector<float>>();
		v1.push_back(dataSet[i + numb + batchSize].getProbabilities());
		v.push_back(v1);
		tensor.pushBack(v);
	}	

	return tensor;
}
