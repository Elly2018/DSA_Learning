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

int Count(struct List* list){
  int r = 1;
  struct Element* n = list->start;
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
	list->end->next = lastElement;
	list->end = lastElement;
}

int main(){
  struct Element e = {0, NULL};
  struct List l = {&e, &e};
  printf("%i\n", Count(&l));
  Add(&l, 50);
  Add(&l, 50);
  Add(&l, 50);
  printf("%i\n", Count(&l));
  Add(&l, 50);
  printf("%i\n", Count(&l));
  return 0;
}
