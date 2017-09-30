//graph using adjacency lists

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
   int vert, data;
   struct node *prox;
}Node;

typedef struct graph{
   int num_vert,num_edge;
   int *degree;
   Node **edge;
}Graph;

Graph* make_graph(int num_vert){
   if(num_vert <= 0)
      return NULL;

   Graph *g;
   g = (Graph*) malloc(sizeof(Graph));
   if(g == NULL)
      return NULL;

   g->num_vert = num_vert;
   g->num_edge = 0;
   g->degree = (int*) calloc(num_vert,sizeof(int));
   if(g->degree == NULL){
      free(g);
      return NULL;
   }

   g->edge = (Node**) malloc(num_vert*sizeof(Node*));
   if(g->edge == NULL){
      free(g->edge);
      free(g);
      return NULL;
   }

   int i;
   for(i = 0; i < num_vert; i++)
      g->edge[i] = NULL;

   return g;
}

int verify_edge(Graph *g, int v1, int v2){
   if(g == NULL || v1 < 0 || v1 > g->num_vert || v2 < 0 || v2 > g->num_vert)
      return -1;

   Node *aux;
   aux = g->edge[v1];
   while(aux != NULL && aux->vert != v2)
      aux = aux->prox;

   if(aux == NULL)
      return 0;

   return 1;
}

int insert_edge(Graph *g, int v1, int v2, int data){
   if(verify_edge(g, v1, v2) == -1)
      return -1;

   if(verify_edge(g, v1, v2) == 1)
      return 0;

   Node *new,*new2;
   new = (Node*) malloc(sizeof(Node));
   new2 = (Node*) malloc(sizeof(Node));
   if(new == NULL || new2 == NULL)
      return 0;

   new->vert = v2;
   new->data = data;
   new->prox = g->edge[v1];
   g->edge[v1] = new;
                               /*
   new2->vert = v1;             *
   new2->data = data;           * With this the graph turns to non directional
   new2->prox = g->edge[v2];    *
   g->edge[v2] = new2;          */

   g->num_edge++;
   g->degree[v1]++;
   g->degree[v2]++;

   return 1;
}

int remove_edge(Graph *g, int v1, int v2){
   if(verify_edge(g, v1, v2) == -1)
      return -1;

   Node *aux,*ant;
   aux = g->edge[v1];
   ant = NULL;

   while(aux != NULL && aux->vert != v2){
      ant = aux;
      aux = aux->prox;
   }

   if(aux == NULL)
      return 0;

   if(ant == NULL)
      g->edge[v1] = aux->prox;
   else
      ant->prox = aux->prox;

   free(aux);
                                              /*
   Node *aux2,*ant2;                           *
   aux2 = g->edge[v2];                         *
   ant2 = NULL;                                *
                                               *
   while(aux2 != NULL && aux2->vert != v1){    *
      ant2 = aux2;                             *
      aux2 = aux2->prox;                       *
   }                                           *
                                               * With this the graph turns to non directional
   if(aux2 == NULL)                            *
      return 0;                                *
                                               *
   if(ant2 == NULL)                            *
      g->edge[v2] = aux2->prox;                *
   else                                        *
      ant2->prox = aux2->prox;                 *
                                               *
   free(aux2);                                 */
   g->num_edge--;
   g->degree[v1]--;
   g->degree[v2]--;

   return 1;
}

int consult_edge(Graph *g, int v1, int v2, int *data){
   if(verify_edge(g, v1, v2) == -1)
      return -1;

   Node *aux;
   aux = g->edge[v1];

   while(aux != NULL && aux->vert != v2)
      aux = aux->prox;

   if(aux == NULL)
      return 0;

   *data = aux->data;

   return 1;
}

void show_adj(Graph *g, int v){
   if(g == NULL || v < 0 || v > g->num_vert){
      printf("Invalid graph!!\n");
      return;
   }

   Node *aux;
   aux = g->edge[v];
   if(aux == NULL){
      printf("NULL\n");
      return;
   }

   int count = 0;
   while(aux != NULL){
      if(!count)
         printf("%d -> %d = %d", v,aux->vert,aux->data);
      else
         printf(", %d -> %d = %d", v,aux->vert,aux->data);
      aux = aux->prox;
      count++;
   }
   if(!count)
      printf("NULL\n");
   else
      printf("\n");
}

void show_graph(Graph *g){
   if(g == NULL){
      printf("Invalid graph!!\n");
      return;
   }

   if(!g->num_edge){
      printf("Empty graph!!\n");
      return;
   }

   int i;
   for(i = 0; i < g->num_vert; i++){
      printf("Vert[%d]: ", i);
      show_adj(g, i);
   }
}

void destroy(Graph **g){
   int i;
   Node *aux,*aux2;

   for(i = 0; i < (*g)->num_vert; i++){
      aux = (*g)->edge[i];
      while(aux != NULL){
         aux2 = aux;
         aux = aux->prox;
         free(aux2);
      }
   }
   free((*g)->edge);
   free((*g)->degree);
   free((*g));
   *g = NULL;
}

int main(){

   int num_vert;
   Graph *g;

   g = make_graph(4);
   insert_edge(g, 0, 2, 3);
   insert_edge(g, 1, 0, 4);
   insert_edge(g, 1, 2, 5);
   insert_edge(g, 1, 1, 5);
   insert_edge(g, 3, 1, 7);
   insert_edge(g, 2, 3, 4);
   insert_edge(g, 3, 2, 8);

   show_graph(g);

   remove_edge(g, 0, 2);
   remove_edge(g, 3, 2);
   remove_edge(g, 1, 2);
   remove_edge(g, 2, 3);

   printf("\nRemoved edges:\n");
   show_graph(g);

   destroy(&g);

   return 0;
}

