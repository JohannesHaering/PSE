#include <gtest/gtest.h>

#include "Model/ModelTest.hpp"
#include "Controller/ControllerTest.hpp"

#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>

#include <QApplication>

void SetupModelFacadeTests()
{
    struct stat info;

    if (stat("/home/pselabw1920/Documents/PSE/ImplementationPhase/build/testdata", &info) != 0)
    {
        mkdir("/home/pselabw1920/Documents/PSE/ImplementationPhase/build/testdata", 0);
        mkdir("/home/pselabw1920/Documents/PSE/ImplementationPhase/build/testdata/readdir", 0);
        mkdir("/home/pselabw1920/Documents/PSE/ImplementationPhase/build/testdata/writedir", 0);
    }
    else
    {
        if (stat("/home/pselabw1920/Documents/PSE/ImplementationPhase/build/testdata/readdir", &info) != 0)
        {
            mkdir("/home/pselabw1920/Documents/PSE/ImplementationPhase/build/testdata/readdir", 0);

            auto io = ImageFileIO();
            cv::Mat mat(64, 64, CV_32F, cv::Scalar(0, 0, 0));
            io.writeFile(Data<cv::Mat>(mat), "/home/pselabw1920/Documents/PSE/ImplementationPhase/build/testdata/readir/testBMPWrite.bmp");

            auto nns = std::list<NeuralNetwork>();
            auto paths = std::list<std::string>();
            NeuralNetwork network = NeuralNetwork("nn", 64, 64, 3);
            ReLuLayer *layer = new ReLuLayer();
            network.addLayer(layer);
            auto path = "/home/pselabw1920/Documents/PSE/ImplementationPhase/build/testdata/readdir/TestNeuralNetworkWrite.txt";
            nns.push_back(network);
            paths.push_back(path);
            auto succes = NeuralNetworkFacade().saveNeuralNetworks(nns, paths);
        }
        if (stat("/home/pselabw1920/Documents/PSE/ImplementationPhase/build/testdata/writedir", &info) != 0)
        {
            mkdir("/home/pselabw1920/Documents/PSE/ImplementationPhase/build/testdata/writedir", 0);
        }
    }
}

void setupIOTests()
{
  struct stat info;

  if (stat("/home/pselabw1920/Documents/PSE/ImplementationPhase/build/testdata", &info) != 0)
  {
    mkdir("/home/pselabw1920/Documents/PSE/ImplementationPhase/build/testdata", 0);
    mkdir("/home/pselabw1920/Documents/PSE/ImplementationPhase/build/testdata/readdir", 0);
    mkdir("/home/pselabw1920/Documents/PSE/ImplementationPhase/build/testdata/writedir", 0);
  }
  else
  {
    if (stat("/home/pselabw1920/Documents/PSE/ImplementationPhase/build/testdata/readdir", &info) != 0)
    {
      mkdir("/home/pselabw1920/Documents/PSE/ImplementationPhase/build/testdata/readdir", 0);

      auto io = TextFileIO();
      io.writeFile("/home/pselabw1920/Documents/PSE/ImplementationPhase/build/testdata/readdir/testTXT.txt", Data<std::string>("foo"));

      auto imageIo = ImageFileIO();
      cv::Mat mat(64, 64, CV_32F, cv::Scalar(0, 0, 0));
      imageIo.writeFile(Data<cv::Mat>(mat), "/home/pselabw1920/Documents/PSE/ImplementationPhase/build/testdata/readdir/testBMPWrite.bmp");
    }
    if (stat("/home/pselabw1920/Documents/PSE/ImplementationPhase/build/testdata/writedir", &info) != 0)
    {
      mkdir("/home/pselabw1920/Documents/PSE/ImplementationPhase/build/testdata/writedir", 0);
    }
  }
}


int main(int argc, char **argv) {
  SetupModelFacadeTests();
  setupIOTests();
  QApplication a(argc, argv);
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
