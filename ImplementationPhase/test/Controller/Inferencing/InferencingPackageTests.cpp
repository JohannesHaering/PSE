#include <gtest/gtest.h>

#include "src/InferencerTest.cpp"
#include "src/DistributorTest.cpp"
#include "src/TopologyInferencerTest.cpp"
#include "src/TrainingDistributorTest.cpp"
#include "src/InferencingDistributorClassificationTest.cpp"
#include "src/PagerTest.cpp"
#include "src/NeuralNetworkSetterTest.cpp"
#include <QApplication>

int main(int argc, char **argv)
{
    QApplication a(argc, argv);
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
