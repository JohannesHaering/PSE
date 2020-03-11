#include <gtest/gtest.h>

#include "InferencerTest.cpp"
#include "DistributorTest.cpp"
#include "TopologyInferencerTest.cpp"
#include "TrainingDistributorTest.cpp"
#include "InferencingDistributorClassificationTest.cpp"
#include "PagerTest.cpp"
#include "NeuralNetworkSetterTest.cpp"

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}