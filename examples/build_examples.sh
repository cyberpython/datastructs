#!/bin/bash

# To build the tests you must have installed:
# gcc

gcc -o example_01 example_01.c ../src/datastructs.c -I../src
gcc -o example_02 example_02.c ../src/datastructs.c -I../src

