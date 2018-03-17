typedef struct node{
  int data;
  struct node *next;
}Node;

typedef struct queue{
  int size;
  Node *head;
  Node *tail;
}List;

List* make_list(){
  List *li;
  li = (List*) malloc(sizeof(List));
  li->size = 0;
  li->head = NULL;
  li->tail = NULL;
  return li;
}

int emptyli(List* li){
  return (li->size==0);
}

void push_back(List* li, int c){
  Node *new;
  new = (Node*) malloc(sizeof(Node));
  if(emptyli(li)){
    new->data = c;
    new->next = NULL;
    li->head = new;
    li->tail = new;
  }
  else{
    new->data = c;
    new->next = NULL;
    li->tail->next = new;
    li->tail = new;
  }
  li->size++;
}

int top(List* li){
    return li->head->data;
}

int back(List* li){
    return li->tail->data;
}

void delete(List* li){
    Node *aux;
    aux = li->head;
    if(li->size==1){
        li->head = NULL;
        li->tail = NULL;
    }
    else
        li->head = li->head->next;
    free(aux);
    li->size--;
}

void free_list(List **li){ 
    while(!emptyli(li[i]))
        delete(li[i]);
    free(li);
}
