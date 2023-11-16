#! /bin/bash

mkdir bin

echo basic application
gcc -Wall -W argument.c -o bin/argument.exe
gcc -Wall -W -Ilib/tinycthread/source multi_thread.c -o bin/multi_thread.exe

echo sorting algorithms
gcc -Wall -W selectSort.c -o bin/selectSort.exe
gcc -Wall -W mergeSort.c -o bin/mergeSort.exe
gcc -Wall -W bubbleSort.c -o bin/bubbleSort.exe
gcc -Wall -W insertSort.c -o bin/insertSort.exe
