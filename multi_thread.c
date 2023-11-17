#include <stdio.h>
#include <stdint.h>
#include <tinycthread.h>

int printSomething(void* id){
  printf("%i\n", *(int*)id);
  return 0;
}

int main(int argc, char* argv[]){
  int count = 20;
  if(argc >= 2){
    sscanf(argv[0], "%d", &count);
  }
  thrd_t t[count];
  int arg[count];
  for(int i = 0; i < count; i++){
    thrd_t buffer;
    arg[i] = i;
    thrd_create(&buffer, printSomething, (void*)&arg[i]);
    t[i] = buffer;
  }

  for(int i = 0; i < count; i++){
    thrd_join(t[i], NULL);
  }

  return 0;
}
