#! /bin/bash

mkdir bin

echo basic application
gcc -std=c11 -Wall -W argument.c -o bin/argument.exe
gcc -std=c11 -Wall -W -Ilib/tinycthread/source multi_thread.c -o bin/multi_thread.exe

echo sorting algorithms
gcc -std=c11 -Wall -W selectSort.c -o bin/selectSort.exe
gcc -std=c11 -Wall -W mergeSort.c -o bin/mergeSort.exe
gcc -std=c11 -Wall -W bubbleSort.c -o bin/bubbleSort.exe
gcc -std=c11 -Wall -W insertSort.c -o bin/insertSort.exe
gcc -std=c11 -Wall -W quickSort.c -o bin/quickSort.exe

