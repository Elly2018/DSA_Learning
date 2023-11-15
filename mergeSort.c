#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <pthread.h>

void printArray(int arr[], int n){
  printf("{");
  for(int i = 0; i < n; i++){
    printf(i == 0 ? "%i" : ", %i", arr[i]);
  }
  printf("}\n");
}

void merge(int arr[], int start, int middle, int end){
  int i, j, k;
  int LeftSize = middle - start + 1;
  int RightSize = end - middle;

  int L[LeftSize];
  int R[RightSize];

  for(i = 0; i < LeftSize; i++){
    L[i] = arr[start + i];
  }

  for(j = 0; j < RightSize; j++){
    R[j] = arr[middle + 1 + j];
  }

  i = 0;
  j = 0;
  k = start;
  while(i < LeftSize && j < RightSize){
    if(L[i] <= R[j]){
      arr[k] = L[i];
      i++;
    }else{
      arr[k] = R[j];
      j++;
    }
    k++;
  }
  while (i < LeftSize){
    arr[k] = L[i];
    i++;
    k++;
  }
  while(j < RightSize){
    arr[k] = R[j];
    j++;
    k++;
  }
//  printf("merge log: %i %i %i %i %i %i %i %i\n", start, middle, end, i, j, k, LeftSize, RightSize);
}

void sort(int arr[], int start, int end){
  if(start < end){
    // if array length is 6
    // start = 0, end = 5, middle = 2
    int middle = start + (end - start) / 2;

    sort(arr, start, middle); // Left side, 0, 2
    sort(arr, middle + 1, end); // Right side, 3, 5

    merge(arr, start, middle, end); // 0, 2, 5
  }
}

void mergeSort(int size){
  time_t t;
  int i;
  int arr[size];

  srand((unsigned) time(&t));

  for(i = 0; i < size; i++){
    int r = rand() % 10000;
    arr[i] = r;
  }
  //printArray(arr, size);
  sort(arr, 0, size - 1);
  //printArray(arr, size);
}

int main(){ 
  printf("benchmark sorting: %i %i %i %i %i %i\n", 100, 1000, 5000, 10000, 50000, 100000);
  int arr[6] = {100, 1000, 5000, 10000, 50000, 100000};


  //mergeSort(50);
  //return 0;
  printf("Single-core test start \n");
  for(int i = 0; i < 6; i++){
    clock_t starttime = clock();
    mergeSort(arr[i]);
    printf("result: %i,  %f\n", arr[i], ((double)(clock() - starttime)) / CLOCKS_PER_SEC);
  }

  printf("Multi-core test start \n");

  for(int i = 0; i < 6; i++){
    clock_t starttime = clock();
    mergeSort(arr[i]);
    printf("result: %i,  %f\n", arr[i], ((double)(clock() - starttime)) / CLOCKS_PER_SEC);
  }
  return 0;
}
