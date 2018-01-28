
#ifndef BINPACKING_ALGORITHM_H
#define BINPACKING_ALGORITHM_H

#include <map>
#include "bin.h"
#include "binObjectFactory.h"

class binPackingAlgorithm {

private:
    int num_objects;
    distType obj_dist;
    std::vector<Bin> bins;
    binObjectVector bin_objects;
    binObjectFactory factory;
public:
    binPackingAlgorithm() = default;
    binPackingAlgorithm(int n_objects, distType dist);
    int bin_count() { return bins.size(); };
    virtual int packBins();
    void reset();
    std::string name = "Bin Packing";
    int count_objects() { return num_objects; };
};

#endif //BINPACKING_ALGORITHM_H