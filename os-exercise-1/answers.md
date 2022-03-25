# Answers - OS-Exercise 1
## Task 3
**t3_case1.o**

The input array [5 9 1 2 3] gets sorted in ascending order resulting in the output [1 2 3 5 9].

**t3_case2.o**

The input array [5 9 1 2 3] gets sorted in decending order resulting in th output [9 5 3 2 1].

**t3_case3.o**

The input array [5 9 1 2 3] gets sorted in ascending order resulting in the ouput [1 2 3 5 9].

**Why different outcomes?**

The different outcomes in the three cases is a result of the structure of the programm. The file *T3.c* contains the code that creates the input array and prints the result. To sort the input, *T3.c* calls the method sort that isn't part of *T3.c* but part of *mylib1* in *case1* and *mylib2* in *case2*. *mylib 1* and *2* are the compiation output of the two files *l1.c* and *l2.c*. Those implement the swapping of elements in the input array as well as the sorting itself (e.g the comparison of elements and when to swap them). Therefore the sorting behaviour of *T3.c* is determined by *l1.c* and *l2.c*. As *case1* uses *l1.c* and *case2* uses *l2.c* the behavious differs. *Case 3* is special as it doesn't use mylib but includes *l1.c* directly. Therefore it acts the same as case 1.

## Task 4
**Linking**: The process of combining required support code like required libraries with the object code to make an executable program.

**Compiling**: The process of translation of source code to binary object code.
