#include "queue.h"
#include <assert.h>
#include <stdlib.h>


/*
 	vi använder oss *endast* av list-interfacet 
	för att skriva interagera med listan i bakgrunden
*/
Queue createQueue(void){	
	//Queue res = (List)malloc(sizeof(node));
	//////List res = new node;
	//if (!res) {
	//	return NULL;
	//}
	////return res;
	////List res;
	//res->d = -1;
	//res->rest = NULL;
	//return res;
	////return {};
	List ret = NULL;
	return ret;
}

int isQueueEmpty(Queue q){
	//return q.isEmpty();
	return isEmpty(q);
}

int enqueue(Queue* q, const int d){
	//return q->addLast(d);
	return addLast(q, d);
}

int dequeue(Queue* q){
	//assert(!q->isEmpty());
	//int ret = q->getFirstElement();
	//q->removeFirst();
	//assert(!isEmpty(*q));
	int ret = getFirstElement(*q);
	removeFirst(q);
	return ret; 
}

int peekQueue(Queue q){
	//assert(!q.isEmpty());
	//return q.getFirstElement();
	assert(!isEmpty(q));
	return getFirstElement(q);
}

void clearQueue(Queue* q){
	//q->clearList();
	//assert(q->isEmpty());
	clearList(q);
	assert(isEmpty(*q));
	//Postcondition: stacken är tom (testa med assert)
}

//kan vara bra att i utskriften skriva ut vad som är längst fram!
void printQueue(Queue q, FILE* stream){
    
}