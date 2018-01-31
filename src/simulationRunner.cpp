
#include <iostream>
#include <chrono>
#include <ctime>
#include <numeric>
#include "../include/simulationRunner.h"


simulationRunner::simulationRunner(binPackingAlgorithm algo){
    algorithm = algo;
    num_bins.reserve(algorithm.count_objects()); //preallocate to save time
    run_times.reserve(algorithm.count_objects());

}

// Run one binpacking sim given the set up and return the number of bins req'd
int simulationRunner::runOne() {
    int bin = algorithm.packBins();
    return bin;
}

void simulationRunner::runN(int n_sims){
    std::cout << "Running " << n_sims << " bin packing experiments using: "
              << algorithm.name << " with " << algorithm.count_objects()
              << " bin objects" << std::endl;
    int bins;
    time_t start;
    time_t end;
    time_t job_start;
    time_t job_end;
    time(&job_start);
    for(int i = 0; i < n_sims; i++){
        time(&start);
        bins = runOne();
        time(&end);
        num_bins.push_back((float) bins);
        auto run_time = difftime(end, start);
        std::cout << run_time << std::endl;
        run_times.push_back((float) run_time);

    }
    time(&job_end);
    auto total_runtime = difftime(job_end, job_start);
    std::cout << "Simulation Complete! It took a total of " << total_runtime << " sec to complete "
              << n_sims << " simulations." << std::endl << "Data Report:" << std::endl;
    report();
}

void simulationRunner::report(){
    float average_bins = std::accumulate(num_bins.begin(), num_bins.end(), 0)/num_bins.size();
    float average_time = std::accumulate(run_times.begin(), run_times.end(), 0)/run_times.size();
    
    std::cout << "Average number of bins : " << average_bins << std::endl
              << "Average run time : " << average_time << std::endl;
}