#include "MaxPool2D.hpp"
#include <vector>

#include MaxPooling2D.h


MaxPooling2D::MaxPooling2D()
{


}


std::vector<int> maxPool(std::vector<std::vector<float>> input, std::vector<std::vector<float>> output, int filterSize, int y, int x)
{
	int max;
	int radius = (filterSize%2 == 0) ? filterSize/2 : (filterSize-1)/2;//just to point it out..
	std::vector<int> xVals = std::vector<int>(filterSize);
	std::vector<int> yVals = std::vector<int>(filterSize);
	if (filterSize % 2 == 1) {xVals[radius] = x; yVals[radius] = y;}
	for (int i = 0; i < radius; i++) {
		xVals[radius-i] = x-i;
		xVals[radius+i] = x+i;
		yVals[radius-i] = y-i;
		yVals[radius+i] = y+i;
	}
	for (int i = 0; i < filterSize; i++) {
		if (xVals[i] < 0 || xVals[i] >= output[0].size()) {xVals.remove[i]; max = 0;}//should only happen with zeroPadding
		if (yVals[i] < 0 || yVals[i] >= output.size()) {yVals.remove[i]; max = 0;}//should only happen with zeroPadding
	}
	for (int i = 0; i < xVals.size(); i++)
		for (int j = 0; j < yVals.size; j++) {
			if (input[xVals[i]][yVals[j]] > max) resVec.erase(resVec.begin(),resVec,end());
			if (input[xVals[i]][yVals[j]] >= max)
				resVec.push_back(i);
				resVec.push_back(j);
				max = input[xVals[i]][yVals[j]];
			}

		}
	resVec.push_back(max);
	return max;


std::vector<float> MaxPooling2D::fprop(std::vector<std::vector<float>> input, int filterSize, int stride, bool zeroPadding) 
{
	if (!zeroPadding) //check if it's possible or the user retarded
	{
		if (input.sizer() < filterSize || input.size[0].size() < filterSize || filterSize < 1) std::throw();
		if ((input.size()-filterSize) % stride != 0 || (input[0].size()-filterSize) % strid != 0) std::throw();
	}
	if !zeroPadding{
		newSizeX = 1 + (input[0].size() - filterSize) / stride;
		newsizeY = 1 + (input.size()    - filterSize) / stride;
	} else {
		newSizeX = input[0].size();
		newSizeY = input.size();
	}

	std::vector<std::vector<float>> output = std::vector<std::vector<float>>(newsizeY, std::vector<float>(newSizeX));

	if zeroPadding{
		for(int i = 0; i <  newsizeY; i+=stride)
			for(int j = 0; j < newSizeX; j+=stride)
				output[i][j] = 	maxPool(input, output&, filterSize, i, j, 1);
	} else {
		for(int i = 0; i <  newsizeY; i++)
			for(int j = 0; j < newSizeX; j++)
				output[i][j] = maxPool(input, output&, filterSize, i, j, 0);
	}


}
