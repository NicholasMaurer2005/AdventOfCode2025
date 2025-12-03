These are my solutions to Advent of Code 2025. It is not a real project nor software for anyone to use, just a place where I can show of my (hopefully) clever solutions. I am going to sovle everything in C++ with the goal of minimizing heap allocaitons and branches, effectively producing the fastest runtime. 

### Project Layout
There is one header file 'Days.h' that contains the definitions for all of the days and nothing else. Each day part 1 and 2 will get its own source fle. I did it like this to avoid a twelve two-funciton header files while still keeping the solutions organized. 'Helper.h' and 'Helper.cpp' will contain reusable helper functions and right now helper classes
are kind of unorganized. I originally was going to keep all of them in the Helper header file but SplitString quickly became too large (in number of methods) that I felt it should be in its own file. I will probably come up with a better solution but hey its not like this is a long term project I mean its twelve days. 


### Cool Features I guess

**SplitString** is a class that simulates what would normally be a string.split() method in other languages used to convert a string into a list of strings. The problem with that is each string needs a heap allocation and the list itself needs a heap allocation. Instead I created SplitString which is essentially a view of a string with a custom iterator
to loop through the string as if it were a new list of strings seperated by a character. SplitString::Iterator::operator++ works by finding the next occurance of your character and updating its pointers to view what would be the new string. Anyways I think its pretty clever and it is brancheless and heap-allocation-less

