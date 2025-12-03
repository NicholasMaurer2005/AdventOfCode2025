These are my solutions to Advent of Code 2025. It is not a real project nor software for anyone to use, just a place where I can show of my (hopefully) clever solutions. I am going to sovle everything in C++ with the goal of minimizing heap allocaitons and branches, effectively producing the fastest runtime. 

### Cool Features I guess

**SplitString** is a class that simulates what would normally be a string.split() method in other languages used to convert a string into a list of strings. The problem with that is each string needs a heap allocation and the list itself needs a heap allocation. Instead I created SplitString which is essentially a view of a string with a custom iterator
to loop through the string as if it were a new list of strings seperated by a character. SplitString::Iterator::operator++ works by finding the next occurance of your character and updating its pointers to view what would be the new string. Anyways I think its pretty clever and it is brancheless and heap-allocation-less

