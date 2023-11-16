#include <stdio.h>

void printArray(int arr[], int n){
  printf("{ ");
  for(int i = 0; i < n; i++){
    printf(i == 0 ? "%i" : ", %i", arr[i]);
  }
  printf("}\n");
}


int* getArray(int argc, char* argv[], int& printy, int& count){
  count = 6;
  printy = argc > 1 && strlen(argv[1]) == 1 && argv[1][0] == '0' ? 0 : 1;
  int* arr = NULL;
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
  return arr;
}

