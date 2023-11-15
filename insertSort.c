#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void printArray(int arr[], int n){
  printf("{");
  for(int i = 0; i < n; i++){
    printf(i == 0 ? "%i" : ", %i", arr[i]);
  }
  printf("}\n");
}

void sort(int arr[], int size){
  int i, j;
  for(i = 1; i < size; i++){
    j = i;
    (arr[i] < arr[i - 1]){

    }
  }
}

void insertSort(int size){ 
  time_t t;
  int i;
  int arr[size];

  srand((unsigned) time(&t));

  for(i = 0; i < size; i++){
    int r = rand() % 10000;
    arr[i] = r;
  }

  sort(arr, size);
}

int main(){
  printf("benchmark sorting: %i %i %i %i %i %i\n", 100, 1000, 5000, 10000, 50000, 100000);
  int arr[6] = {100, 1000, 5000, 10000, 50000, 100000};

  for(int i = 0; i < 6; i++){
    clock_t starttime = clock();
    insertSort(arr[i]);
    printf("result: %i,  %f\n", arr[i], ((double)(clock() - starttime)) / CLOCKS_PER_SEC);
  }

  return 0;
}
