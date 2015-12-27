#!/bin/sh
make &&echo "make success----------------------------------------" && ./bin/compiler test/quicksort.c1 && echo "compile success----------------------------------------" && ./bin/interpreter test/quicksort.o
