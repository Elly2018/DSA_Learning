#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "util.h"


int bubleSort(int size, int printy){
  time_t t;
  int i, j, temp;
  bool swap = false;
  int arr[size];

  srand((unsigned) time(&t));

  for(i = 0; i < size; i++){
    int r = rand() % 10000;
    arr[i] = r;
  }

  if(printy) printArray(arr, size);
  for(i = 0; i < size; i++){
    for(j = 0; j < size - 1 - i; j++){
      if(arr[j] > arr[j + 1]){        
        swap = true;
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
    if(!swap) break;
  }
  if(printy) printArray(arr, size);
  return 0;
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
    clock_t starttime = clock();
    bubleSort(arr[i], printy);
    printf("result: %i,  %f\n", arr[i], ((double)(clock() - starttime)) / CLOCKS_PER_SEC);
  }
  return 0;
}

