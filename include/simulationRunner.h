
#ifndef BINPACKING_SIMRUNNER_H
#define BINPACKING_SIMRUNNER_H
#include <vector>
#include <map>
#include "algorithm.h"
#include "firstFitAlgorithm.h"

enum supported_algos{
    first_fit,
    smart_first_fit
};

const std::map<supported_algos, std::string> algo_map_name = {{first_fit, "First fit"}, {smart_first_fit, "Smart_first_fit"}};

struct SIMDATA{
    int n_sims;
    int n_objs;
    distType dist;
    supported_algos algo;
};

class simulationRunner{
public:
    simulationRunner() = default;
    std::vector<float> num_bins;
    std::vector<float> run_times;
    int runOne(SIMDATA data);
    void runN(SIMDATA data);
    void report(float average_time);
};






#endif //BINPACKING_SIMRUNNER_H