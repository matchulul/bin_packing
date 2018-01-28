#include <iostream>
#include "../include/simulationRunner.h"
#include "../include/binPackingAlgorithm.h"

int main() 
{
//todo: implement arg parsing for efficient scripting
   auto algo = binPackingAlgorithm(50, normal);
   auto simRunner = simulationRunner(algo);
   simRunner.runN(50);


    return 0; 
}