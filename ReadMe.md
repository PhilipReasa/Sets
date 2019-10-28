# Sets

## About
This is a quick little project that I threw together to explore different potential time complexities for different Set implementations

## Variations
There are three implementations

 1. List based. Just add the element to a list. You can clear the list quickly, but other ops take O(count) time
 2. Map based. Add elements to an array. This works really well if you are using most of your domain. Inset, remove, and lookup are fast, but clear is slow
 3. Hybrid. Use both a List and a Map. Twice the memory footprint, but you can do all ops in O(1)

##Operations
| x        | Insert    | Remove    | Lookup    | Clear  |
|---       |---        |---        |---        |---     |
| LIST     | O(count)  | O(count)  | O(Count)  | O(1)   |
| MAP      | O(1)      | O(1)      | O(1)      | O(N)   |
| HYBRID   | O(1)      | O(1)      | O(1)      | O(1)   |

## Repo Info
### Makefile
There is a make file with three main commands
 * test - creates an executable to run a set of unit tests on the algorythms. You can change what algorythm is put through the test in test.cpp I'm using the catch (https://github.com/philsquared/Catch) testing framwork.
 * evaluate - creates an executable to see how the algs perform (time-wise). You can play around with the two main parameters (STRESS_REPS and DOMAIN_MAX) in evaluate.cpp
 * clean - removes the .o's for test and evaluate
 
### Data Structures
There is one ADT (set.hpp) that the tree algo's inheret from.
The implementations do require a domain range to be provided.
The code is half set up to accept both a LOW and HIGH d=bound, but is currently only tested with a high bound
