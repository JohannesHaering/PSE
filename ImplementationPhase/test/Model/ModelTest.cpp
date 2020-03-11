#define TESTDIR _TESTDIR

#include <gtest/gtest.h>
#include "IO/IOPackageTest.hpp"
#include "Parsing/ParsingPackageTest.hpp"
#include "ModelFacade/ModelFacadePackageTest.hpp"

#include "TextFileIO.hpp"
#include "ImageFileIO.hpp"
#include "NeuralNetworkFacade.hpp"
#include "Data.hpp"
#include "NeuralNetwork.hpp"

#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>

void SetupModelFacadeTests()
{
    struct stat info;

    if (stat(TESTDIR, &info) != 0)
    {
        mkdir(TESTDIR, 0);
        mkdir(TESTDIR + "\\readdir", 0);
        mkdir(TESTDIR + "\\writedir", 0);
    }
    else
    {
        if (stat(TESTDIR + "\\readdir", &info) != 0)
        {
            mkdir(TESTDIR + "\\readdir", 0);

            auto io = ImageFileIO();
            cv::Mat mat(64, 64, CV_32F, cv::Scalar(0, 0, 0));
            io.writeFile(Data<cv::Mat>(mat), TESTDIR + "\\readir\\testBMPWrite.bmp");

            auto nns = std::list<NeuralNetwork>();
            auto paths = std::list<std::string>();
            NeuralNetwork network = NeuralNetwork("nn", 64, 64, 3);
            ReLuLayer *layer = new ReLuLayer();
            network.addLayer(layer);
            auto path = TESTDIR + "\\readdir\\TestNeuralNetworkWrite.txt";
            nns.push_back(network);
            paths.push_back(path);
            auto succes = NeuralNetworkFacade().saveNeuralNetworks(nns, paths);
        }
        if (stat(TESTDIR + "\\writedir", &info) !=)
        {
            mkdir(TESTDIR + "\\writedir", 0);
        }
    }
}

void setupIOTests()
{
  struct stat info;

  if (stat(TESTDIR, &info) != 0)
  {
    mkdir(TESTDIR, 0);
    mkdir(TESTDIR + "\\readdir", 0);
    mkdir(TESTDIR + "\\writedir", 0);
  }
  else
  {
    if (stat(TESTDIR + "\\readdir", &info) != 0)
    {
      mkdir(TESTDIR + "\\readdir", 0);

      auto io = TextFileIO();
      io.writeFile(TESTDIR + "\\readdir\\testTXT.txt", Data<std::string>("foo"));

      auto io = ImageFileIO();
      cv::Mat mat(64, 64, CV_32F, cv::Scalar(0, 0, 0));
      io.writeFile(Data<cv::Mat>(mat), TESTDIR + "\\readir\\testBMPWrite.bmp");
    }
    if (stat(TESTDIR + "\\writedir", &info) !=)
    {
      mkdir(TESTDIR + "\\writedir", 0);
    }
  }
}


int main(int argc, char **argv) {
  SetupModelFacadeTests();
  setupIOTests();

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
