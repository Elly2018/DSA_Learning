#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// Predefine the struct otherwise below struct will getting compile error
typedef struct Element Element;

struct List {
	struct Element* start;
	struct Element* end;
};

struct Element {
	int value; // The actual data
	struct Element* next; // Pointing to next data
};

void PrintList(struct List* list){
  printf("Current Data: { ");
  struct Element* n = list->start;
  while(n != NULL){
    printf("%i  ", n->value);
    n = n->next;
  }
  printf("}\n");
}

int Count(struct List* list){
  int r = 1;
  struct Element* n = list->start;
  if (list->start == NULL && list->end == NULL) return 0;
  if (list->start == list->end) return r;
  r++;
	while (n->next != list->end){
		r++;
		n = n->next;
	}
	return r;
}

void Add(struct List* list, int value){
  struct Element* lastElement = (Element*)malloc(sizeof(Element));
  lastElement->value = value;
  lastElement->next = NULL;
  if (list->start == NULL){
    list->start = lastElement;
    list->end = lastElement;
    return;
  }
	list->end->next = lastElement;
	list->end = lastElement;
}

void Delete(struct List* list, int index){
  if(list->start == NULL) {
    printf("List is empty\n");
    return;
  }
  int counter = 0;
  struct Element* n = list->start;
  struct Element* ln = list->start;
  while(counter < index){
    counter++;
    ln = n;
    n = n->next;
  }
  ln->next = n->next;
  if(index == 0){
    list->start = n->next;
  }
  free(n);
}

int main(){
  struct List l = {NULL, NULL};
  PrintList(&l);
  printf("Current Count: %i\n", Count(&l));
  Add(&l, 20);
  Add(&l, 75);
  Add(&l, 1577);
  PrintList(&l);
  printf("Current Count: %i\n", Count(&l));
  Add(&l, 2345);
  PrintList(&l);
  printf("Current Count: %i\n", Count(&l));
  Delete(&l, 2);
  PrintList(&l);
  printf("Current Count: %i\n", Count(&l));
  return 0;
}
