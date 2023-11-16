#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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

// first arg: print result 0 or 1
// after arg: number
int main(int argc, char* argv[]){
  int count = 6;
  int printy = argc > 1 && strlen(argv[1]) == 1 && argv[1][0] == '0' ? 0 : 1;
  int* arr = 0;
  if (argc <= 2){
    printf("Apply default number array\n");
    printf("benchmark sorting: %i %i %i %i %i %i\n", 100, 1000, 5000, 10000, 50000, 100000);
    arr = (int*)malloc(sizeof(int) * count);
    arr = {100, 1000, 5000, 10000, 50000, 100000};
  }else{
    count = argc - 2;
    arr = (int*)malloc(sizeof(int) * count);
    for(int i = 2; i < argc; i++){
      int buffer;
      sscanf(argv[i], "%d", &buffer);
      arr[i] = buffer;
    }
  }

  for(int i = 0; i < count; i++)
  {
    time_t t = clock();
    linearSort(arr[i]);
    printf("result: %i  %f\n", arr[i], ((double)(clock() - t)) / CLOCKS_PER_SEC);
  }
  return 0;
}
