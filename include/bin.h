
#ifndef BINPACKING_BIN_H
#define BINPACKING_BIN_H

#include "binObject.h"
#include <vector>

/*
 * bin.h
 * purpose: Data class for bins
 */
class Bin {
public:
  Bin() = default;
  Bin(binObjectVector _bin_objects);
  Bin(float _bin_capacity) : bin_capacity(_bin_capacity){};

  float total_weight;
  float bin_capacity = 1;
  binObjectVector bin_objects;

  bool insertBinObject(binObject object);
  bool isEmpty() { return total_weight == 0; }
};

typedef std::vector<Bin> binVector;

#endif // BINPACKING_BIN_H