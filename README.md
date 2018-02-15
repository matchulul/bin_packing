# Comp 372 - Bin packing
### Summary
This project is a solution implementation to the bin packing problem as stated in [Introduction to Algorithms: Problem 35-1](https://www.amazon.ca/Introduction-Algorithms-Thomas-H-Cormen/dp/0262033844) using the first fit heuristic.


*Suppose that we are given a set of _n_ objects,  where the size _s~i~_ of the ith object satisfies 0< s~i~ < 1.We wish to pack all the objects into the minimum number of unit-size bins. Each bin can hold any subset of the objects whose total size does not exceed 1.*

The **first-fit** heuristic takes each object in trun and places it into the first bin that can accomodate it.


##### Requirements:
* g++ supporting c++17. Developed with gcc 7.3.0
* GNU Make. Developed with 4.2.1

If you'd like to use the data analysis scripts, you'll require:
* Python 3.6
* Python packages: Numpy, pandas and matplotlib
  * Using conda is recommended. 

### Implementation
The project contains two solution algorithms, *First fit* and *"Smart first fit"*
##### First fit
* A naive implementation, which linearly scans the list of available bins and places the object in the first bin that can accomodate. 
* Runs in ~O(n^2^) time.

##### Smart first fit
* An implementation which utilizes a useful property of the first fit heuristic, we only even need a bin that is less than half full and empty. When we are looking for a bin to insert in to, simply put it in an empty bin if it's greater than 0.5, or put it in a bin which is less than half full (which we hold a reference to)
* Runs in approximately linear time, and is significantly faster than the normal first Fit.

In the first fit heurstic, **S** is used to refer to the sum of the size of all objects. The project also offers an S estimate mode:

##### S estimate mode
* A simple mode which outputs the sum of all the objects given the input settings as an integer. Calculated as the rounded ceiling of the object sum.
### Building the project
To build the project, simply run ```make```  on the command line from the top level directory. This will produce an executable in ```bin/runner```. You can simply run this directly to run an example problem:
The example problem runs one instance of First fit with 50 objects using uniformly distributed object sizes.  

### Command usage
The current implemplementation offers a few different modes. The command line parsing is currently rudimentary, and doesn't offer non-positional arguments.

The arguments are as follows:
```bin/runner number_of_sims number_of_objects [distribution] [algorithm_mode]```

**If you specify distribution, it is recommended you also set algorithm.**

##### number_of_sims
* Run this many copies of a problem instance. The results will be averaged together.
##### number_of_objects
* Specifies the number of objects to simulate with
##### distribution 
* Specifies the distribution that the objects should have
* Default: [Normal] Distribution
* Options:
  * 0: Set the distribution to be Uniform(0,1).
  * 1: Set the distribution to be Normal(0.5,0.15).

##### algorithm_mode
* Set the algorithm or mode you would like to run in.
* Default: [first_fit] Use the naive first fit 
* Options:
  * 0: Use the naive first fit
  * 1: Use smart first fit
  * 2: Run S Estimate mode

### Results
The project outputs results in a very minimalistic way, so as to support large data production and parsing.

The basic output form is as follows:
```Experiments run, Algorithm, Number of objects, average number of bins, execution time in ms```

### Data Analysis scripts
Example scripts for data analysis and collection can be found in the scripting directory.
* ```simulationDriver.py``` is a simple customizable python script for generating large sets of results.
* ```DataAnalysis.py|ipynb``` is a script/Jupyter notebook which allows you to view various graphs and data tables from results generated by ```simulationDriver```

Any questions, please contact me at ```mitchellcorbett20@gmail.com```
```ᕙ(ȍ ³ȍ)ᕗ```
