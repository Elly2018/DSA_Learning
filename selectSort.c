#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void printArray(int arr[], int n){
  printf("{ ");
  for(int i = 0; i < n; i++){
    printf(i == 0 ? "%i" : ", %i", arr[i]);
  }
  printf("}\n");
}

void linearSort(int size){
  int i, j, k, temp;
  int arr[size];
  time_t t;

  srand((unsigned) time(&t));
  for(i = 0; i < size; i++){
    int r = rand() % 100;
    arr[i] = r;
  }
//printArray(arr, size);

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
  //printArray(arr, size);
}

int main(){
  printf("benchmark sorting: %i %i %i %i %i\n", 100, 1000, 5000, 10000, 50000);
  int arr[5] = {100, 1000, 5000, 10000, 50000};
  for(int i = 0; i < 5; i++)
  {
    time_t t = clock();
    linearSort(arr[i]);
    printf("result: %i  %f\n", arr[i], ((double)(clock() - t)) / CLOCKS_PER_SEC);
  }
  return 0;
}
