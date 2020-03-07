#include <gtest/gtest.h>

#include "ClassificationDatasetFacade_test.hpp"
#include "DetectionDataFacade.hpp"
#include "ImageFacade_test.hpp"
#include "ModelFacade_test.hpp"
#include "NeuralNetworkFacade_test.hpp"

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}