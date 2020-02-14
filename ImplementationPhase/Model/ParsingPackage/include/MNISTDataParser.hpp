#ifndef MNIST_DATA_PARSER_H_
#define MNIST_DATA_PARSER_H_

#include <opencv2/opencv.hpp>
#include <vector>
#include <cinttypes>

#include "mnist/include/mnist/mnist_reader.hpp"

class MNISTDataParser {
public:
	MNISTDataParser();
	std::vector<cv::Mat> parseTraining();
	std::vector<cv::Mat> parseTest();
	std::vector<std::vector<float>> parseTrainingLabel();
	std::vector<std::vector<float>> parseTestLabel();
private:
	mnist::MNIST_dataset<std::vector, std::vector, uint8_t, uint8_t> dataset;
	cv::Mat parse(std::vector<uint8_t> image);
	std::string MNIST_DATA_LOCATION = "/home/pselabw1920/Documents/mnist";
};
#endif