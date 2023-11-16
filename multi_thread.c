#include <stdio.h>
#include <stdint.h>
#include <tinycthread.h>

#define COUNT 20

int printSomething(void* id){
  printf("%i\n", *(int*)id);
  return 0;
}

int main(int argc, char* argv[]){
  thrd_t t[COUNT];
  int arg[COUNT];
  for(int i = 0; i < COUNT; i++){
    thrd_t buffer;
    arg[i] = i;
    thrd_create(&buffer, printSomething, (void*)&arg[i]);
    t[i] = buffer;
  }

  for(int i = 0; i < COUNT; i++){
    thrd_join(t[i], NULL);
  }

  return 0;
}
