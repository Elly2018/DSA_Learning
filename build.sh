#! /bin/bash

mkdir bin

echo basic application
gcc -std=c11 -Wall -W src/basic/argument.c -o bin/argument.exe
gcc -std=c11 -Wall -W -Ilib/tinycthread/source src/thread/multi_thread.c -o bin/multi_thread.exe

echo sorting algorithms
gcc -std=c11 -Wall -W -Isrc/util src/sorting/selectSort.c -o bin/selectSort.exe
gcc -std=c11 -Wall -W -Isrc/util src/sorting/mergeSort.c -o bin/mergeSort.exe
gcc -std=c11 -Wall -W -Isrc/util src/sorting/bubbleSort.c -o bin/bubbleSort.exe
gcc -std=c11 -Wall -W -Isrc/util src/sorting/insertSort.c -o bin/insertSort.exe
gcc -std=c11 -Wall -W -Isrc/util src/sorting/quickSort.c -o bin/quickSort.exe

echo search algorithms
