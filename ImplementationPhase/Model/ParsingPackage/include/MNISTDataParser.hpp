#ifndef MNIST_DATA_PARSER_H_
#define MNIST_DATA_PARSER_H_

#include <vector>
#include "MatrixDefine.hpp"

#include "/home/pselabw1920/Documents/mnist/include/mnist/mnist_reader.hpp"

class MNISTDataParser {
public:
	MNISTDataParser(int batchSize);
	TENSOR(float) parseTraining();
	TENSOR(float) parseTest();
	TENSOR(float) parseTrainingLabel();
	TENSOR(float) parseTestLabel();
private:
	int batchSize;
	std::vector<uint> trainImagePositions;
	std::vector<uint> testImagePositions;
	mnist::MNIST_dataset<std::vector, std::vector<float>, uint8_t> mnist_dataset;
	std::string MNIST_DATA_LOCATION = "/home/pselabw1920/Documents/mnist";
	TENSOR(float) dataset_train_images;
	TENSOR(float) dataset_test_images;
	TENSOR(float) dataset_train_labels;
	TENSOR(float) dataset_test_labels;
};
#endif
