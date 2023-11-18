#include <stdlib.h>
#include <stdio.h>
#include "util.h"


int main(int argc, char* argv[]){
  int count = 0, printy = 0;
  int* arr = getArray(argc, argv, &printy, &count);

  return 0;
}
