#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int data;
  struct node *next;
}Node;

typedef struct queue{
  int size;
  Node *head;
  Node *tail;
}Queue;

Queue* make_queue(){
  Queue *q;
  q = (Queue*) malloc(sizeof(Queue));
  q->size = 0;
  q->head = NULL;
  q->tail = NULL;
  return q;
}

int empty(Queue* q){
  return (q->size == 0);
}

void push(Queue* q, int n){
  Node *new;
  new = (Node*) malloc(sizeof(Node));
  if(empty(q)){
    new->data = n;
    new->next = NULL;
    q->head = new;
    q->tail = new;
  }
  else{
    new->data = n;
    new->next = NULL;
    q->tail->next = new;
    q->tail = new;
  }
  q->size++;
}

void pop(Queue* q){
    Node *aux;
    aux = q->head;
    if(q->size == 1){
        q->head = NULL;
        q->tail = NULL;
    }
    else
        q->head = q->head->next;
    free(aux);
    q->size--;
}

int top(Queue* q){
  if(empty(q))
    return;
  return q->head->data;
}

void free_queue(Queue* q){
   while(!empty(q))
      pop(q);
   free(q);
}
