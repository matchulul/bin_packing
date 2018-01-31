
#include <iostream>
#include <chrono>
#include <ctime>
#include <numeric>
#include "../include/simulationRunner.h"
#include "../include/algorithm.h"
#include "../include/firstFitAlgorithm.h"


int simulationRunner::runOne(SIMDATA data){
    switch(data.algo){
    case first_fit:
        return firstFitAlgorithm(data.n_objs, data.dist).packBins();
    default:
        return -1;
    }
}

void simulationRunner::runN(SIMDATA data){
    std::cout << "Running " << data.n_sims << " bin packing experiments using: "
              << algo_map_name.at(data.algo) << " with " << data.n_objs
              << " bin objects" << std::endl;
    int bins;
    time_t start;
    time_t end;
    time_t job_start;
    time_t job_end;
    time(&job_start);
    for(int i = 0; i < data.n_sims; i++){
        time(&start);
        bins = runOne(data);
        time(&end);
        num_bins.push_back((float) bins);
        auto run_time = difftime(end, start);
        run_times.push_back((float) run_time);

    }
    time(&job_end);
    auto total_runtime = difftime(job_end, job_start);
    std::cout << "Simulation Complete! It took a total of " << total_runtime << " sec to complete "
              << data.n_sims << " simulations." << std::endl << "Data Report:" << std::endl;
    report();
}

void simulationRunner::report(){
    float average_bins = std::accumulate(num_bins.begin(), num_bins.end(), 0)/num_bins.size();
    float average_time = std::accumulate(run_times.begin(), run_times.end(), 0)/run_times.size();
    
    std::cout << "Average number of bins : " << average_bins << std::endl
              << "Average run time : " << average_time << std::endl;
}