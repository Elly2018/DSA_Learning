#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "util.h"

void linearSort(int size, int printy){
  int i, j, k, temp;
  int arr[size];
  time_t t;

  srand((unsigned) time(&t));
  for(i = 0; i < size; i++){
    int r = rand() % 100;
    arr[i] = r;
  }
  if(printy) printArray(arr, size);

  for(i = 0; i < size; i++){
    k = i;
    for(j = i; j < size; j++){
      if(arr[j] < arr[k]){
        k = j;
      }
    }
    if(k != i){
      temp = arr[i];
      arr[i] = arr[k];
      arr[k] = temp;
    }
  }
  if(printy) printArray(arr, size);
}

// first arg: print result 0 or 1
// after arg: number
int main(int argc, char* argv[]){
  int count = 0, printy = 0;
  int* arr = getArray(argc, argv, &printy, &count);
  printf("count: %i, printy: %i\n", count, printy);
  if(arr == NULL){
    printf("arr is NULL\n");
    return 1;
  }
  for(int i = 0; i < count; i++)
  {
    time_t t = clock();
    linearSort(arr[i], printy);
    printf("result: %i  %f\n", arr[i], ((double)(clock() - t)) / CLOCKS_PER_SEC);
  }
  return 0;
}
