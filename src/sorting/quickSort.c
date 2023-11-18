#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int part(int arr[], int low, int high){
  int pi = arr[high];
  
  return 0;
}

void sort(int arr[], int low, int high){
  if(low < high){
    int pi = part(arr, low, high);
    sort(arr, low, pi - 1);
    sort(arr, pi + 1, high);
  }
}

void quickSort(int size, int printy){
  int arr[size];
  generateArray(arr, size, 1000);

  if(printy) printArray(arr, size);
  sort(arr, 0, size - 1);
  if(printy) printArray(arr, size);
}

int main(int argc, char* argv[]){
  int count = 0, printy = 0;
  int* arr = getArray(argc, argv, &printy, &count);
  printf("count: %i, printy: %i\n", count, printy);
  if(arr == NULL){
    printf("arr is NULL\n");
    return 1;
  }

  for(int i = 0; i < count; i++){
    time_t t = clock();
    quickSort(arr[i], printy);
    printf("result: %i  %f\n", arr[i], ((double)(clock() - t)) / CLOCKS_PER_SEC);
  }

  return 0;
}

