#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <vector>

/*	
	createListNode() finns för att göra koden lättare 
	att skriva. det är en så kallad hjälpfunktion.
	
	den är _inte_ med i interfacet, och är därmed static.

	vad den ska göra:
	allokera minne för en ny nod
	undersök om allokering lyckas
		returnera NULL ifall misslyckas
	initiera noden
	returnera noden */

static struct node* createListNode(Data d){
	struct node* newNode = (node*)malloc(sizeof(node));
	if (!newNode)
		return NULL;
	newNode->d = d;
	newNode->rest = NULL;
	return newNode;
}

List createEmptyList(void){
	return NULL; //är korrekt, ändra inte
}

int isEmpty(List l){
	return l == NULL;
}

int addFirst(List* l, Data d){
	node* newNode = createListNode(d);
	if (newNode) {
		newNode->rest = *l;
		*l = newNode;
		return 1;
	}
	return 0;
}

int addLast(List* l, Data d){
	if (isEmpty(*l))
		return addFirst(l, d);
	return addLast(&(*l)->rest, d);
}

void removeFirst(List* l){
	//precondition: listan är inte tom (testa med assert)
	assert(!isEmpty(*l));

	node* toRemove = *l;
	*l = (*l)->rest;
	free(toRemove);
}

void removeLast(List* l){
	//precondition: listan är inte tom (testa med assert)
	assert(!isEmpty(*l));

	if (isEmpty((*l)->rest))
		removeFirst(l);
	removeLast(&(*l)->rest);
}

int removeElement(List* l, Data d){
	if (isEmpty(*l))
		return 0;
	if (getFirstElement(*l) == d) {
		removeFirst(l);
		return 1;
	}
	return removeElement(&(*l)->rest, d);
}

int isInList(List l, Data d){
	if (isEmpty(l))
		return 0;
	if (getFirstElement(l) == d) {
		return 1;
	}
	return isInList(l->rest, d);
}

int lengthOfList(List l){
	if (isEmpty(l))
		return 0;
	return 1 + lengthOfList(l->rest);
}

void clearList(List* l){
	if (!isEmpty(*l)) {
		removeFirst(l);
		clearList(l);
	}
	//postcondition: listan är tom (testa med assert)
	assert(isEmpty(*l));
}

void printList(List l, FILE* stream){
	if (!isEmpty(l)) {
		fprintf(stream, "%d, ", getFirstElement(l));
		printList(l->rest, stream);
	}
	//bör använda iteration!
}

Data getFirstElement(List l){
	//precondition: listan är inte tom (testa med assert)
	assert(!isEmpty(l));

	return l->d;
}

Data getLastElement(List l){
	//precondition: listan är inte tom (testa med assert)
	assert(!isEmpty(l));

	if (isEmpty((l)->rest))
		return getFirstElement(l);
	return getLastElement(l->rest);
}
	