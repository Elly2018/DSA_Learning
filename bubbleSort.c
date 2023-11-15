#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define SORT_SIZE 50

void printArray(int arr[], int n){
  printf("{");
  for(int i = 0; i < n; i++){
    printf(i == 0 ? "%i" : ", %i", arr[i]);
  }
  printf("}\n");
}

int bubleSort(int size){
  time_t t;
  int i, j, temp;
  bool swap = false;
  int arr[size];

  srand((unsigned) time(&t));

  for(i = 0; i < size; i++){
    int r = rand() % 10000;
    arr[i] = r;
  }
  //printArray(arr, SORT_SIZE);



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
  
  //printArray(arr, SORT_SIZE);

  return 0;
 }

int main(){
  printf("benchmark sorting: %i %i %i %i %i\n", 100, 1000, 5000, 10000, 50000);
  int arr[5] = {100, 1000, 5000, 10000, 50000};
  for(int i = 0; i < 5; i++){
    clock_t starttime = clock();
    bubleSort(arr[i]);
    printf("result: %i,  %f\n", arr[i], ((double)(clock() - starttime)) / CLOCKS_PER_SEC);
  }
  return 0;
}

