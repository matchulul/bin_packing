# bin_packing
An implementation of the problem in CLRS 35-1 - Bin Packing

Problem 35-1 **Bin packing**

Suppose that we are given a set of *n* objects, where the size s~i~ of the *i*th object satisfies 0 < s~i~ < 1. We wish to pack all of the objects in to the minimum number of unit sized bins. Each bin can hold any subset of the objects whose total size does not exceed 1. 

**a.** Prove that the problem of determining the minimum number of bins required is NP-hard

The **first-fit** heuristic takes each object in turn and places it in to the first bin that can accommodate it. Let S = sum(i,n of s~i~)

**b.** Argue that the optimal number of bins is at least ceiling(S).
**c.** Argue that the first-fit heuristic leaves at most one bin less than half full.

**d.** Prove that the number of bins used by the first-git heuristic is never more than ceiling(2S).

**e.** Prove an approximation ratio of 2 for the first-fit heuristic.

**f.** Give an efficient implementation of the first-fit heuristic and analyze its running time.

a-e will be answered in a googledoc. Additionally, the Experimental report will also be in the document:

Experimental report. Submit a PDF or Microsoft Word. Other file formats are not acceptable. The report should include the following: 
a. A description of your software and hardware environment for developing the project.
b. The design of the algorithm.
c. Testing input data and the results and complexity analysis. You should include some screen shots showing the running scenarios and the running results.
d. A user manual explaining how to run your project.  
e. Discussions and reflection on knowledge gained.
f. References.










CODE TODO:
 get chrono working properly god damn it 
 Refactor first fit greedy algo to encapsulate linear searching bins 
 generalize the timing bits of the the simulation runner
 write soem basic arg parsing so I can script outputs  and parse the results