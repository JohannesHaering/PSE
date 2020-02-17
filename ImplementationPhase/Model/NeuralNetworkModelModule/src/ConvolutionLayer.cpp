#include "ConvolutionLayer.hpp"
#include "MatrixDefine.hpp"
#include <vector>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <random>

ConvolutionLayer::ConvolutionLayer(int filterSizeX, int filterSizeY, int filterSizeZ, int numFilters, int stride, int padding) : stride(stride), padding(padding), numFilters(numFilters),
                                                                                                                                 filterSizeZ(filterSizeZ), filterSizeY(filterSizeY), filterSizeX(filterSizeX)
{
  weightsTensor = TENSOR(float)(numFilters, MATRIX_3D(float)(filterSizeZ, MATRIX_2D(float)(filterSizeY, std::vector<float>(filterSizeX))));
  float r = sqrt(12.0 / (filterSizeX * filterSizeY * filterSizeZ * numFilters));
  //float r = sqrt(12.0 / (netSize + outputSize));
  //float r = 4 * sqrt(6.0 / (netSize + outputSize));
  std::random_device rand_dev;
  std::mt19937 generator(rand_dev());
  std::uniform_real_distribution<float> distr(-r, r);

  for (int filter = 0; filter < numFilters; filter++)
    for (int z = 0; z < filterSizeZ; z++)
      for (int y = 0; y < filterSizeY; y++)
        for (int x = 0; x < filterSizeX; x++)
          weightsTensor[filter][z][y][x] = distr(generator);

  float sum = 0;
  for (int filter = 0; filter < numFilters; filter++)
    for (int z = 0; z < filterSizeZ; z++)
      for (int y = 0; y < filterSizeY; y++)
        for (int x = 0; x < filterSizeX; x++)
          sum += weightsTensor[filter][z][y][x];
  std::cout << "init sum: " << sum << std::endl;

  //layerStrategy = DenseLayerCPP(&weights, &bias, &learningRate, &netSize, &outputSize);
}

ConvolutionLayer::ConvolutionLayer(TENSOR(float) filter, int stride, int padding) : stride(stride), padding(padding)
{
  weightsTensor = filter;
  numFilters = filter.size();
  filterSizeZ = filter[0].size();
  filterSizeY = filter[0][0].size();
  filterSizeX = filter[0][0][0].size();
}

float ConvolutionLayer::dotProduct(MATRIX_3D(float) net, MATRIX_3D(float) filter, int xStart, int yStart)
{
  float sum = 0;
  for (int z = 0; z < filter.size(); z++)
    for (int y = 0; y < filter[0].size(); y++)
      for (int x = 0; x < filter[0][0].size(); x++)
        sum += net[z][yStart + y][xStart + x] * filter[z][y][x];
  return sum;
}

MATRIX_2D(float)
ConvolutionLayer::Convolute(MATRIX_3D(float) net, MATRIX_3D(float) filter, int stride, int padding)
{
  int newSizeX = net[0][0].size() - (filter[0][0].size() - 1);
  int newSizeY = net[0].size() - (filter[0].size() - 1);
  MATRIX_2D(float)
  featureMap = MATRIX_2D(float)(newSizeY, std::vector<float>(newSizeX, 0.0f));

  for (int y = 0; y < featureMap.size(); y++)
    for (int x = 0; x < featureMap[0].size(); x++)
    {
      featureMap[y][x] = dotProduct(net, filter, x, y);
    }
  return featureMap;
}

TENSOR(float)
ConvolutionLayer::forward(TENSOR(float) net)
{
  this->net = net; //store it for backprop
  if (net[0].size() != filterSizeZ)
    std::cout << "ERROR, Z-DIMMENSION MISMATCH!" << std::endl;

  if (padding == 0 && stride == 1)
  { //first 2 Dimensions indipendent of stride and padding
    output_forward = TENSOR(float)(net.size(), MATRIX_3D(float)(numFilters));
  }
  else
  {
    std::cout << "not supporting stride != 1 or padding != 0" << std::endl;
    return output_forward;
  }
  for (int b = 0; b < net.size(); b++)
  {
    for (int filter = 0; filter < numFilters; filter++)
    {
      //do convolution for each filter in each batchIteration
      output_forward[b][filter] = Convolute(net[b], weightsTensor[filter], stride, padding);
    }
  }
  return output_forward;
}

// Backprop from here on

float ConvolutionLayer::calcWeightUpdate(TENSOR(float) feedback, int numFilters, int filterPosZ, int filterPosY, int filterPosX)
{
  float update = 0;
  //std::cout << "sizes: " << net.size() << " " << feedback[0].size() << " "  << feedback[0][0].size() << " " << feedback[0][0][0].size() << std::endl;
  for (int b = 0; b < net.size(); b++)
  {
    for (int ZPos = 0; ZPos < feedback[0].size(); ZPos++)
      for (int YPos = 0; YPos < feedback[0][0].size(); YPos++)
        for (int XPos = 0; XPos < feedback[0][0][0].size(); XPos++)
        {
          update += net[b][ZPos + filterPosZ][YPos + filterPosY][XPos + filterPosX] * feedback[b][ZPos][YPos][XPos];
        }
  }
  std::cout << "update in calcWeightUpdate: " << update << std::endl;
  return update;
}

MATRIX_3D(float)
ConvolutionLayer::backpropError(MATRIX_3D(float) feedback)
{
  MATRIX_3D(float)
  D3_Result = MATRIX_3D(float)(net[0].size(), MATRIX_2D(float)(net[0][0].size(), std::vector<float>(net[0][0][0].size(), 0.0f)));
  for (int filter = 0; filter < numFilters; filter++)
    for (int filterPosZ = 0; filterPosZ < filterSizeZ; filterPosZ++)
      for (int filterPosY = 0; filterPosY < filterSizeY; filterPosY++)
        for (int filterPosX = 0; filterPosX < filterSizeX; filterPosX++)
          for (int feedbackPosY = 0; feedbackPosY < feedback[0].size(); feedbackPosY++)
            for (int feedbackPosX = 0; feedbackPosX < feedback[0][0].size(); feedbackPosX++)
            {
              D3_Result[filterPosZ][filterPosY + feedbackPosY][filterPosX + feedbackPosX] +=
                  weightsTensor[filter][filterPosZ][filterPosY][filterPosX] * feedback[filter][feedbackPosY][feedbackPosX];
            }
  return D3_Result;
}

TENSOR(float)
ConvolutionLayer::backprob(TENSOR(float) feedback, float learningRate)
{
  output_backward = TENSOR(float)(net.size());

  //calc output_backward new2
  for (int b = 0; b < output_backward.size(); b++)
    output_backward[b] = backpropError(feedback[b]);

  //calc weight updates
  for (int filter = 0; filter < numFilters; filter++)
    for (int filterZ = 0; filterZ < filterSizeZ; filterZ++)
      for (int filterY = 0; filterY < filterSizeY; filterY++)
        for (int filterX = 0; filterX < filterSizeX; filterX++)
        {
          // only update every weight once :)
          weightsTensor[filter][filterZ][filterY][filterX] -= calcWeightUpdate(feedback, filter, filterZ, filterY, filterX) * learningRate;
        }

  return output_backward;
}

//ConvolutionLayer::ConvolutionLayer() : NetworkLayer(LayerType::CONVOLUTION), stride(0), padding(0) {}

void ConvolutionLayer::setWeightsTensor(TENSOR(float) newWeights)
{
  weightsTensor = newWeights;
}

TENSOR(float)
ConvolutionLayer::getWeightsTensor() { return weightsTensor; }

int ConvolutionLayer::getStride() { return stride; }

int ConvolutionLayer::getPadding() { return padding; }

int *ConvolutionLayer::getTensorDimensions()
{
  return new int[4]{(int)weightsTensor[0][0][0].size(), (int)weightsTensor[0][0].size(), (int)weightsTensor[0].size(), (int)weightsTensor.size()};
}

void ConvolutionLayer::setMode(DeviceType device, cl_int deviceID)
{
}