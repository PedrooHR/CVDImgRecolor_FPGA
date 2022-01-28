#!/bin/bash

g++ -c -pg src/solver.cpp -std=c++11
g++ -c -pg src/dataset.cpp -std=c++11
g++ -c -pg src/utils.cpp -std=c++11
g++ -c -pg src/grid.cpp -std=c++11
g++ -c -pg src/main.cpp -std=c++11
g++ *.o -pg -o main -lX11 -lpthread -ljpeg
