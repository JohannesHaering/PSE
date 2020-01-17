#include "CollectResultsLayer.hpp"

CollectResultsLayer::CollectResultsLayer() : NetworkLayer(LayerType::COLLECT_RESULTS) {}
CollectResultsLayer::CollectResultsLayer(std::string name, int* inputDimensions) : NetworkLayer(name, inputDimensions, LayerType::COLLECT_RESULTS) {}
