
#include <iostream>
#include <chrono>
#include <ctime>
#include <numeric>
#include "../include/simulationRunner.h"
#include "../include/algorithm.h"
#include "../include/firstFitAlgorithm.h"
#include "../include/smartFirstFit.h"


typedef std::chrono::high_resolution_clock Time;


namespace { 
    typedef std::chrono::high_resolution_clock::time_point point;
    typedef std::chrono::milliseconds ms;
    typedef std::chrono::duration<float> fsec;
    ms get_delta(point pA, point pB){
        return std::chrono::duration_cast<ms>(pB - pA);
    }
}
int simulationRunner::runOne(SIMDATA data){
    switch(data.algo){
    case first_fit:
        return firstFitAlgorithm(data.n_objs, data.dist).packBins();
    case smart_first_fit:
        return smartFirstFit(data.n_objs, data.dist).packBins();
    default:
        return -1;
    }
}

void simulationRunner::runN(SIMDATA data){
    std::cout << "Running ^" << data.n_sims << " bin packing experiments using: "
              << algo_map_name.at(data.algo) << " with *" << data.n_objs
              << " bin objects " << std::endl;
    int bins;
    float average_time = 0.0;
    for(int i = 0; i < data.n_sims; i++){
        auto start = Time::now();
        bins = runOne(data);
        average_time += get_delta(start, Time::now()).count();
        num_bins.push_back((float) bins);
    }

    std::cout << "Simulation Complete! It took a total of " << average_time << " ms to complete "
              << data.n_sims << " simulations." << std::endl << "Data Report:" << std::endl;
    report(average_time/data.n_sims);
}

void simulationRunner::report(float average_time){
    float average_bins = std::accumulate(num_bins.begin(), num_bins.end(), 0)/num_bins.size();
    
    std::cout << "Average number of bins #" << average_bins 
              << " Average run time in ms @" << average_time<< std::endl;
}

