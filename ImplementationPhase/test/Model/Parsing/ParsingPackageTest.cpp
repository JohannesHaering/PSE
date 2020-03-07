#include <gtest/gtest.h>

#include "SingleDetectionDatasetParser_test.hpp"
#include "Parser_test.hpp"
#include "NeuralNetworkParser_test.hpp"
#include "LineBreakParser_test.hpp"
#include "ImageLocationParser_test.hpp"
#include "ImageParserWithSizing_test.hpp"
#include "DetectionDataParser_test.hpp"
#include "DetectionDataParser_test.hpp"
#include "DetectionResultFactory_test.hpp"
#include "DetectionResultParser_test.hpp"
#include "ClassProbabilityParser_test.hpp"
#include "ClassificationResultFactory_test.hpp"
#include "BoundingBoxFactory_test.hpp"
#include "BoundingBoxParser_test.hpp"
#include "ClassificationResultParser_test.hpp"
#include "LayerParsing/ActivationLayerParser_test.hpp"
#include "LayerParsing/ConvolutionalLayerParser_test.hpp"
#include "LayerParsing/FlattenLayerParser_test.hpp"
#include "LayerParsing/DenseLayerParser_test.hpp"
#include "LayerParsing/MaxPoolLayerParser_test.hpp"
#include "Factory/ActivationLayerFactory_test.hpp"
#include "Factory/ConvolutionalLayerFactory_test.hpp"
#include "Factory/DenseLayerFactory_test.hpp"
#include "Factory/DenseLayerFactory_test.hpp"

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}