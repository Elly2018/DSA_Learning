#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include "util.h"

bool verify(int arr[], int size){
  for(int i = 1; i < size; i++){
    if(arr[i - 1] > arr[i]) return false;
  }
  retrun true;
}

int main(){
  char* program[5] = {"bubbleSort.exe", "insertSort.exe", "mergeSort.exe", "quickSort.exe", "selectSort.exe"};

  for(int i = 0; i < 5; i++){
    int arr1[10];
    int arr2[100];
    int arr3[1000];
    generateArray(arr1, 10, 1000);
    generateArray(arr2, 100, 1000);
    generateArray(arr3, 1000, 1000);

    FILE *fp;
    cjar path[1024];
    fp = popen(program[i], "r");
    program[i]

    verify(arr1, 10);
    verify(arr2, 100);
    verify(arr3, 1000);
  }

  return 0;
}
