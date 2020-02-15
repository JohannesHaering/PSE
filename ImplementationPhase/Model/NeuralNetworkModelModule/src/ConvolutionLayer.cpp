#include "ConvolutionLayer.hpp"



ConvolutionLayer::ConvolutionLayer(int filterSizeX, int filterSizeY, int filterSizeZ, int numFilters, int stride, int padding) :
stride(stride), padding(padding), numFilters(numFilters),
filterSizeZ(filterSizeZ), filterSizeY(filterSizeY), filterSizeX(filterSizeX)
{
  layerType = LayerType::CONVOLUTION;
  weightsTensor = TENSOR(float)(numFilters, MATRIX_3D(float)(filterSizeZ, MATRIX_2D(float)(filterSizeY, std::vector<float>(filterSizeX))));
	float r = sqrt(12.0 / (inputSize + outputSize));
	//float r = 4 * sqrt(6.0 / (inputSize + outputSize));
	std::random_device rand_dev;
	std::mt19937 generator(rand_dev());
	std::uniform_real_distribution<float> distr(-r, r);

	for (int filter = 0; filter < numFilters; filter++) {
    for (int z = 0; z < filterSizeZ; z++)
      for (int y = 0; y < filterSizeY; y++)
        for (int x = 0; x < filterSizeX; x++)
			    weightsTensor[filter][z][y][x] = distr(generator);
	}
	float sum = 0;
	for (int filter = 0; filter < numFilters; filter++) {
    for (int z = 0; z < filterSizeZ; z++)
      for (int y = 0; y < filterSizeY; y++)
        for (int x = 0; x < filterSizeX; x++)
			    sum += weightsTensor[filter][z][y][x];
	std::cout << "init sum: " << sum << std::endl;

  //layerStrategy = DenseLayerCPP(&weights, &bias, &learningRate, &inputSize, &outputSize);
}


float dotProduct(MATRIX_3D input, MATRIX_3D filter, int xStart, int yStart)
{ 
  float sum = 0;
  for (int z = 0; z < filter.size(); z++)
    for (int y = 0; y < filter[0].size(); y++)
      for (int x = 0; x < filter[0][0].size(); x++)
        sum += input[z][yStart+y][xStart+x] * filter[z][yStart+y][xStart+x];
  return sum;
}


MATRIX_2D Convolute(MATRIX_3D input, MATRIX_3D filter, int stride, int padding)
{
  int newSizeX = input[0][0].size() - (filter[0][0].size() - 1);
  int newSizeY = input[0].size() - (filter[0].size() - 1);
  MATRIX_2D featureMap = MATRIX_2D(float)(newSizeY, std::vector<flot>(newSizeX, 0.0f));
  
  for (int y = 0; y < featureMap.size(); y++)
    for (int x = 0; x < featureMap[0].size(); x++)
      featureMap[y][x] = dotProduct(input, filter, x, y);
  return featureMap;
}

TENSOR(float) ConvolutionLayer::forward(TENSOR(float) input)
{
  if (input[0].size() != filterSizeZ) std::cout << "ERROR, Z-DIMMENSION MISMATCH!" << std::endl;
  if (padding == 0 && stride == 1) {//first 2 Dimensions indipendent of stride and padding
    output_forward = TENSOR(float)(input.size(), MATRIX_3D(float)(numFilters))//, MATRIX_2D(float)(newSizeY, std::vector<float>(newSizeX))));
  } else {
    std::cout << "not supporting stride != 1 or padding != 0" << std::endl;
    return output_forward;
  }
  for (int b = 0; b < input.size(); b++)
  {
    for (int filter = 0; filter < numFilters; filter++) 
    {
      //do convolution for each filter in each batchIteration
      output_forward[b][filter] = Convolute(input[b], weightsTensor[filter], stride, padding);
    }

  }
  return output_forward;

}




// Backprop from here on

float calcWeightUpdate(TENSOR(float) input, TENSOR(float) feedback, int float, int filterPosZ, int filterPosY, int filterPosX)
{
  float update = 0;
  for (int b = 0; b < input.size(); b++)
  {
    for (int ZPos = 0; ZPos < feedback[0].size(); ZPos++)
      for (int YPos = 0; YPos < feedback[0][0].size(); YPos++)
        for (int XPos = 0; XPos < feedback[0][0][0].size(); XPos++)
        {
          update += input[b][ZPos + filterPosZ][YPos + filterPosY][XPos + filterPosX] * feedback[b][ZPos][YPos][XPos];
        }
  }
  return update;


}


MATRIX_3D backpropError(int b)
{
  MATRIX_3D(float) 3D_result = MATRIX_3D(float)(input[0].size(), MATRIX_2D(float)(input[0][0].size(), std::vector<float>(input[0][0][0].size(), 0.0f)));
    for (int filter = 0; filter < numFilters; filter++)
      for (int filterPosZ = 0; filterPosZ < ; filterPosZ++)
        for (int filterPosY = 0; filterPosY < ; filterPosY++)
          for (int filterPoxX = 0; filterPoxX < ; filterPoxX++)
            for (int feedbackPosY = 0; feedbackPosY < ; feedbackPosY++)
              for (int feedbackPosX = 0; feedbackPosX < ; feedbackPosX++)
              {
                3D_result[filterPosZ][filterPosY + feedbackPosY][filterPosX + feedbackPosX] += 
                  weightsTensor[filter][filterPosZ][filterPosY][filterPosX] * feedback[b][filter][feedbackPosY][feedbackPosX];
              }
    return 3D_result;
}


TENSOR(float) ConvolutionLayer::backward(TENSOR(float) feedback, float learningRate)
{
  output_backward = TENSOR(float)(input.size());

  //calc output_backward new2
  for (int b = 0; b < output_backward.size(); b++)
      output_backward[b] = backpropError(b);
  
  //calc weight updates
    for (int filter = 0; filter < numFilters; filter++)
      for (int filterZ = 0; filterZ < filterSizeZ; filterZ++)
        for (int filterY = 0; filterY < filterSizeY; filterY++)
          for (int filterX = 0; filterX < filterSizeX; filterX++)
          {
            // only update every weight once :)
            weightsTensor[filter][filterZ][filterY][filterX] -= calcWeightUpdate(input, feedback, filter, filterZ, filterY, filterX) * learningRate;    
          }

  return output_backward;
}






ConvolutionLayer::ConvolutionLayer() : NetworkLayer(LayerType::CONVOLUTION), stride(0), padding(0) {}

void ConvolutionLayer::setWeightsTensor(TENSOR(float) weights) { weightsTensor = weights; }

TENSOR(float) ConvolutionLayer::getWeightsTensor() { return weightsTensor; }

int ConvolutionLayer::getStride() { return stride; }

int ConvolutionLayer::getPadding() { return padding; }

int* ConvolutionLayer::getTensorDimensions() {
 return new int[4] { (int) weightsTensor[0][0][0].size(), (int) weightsTensor[0][0].size(), (int) weightsTensor[0].size(), (int) weightsTensor.size()}; }
