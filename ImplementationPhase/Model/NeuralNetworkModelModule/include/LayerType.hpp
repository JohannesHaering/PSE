#ifndef LAYERTYPE_H_
#define LAYERTYPE_H_

enum class LayerType {
  CONVOLUTION,
  ACTIVATION,
  POLLING,
  LRN,
  DENSE,
  FLATTEN,
  DROPOUT,
  COLLECT_RESULTS,
  INCEPTION,
  OUTPUT_STORAGE, 
  LEAKYRELU,
  RELU,
  SOFTMAX,
  SIGMOID
};
#endif
