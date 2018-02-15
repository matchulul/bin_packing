
#ifndef BINPACKING_SIMRUNNER_H
#define BINPACKING_SIMRUNNER_H
#include "algorithm.h"
#include "firstFitAlgorithm.h"
#include <map>
#include <vector>

enum supported_algos { first_fit, smart_first_fit, s_estimate };

// pretty printing :3
const std::map<supported_algos, std::string> algo_map_name = {
    {first_fit, "First fit"},
    {smart_first_fit, "Smart_first_fit"},
    {s_estimate, "S_estimate"}
};

// A struct for passing in simulation settings
struct SIMDATA {
  int n_sims;
  int n_objs;
  distType dist;
  supported_algos algo;
};

/*
 * simulationRunner.h
 * Purpose: A class to run N experiments, average the results together and print
 * the output.
 */
class simulationRunner {
public:
  simulationRunner() = default;

  std::vector<float> num_bins;
  std::vector<float> run_times;

  int runOne(SIMDATA data);
  void runN(SIMDATA data);
  void report(float average_time);
};

#endif // BINPACKING_SIMRUNNER_H