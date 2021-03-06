#include "declerations.h"
// a function that removes a data from the list according to its code
void buyAnApt(List* lst, int code) {
	Apartment* current;
	Apartment* toDel;
	current = lst->head;
	while (current->next->code != code) {
		current = current->next;
	}
	if (current != NULL) {
		toDel = current->next;
		current->next = current->next->next;
		freeApt(&toDel);
	}
}