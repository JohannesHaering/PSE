#include <vector>
#include <string>

#include "MatrixDefine.hpp"
#include "MNISTDataParser.hpp"
#include "/home/pselabw1920/Documents/mnist/include/mnist/mnist_reader.hpp"

MNISTDataParser::MNISTDataParser(){
  MNISTDataParser(16);
}

MNISTDataParser::MNISTDataParser(int batchSize) : batchSize(batchSize)
{
  mnist_dataset = mnist::read_dataset<std::vector, std::vector, float, uint8_t>(MNIST_DATA_LOCATION);

  dataset_train_images = TENSOR(float) (mnist_dataset.training_images.size(), MATRIX_3D(float)(1, MATRIX_2D(float)(28, std::vector<float>(28))));
  dataset_test_images  = TENSOR(float) (mnist_dataset.test_images.size(),     MATRIX_3D(float)(1, MATRIX_2D(float)(28, std::vector<float>(28))));
  dataset_train_labels = TENSOR(float) (mnist_dataset.training_images.size(), MATRIX_3D(float)(1, MATRIX_2D(float)(1,  std::vector<float>(10))));
  dataset_test_labels  = TENSOR(float) (mnist_dataset.test_images.size(),     MATRIX_3D(float)(1, MATRIX_2D(float)(1,  std::vector<float>(10))));

  testImagePositions = std::vector<uint>(batchSize);
  trainImagePositions = std::vector<uint>(batchSize);
    
  for (int i = 0; i < mnist_dataset.training_images.size(); i++) {
      for (int j = 0; j < 28; j++)
        for (int k = 0; k < 28; k++) 
          dataset_train_images[i][0][j][k] = mnist_dataset.training_images[i][j*28 + k] / 255.0f;
      for (int j = 0; j < 10; j++) 
              dataset_train_labels[i][0][0][j] = (mnist_dataset.training_labels[i] == j) ? 1.0f : 0.0f;
  }

  for (int i =0; i < mnist_dataset.test_images.size(); i++) {
      for (int j = 0; j < 28; j++)
        for (int k = 0; k < 28; k++) 
          dataset_test_images[i][0][j][k] = mnist_dataset.training_images[i][j*28 + k] / 255.0f;
      for (int j = 0; j < 10; j++) 
              dataset_test_labels[i][0][0][j] = (mnist_dataset.test_labels[i] == j) ? 1.0f : 0.0f;
  }
  std::cout << "size dataset_test_labels: " << dataset_test_labels.size() << " " << dataset_test_labels[0].size() << std::endl;
}

TENSOR(float) MNISTDataParser::parseTraining()
{
  TENSOR(float) trainTensor = TENSOR(float)(batchSize);
    if ( batchSize  > 16)
    {
      std::cout<<"outdated rror with the batchsize"<<std::endl;
    }
  for (uint i = 0; i < batchSize; i++) {
    trainImagePositions[i] = rand() % mnist_dataset.training_images.size();
    trainTensor[i] = dataset_train_images[trainImagePositions[i]];
    if ( i > 16){
      break;
    }
  }
  return trainTensor;
}

TENSOR(float) MNISTDataParser::parseTest()
{
  TENSOR(float) testTensor = TENSOR(float)(batchSize);
  for (uint i = 0; i < batchSize; i++) {
    testImagePositions[i] = rand() % mnist_dataset.test_images.size();
    testTensor[i] = dataset_test_images[testImagePositions[i]];
  }
  return testTensor;

}

TENSOR(float) MNISTDataParser::parseTrainingLabel()
{
  TENSOR(float) trainLabelTensor = TENSOR(float)(batchSize);
  for (uint i = 0; i < batchSize; i++) {
    trainLabelTensor[i] = dataset_train_labels[trainImagePositions[i]];
  }
  return trainLabelTensor;

}

TENSOR(float) MNISTDataParser::parseTestLabel()
{
  TENSOR(float) testLabelTensor = TENSOR(float)(batchSize);
  for (uint i = 0; i < batchSize; i++) {
    testLabelTensor[i] = dataset_test_labels[testImagePositions[i]];
  }
  return testLabelTensor;
}

