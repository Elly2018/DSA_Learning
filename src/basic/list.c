#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Element Element;

struct Element {
	int value;
	struct Element* next;
};

int Count(struct Element* element){
  int r = 1;
  struct Element* n = element;
  printf("C in\n");
	while (n->next != NULL){
		r++;
		n = element->next;
    printf("counting %i\n", r);
	}
  printf("C out\n");
	return r;
}

void Add(struct Element* list, int value){
	struct Element* last = list;
  while (last->next != NULL){
		last = list->next;
	}
  struct Element* lastElement = (Element*)malloc(sizeof(Element));
  lastElement->value = value;
  lastElement->next = NULL;
	last->next = lastElement;
}

int main(){
  struct Element e = {0, NULL};
  printf("%i\n", Count(&e));
  Add(&e, 50);
  printf("%i\n", Count(&e));
  return 0;
}
