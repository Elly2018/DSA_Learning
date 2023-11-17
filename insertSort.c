#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "util.h"

void sort(int arr[], int size){
  int i, j, temp;
  for(i = 1; i < size; i++){
    j = i;
    while(arr[j] < arr[j - 1] && j > 0){
      temp = arr[j];
      arr[j] = arr[j - 1];
      arr[j - 1] = temp;
      j--;
    }
  }
}

void insertSort(int size, int printy){ 
  time_t t;
  int i;
  int arr[size];

  srand((unsigned) time(&t));

  for(i = 0; i < size; i++){
    int r = rand() % 10000;
    arr[i] = r;
  }
  if(printy) printArray(arr, size);
  sort(arr, size);
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
    clock_t starttime = clock();
    insertSort(arr[i], printy);
    printf("result: %i,  %f\n", arr[i], ((double)(clock() - starttime)) / CLOCKS_PER_SEC);
  }

  return 0;
}
