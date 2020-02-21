#include <opencv2/opencv.hpp>
#include <vector>
#include <math.h>

#include "EvenNotEvenDatasetParser.hpp"

std::vector<cv::Mat> EvenNotEvenDatasetParser::parseDataset(int numbBits)
{
    auto dataset = std::vector<cv::Mat>();
    dataset.resize(pow(2, numbBits));
    for (int i = 0; i < pow(2, numbBits); i++)
    {
        std::vector<int> inputVector = std::vector<int>();
        inputVector.resize(numbBits);
        for (int j = 0; j < numbBits; j++)
        {
            if (i - pow(2, j) < 0)
            {
                inputVector[j] = 0;
            }
            else
            {
                inputVector[j] = 1;
            }
        }
        dataset[i] = parseToMat(inputVector);
    }
    return dataset;
}

std::vector<std::vector<float>> EvenNotEvenDatasetParser::parseDatasetLabel(int numbBits)
{
    std::vector<std::vector<float>> labels = std::vector<std::vector<float>>();
    labels.resize(pow(2, numbBits));
    for (int i = 0; i < pow(2, numbBits); i++)
    {
        std::vector<float> vec = std::vector<float>();
        vec.resize(2);
        vec[0] = 0;
        vec[1] = 0;

        vec[i % 2] = 1;
        labels[i] = vec;
    }
    return labels;
}

cv::Mat EvenNotEvenDatasetParser::parseToMat(std::vector<int> bits)
{
    cv::Mat mat(1, bits.size(), CV_8UC1, bits.data());
    return mat;
}