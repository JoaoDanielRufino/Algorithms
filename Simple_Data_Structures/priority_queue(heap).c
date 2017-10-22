#include <stdio.h>
#include <stdlib.h>

typedef struct heapnode{
    int priority;
    int elem;
}Heapnode;

typedef struct priorityqueue{
    int size;
    Heapnode *heap;
}Priorityqueue;

void make_queue(Priorityqueue* pqueue, int n){
    pqueue->size = 0;
    pqueue->heap = (Heapnode*) malloc((n+1)*sizeof(Heapnode));
}

void push(Priorityqueue* pqueue, int size){
    int father,son;
    son = size + 1;
    father = son/2;
    Heapnode aux;
    while(father > 0 && pqueue->heap[father].priority < pqueue->heap[son].priority){
        aux = pqueue->heap[son];
        pqueue->heap[son] = pqueue->heap[father];
        pqueue->heap[father] = aux;
        son = father;
        father = son/2;
    }
}

void pop(Priorityqueue* pqueue, int father){
    int son;
    son = 2*father;
    Heapnode aux;
    while(son < pqueue->size){
        if(son < pqueue->size){
            if(pqueue->heap[son].priority < pqueue->heap[son+1].priority)
                son++;
        }
        if(pqueue->heap[son].priority > pqueue->heap[father].priority){
            aux = pqueue->heap[son];
            pqueue->heap[son] = pqueue->heap[father];
            pqueue->heap[father] = aux;
            father = son;
            son = 2*father;
        }
    }
}

void dequeue(Priorityqueue* pqueue){
    pqueue->heap[1] = pqueue->heap[pqueue->size];
    pqueue->size--;
    pop(pqueue,1);
}

void insert(Priorityqueue* pqueue, int data){
    pqueue->heap[pqueue->size + 1].elem = data;
    pqueue->heap[pqueue->size + 1].priority = data;
    push(pqueue,pqueue->size);
    pqueue->size++;
}

int front(Priorityqueue* pqueue){
    if(pqueue->size == 1)
        return pqueue->heap[1].elem;
    else{
        if(pqueue->heap[1].priority > pqueue->heap[2].priority)
            return pqueue->heap[1].elem;
        return pqueue->heap[2].elem;
   }
}
