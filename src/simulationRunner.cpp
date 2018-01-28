
#include <iostream>
#include <chrono>
#include <numeric>
#include "../include/simulationRunner.h"


simulationRunner::simulationRunner(binPackingAlgorithm algo){
    algorithm = algo;
    num_bins.reserve(algorithm.count_objects()); //preallocate to save time
    run_times.reserve(algorithm.count_objects());

}

// Run one binpacking sim given the set up and return the number of bins req'd
int simulationRunner::runOne() {
    return algorithm.packBins();
}

void simulationRunner::runN(int n_sims){
    std::cout << "Running " << n_sims << " bin packing experiments using: "
              << algorithm.name << std::endl << "With " << algorithm.count_objects()
              << " bin objects";
    int bins;
    auto runner_start = std::chrono::system_clock::now();
    for(int i = 0; i < n_sims; i++){
        auto start = std::chrono::system_clock::now();
        bins = runOne();
        auto end = std::chrono::system_clock::now();
        num_bins.push_back((float) bins);
        auto run_time = std::chrono::duration_cast<std::chrono::seconds>(end-start).count();
        run_times.push_back(run_time);

    }
    auto runner_end = std::chrono::system_clock::now();
    auto total_runtime = std::chrono::duration_cast<std::chrono::seconds>(runner_end-runner_start).count();
    std::cout << "Simulation Complete! It took a total of " << total_runtime << " to complete "
              << n_sims << " simulations. Data Report:" << std::endl;
    report();
}

void simulationRunner::report(){
    float average_bins = std::accumulate(num_bins.begin(), num_bins.end(), 0)/num_bins.size();
    float average_time = std::accumulate(run_times.begin(), run_times.end(), 0)/run_times.size();
    
    std::cout << "Average number of bins : " << average_bins << std::endl
              << "Average run time : " << average_time << std::endl;
}