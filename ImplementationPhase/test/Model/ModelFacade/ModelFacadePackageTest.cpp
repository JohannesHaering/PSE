#define TESTDIR _TESTDIR

#include <gtest/gtest.h>

#include "ClassificationDatasetFacade_test.hpp"
#include "DetectionDataFacade.hpp"
#include "ImageFacade_test.hpp"
#include "ModelFacade_test.hpp"
#include "NeuralNetworkFacade_test.hpp"
#include "NeuralNetworkFacade.hpp"
#include "NeuralNetwork.hpp"

#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>

int main(int argc, char **argv)
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
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}