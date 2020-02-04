#include <opencv2/opencv.hpp>
#include <vector>

#include "MNISTDataParser.hpp"
#include "mnist/include/mnist/mnist_reader.hpp"

MNISTDataParser::MNISTDataParser()
{
    dataset = mnist::read_dataset<std::vector, std::vector, uint8_t, uint8_t>(MNIST_DATA_LOCATION);
}

std::vector<cv::Mat> MNISTDataParser::parseTraining()
{
    std::vector<cv::Mat> parsedDataset = std::vector<cv::Mat>();
	parsedDataset.resize(mnist_dataset.training_images.size());

	for (int i = 0; i < mnist_dataset.training_images.size(); i++)
    {
		parsedDataset[i] = parse(mnist_dataset.training_images[i]);
    }
    return parsedDataset;
}

std::vector<cv::Mat> MNISTDataParser::parseTest()
{
    std::vector<cv::Mat> parsedDataset = std::vector<cv::Mat>();
    parsedDataset.resize(mnist_dataset.test_images.size());
	
	for (int i = 0; i < mnist_dataset.test_images.size(); i++)
    {
		parsedDataset[i] = parse(mnist_dataset.test_images[i]);
    }
    return parsedDataset;
}

std::vector<std::vector<float>> MNISTDataParser::parseTrainingLabel()
{
    std::vector<uint8_t> dataset_train_labels;
    auto dataset_train_labels = mnist_dataset.training_labels;
    std::vector<std::vector<float>> outputVectors = std::vector<std::vector<float>>();
    for (int i = 0; dataset_train_labels.size(); i++)
    {
        std::vector<float> label = std::vector<float>();
        for (int j = 0; j < 10; j++)
        {
            if (dataset_train_labels[i] == j)
            {
                label.push_back(1);
            }
            else
            {
                label.push_back(0);
            }
        }
        outputVectors.push_back(label);
    }
    return outputVectors;
}

std::vector<std::vector<float>> MNISTDataParser::parseTestLabel()
{
    std::vector<uint8_t> dataset_test_labels;
    auto dataset_test_labels = mnist_dataset.test_labels;
    std::vector<std::vector<float>> outputVectors = std::vector<std::vector<float>>();
    for (int i = 0; dataset_test_labels.size(); i++)
    {
        std::vector<float> label = std::vector<float>();
        for (int j = 0; j < 10; j++)
        {
            if (dataset_test_labels[i] == j)
            {
                label.push_back(1.0f);
            }
            else
            {
                label.push_back(0.0f);
            }
        }
        outputVectors.push_back(label);
    }
    return outputVectors;
}

cv::Mat MNISTDataParser::parse(std::vector<uint8_t> image)
{
    cv::Mat mat(28,28, CV_8UC1, image.data());
    return mat;
}