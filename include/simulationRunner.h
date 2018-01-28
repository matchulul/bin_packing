
#ifndef BINPACKING_SIMRUNNER_H
#define BINPACKING_SIMRUNNER_H
#include <vector>
#include "binPackingAlgorithm.h"

class simulationRunner{
public:
    simulationRunner(binPackingAlgorithm algo);
    binPackingAlgorithm algorithm; // An instance of an algorithm which will be simulated on
    std::vector<float> num_bins;
    std::vector<float> run_times;
    int runOne();
    void runN(int n_sims);
    void report();
};






#endif //BINPACKING_SIMRUNNER_H