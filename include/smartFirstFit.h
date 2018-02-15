#ifndef BINPACKING_SMART_FIRST_FIT_ALGORITHM_H
#define BINPACKING_SMART_FIRST_FIT_ALGORITHM_H

#include "firstFitAlgorithm.h"

/*
 * * smartFirstFit.h
 * Purpose: A smarter implementation of first fit using references to certain
 * bins. Subclasses from firstFitAlgorithm.
 */
class smartFirstFit : public firstFitAlgorithm {
public:
  smartFirstFit() : firstFitAlgorithm() {}
  smartFirstFit(int n_objects, distType dist)
      : firstFitAlgorithm(n_objects, dist) {}

  Bin first_empty_bin;
  Bin *less_half_empty_bin;

  int packBins();
  Bin *nextEmptyBin(bool new_alloc, int empty_position);
};
#endif // BINPACKING_SMART_FIRST_FIT_ALGORITHM_H