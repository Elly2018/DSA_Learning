#include <stdio.h>
#include <string.h>
#include <time.h>

void generateArray(int* arr, int size, int limit){
  int i;
  time_t t;

  srand((unsigned) time(&t));
  for(i = 0; i < size; i++){
    int r = rand() % limit;
    arr[i] = r;
  }
}

void printArray(int arr[], int n){
  printf("{ ");
  for(int i = 0; i < n; i++){
    printf(i == 0 ? "%i" : ", %i", arr[i]);
  }
  printf("}\n");
}


int* getArray(int argc, char* argv[], int* printy, int* count){
  *count = 6;
  *printy = argc > 1 && strlen(argv[1]) == 1 && argv[1][0] == '0' ? 0 : 1;
  int* arr = NULL;
  if (argc <= 2){
    printf("Apply default number array\n");
    printf("benchmark sorting: %i %i %i %i %i %i\n", 100, 1000, 5000, 10000, 50000, 100000);
    arr = (int*) malloc(sizeof(int) * 6);
    arr[0] = 100;
    arr[1] = 1000;
    arr[2] = 5000;
    arr[3] = 10000;
    arr[4] = 50000;
    arr[5] = 100000;
  }else{
    *count = argc - 2;
    arr = (int*)malloc(sizeof(int) * (*count));
    for(int i = 2; i < argc; i++){
      int buffer;
      sscanf(argv[i], "%d", &buffer);
      arr[i] = buffer;
    }
  }
  return arr;
}

