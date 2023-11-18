#include <stdio.h>
#include <stdlib.h>



int main(int argc, char* argv[]){
  FILE *fp;
  char path[1024];
  fp = popen("bubbleSort.exe", "r");
  if(fp == NULL){
    printf("Failed to run command\n");
    return 1;
  }

  while(fgets(path, sizeof(path), fp) != NULL){
    printf("%s", path);
  }

  pclose(fp);
  return 0;
}
