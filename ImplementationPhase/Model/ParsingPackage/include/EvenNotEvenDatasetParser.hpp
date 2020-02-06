#ifndef EVEN_NOT_EVEN_DATASET_PARSER_H_
#define EVEN_NOT_EVEN_DATASET_PARSER_H_

#include <opencv2/opencv.hpp>
#include <vector>

class EvenNotEvenDatasetParser
{
public:
    std::vector<cv::Mat> parseDataset(int numbBits);

    std::vector<std::vector<float>> parseDatasetLabel(int numbBits);
private:
    cv::Mat parseToMat(std::vector<int> bitst);
}