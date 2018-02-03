#include <iostream>
#include <string>
#include "../include/simulationRunner.h"
#include "../include/firstFitAlgorithm.h"

    /*int n_sims;
    int n_objs;
    distType dist;
    supported_algos algo;*/

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
    else{
        data.algo = first_fit; // change this in case i improve on first fit
    }
    return data;
}


int main(int argc, char *argv[]) 
{
//todo: implement arg parsing for efficient scripting
    SIMDATA data = parse_args_basic(argv);
    auto simRunner = simulationRunner();
    simRunner.runN(data);


    return 0; 
}