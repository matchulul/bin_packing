#include <iostream>
#include <string>
#include "../include/simulationRunner.h"
#include "../include/firstFitAlgorithm.h"

//TODO: Implement non-positional, proper -- arg parsing.
SIMDATA parse_args_basic(char *argv[]){
    SIMDATA data;
    data.n_sims = std::stoi(argv[1]);
    data.n_objs = std::stoi(argv[2]);
    if (std::stoi(argv[3]) == 0){
        data.dist = uniform;
    }
    else{
        data.dist = normal;
    }
    if (std::stoi(argv[4]) == 0){
        data.algo = first_fit;
    }
    else if (std::stoi(argv[4]) == 1){
        data.algo = smart_first_fit;
    }
    else if (std::stoi(argv[4]) == 2){
        data.algo = s_estimate;
    }
    else{ // Default
        data.algo = first_fit;
    }
    return data;
}


int main(int argc, char *argv[]) 
{
    SIMDATA data;
    if (argc == 1)
    {
        data = {1, 50, uniform, first_fit};
    }
    else{
        data = parse_args_basic(argv);
    }
    auto simRunner = simulationRunner();
    simRunner.runN(data);


    return 0; 
}