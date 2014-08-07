#!/bin/bash

# To build the tests you must have installed:
# gcc
# check (http://check.sourceforge.net/)

gcc -o check_datastructs check_datastructs.c ../src/datastructs.c -I../src -lcheck -lm -lpthread -lrt

