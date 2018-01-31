#include <iostream>
#include "../include/simulationRunner.h"
#include "../include/firstFitAlgorithm.h"

int main() 
{
//todo: implement arg parsing for efficient scripting
    SIMDATA data = {50, 5000, uniform, first_fit};
    auto simRunner = simulationRunner();
    simRunner.runN(data);


    return 0; 
}