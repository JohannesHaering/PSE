#include "Parser.hpp"
#include "ImageParser.hpp"

#include <opencv2/opencv.hpp>
#include <string>
#include <list>

ImageParser::ImageParser() {

}

ImageParser::ImageParser(int width, int height, int channelNumb) : width(width), height(height), channelNumb(channelNumb) {}