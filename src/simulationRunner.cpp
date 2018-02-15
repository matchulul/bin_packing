
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
    case s_estimate:
    {
        auto bin_obj_vec = binObjectFactory().generateN(data.n_objs, data.dist);
        float sum = 0;
        for(auto obj: bin_obj_vec) sum += obj.size();
        return round(ceil(sum));
    }

    default:
        return -1;
    }
}

void simulationRunner::runN(SIMDATA data){
    std::cout << "  " << data.n_sims << " " << algo_map_name.at(data.algo) << " " << data.n_objs << " ";
    int bins;
    float average_time = 0.0;
    for(int i = 0; i < data.n_sims; i++){
        auto start = Time::now();
        bins = runOne(data);
        average_time += get_delta(start, Time::now()).count();
        num_bins.push_back((float) bins);
    }
    report(average_time/data.n_sims);
}

void simulationRunner::report(float average_time){
    float average_bins = std::accumulate(num_bins.begin(), num_bins.end(), 0)/num_bins.size();
    
    std::cout << " " << average_bins << " " << average_time << std::endl;
}

