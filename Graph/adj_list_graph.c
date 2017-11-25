//graph using adjacency lists

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "queue.h"
#define MAX 10101010

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
   if(g == NULL || v1 < 0 || v1 >= g->num_vert || v2 < 0 || v2 >= g->num_vert)
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
   if(g == NULL || v < 0 || v >= g->num_vert){
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

void deep_search(Graph *g, int v, int *seen){
   seen[v] = 1;

   printf("%d -> ", v);
   Node *aux;
   for(aux = g->edge[v]; aux != NULL; aux = aux->prox){
      int u = aux->vert;
      if(!seen[u]){
         //printf("Next vert: %d\n\n", u);
         deep_search(g, u, seen);
      }
   }
}

void dfs(Graph *g, int v){
   int *seen,i;
   seen = (int*) calloc(g->num_vert, sizeof(int));
   /*for(i = 0; i < g->num_vert; i++){ Use this for not connected graph
      if(!seen[i])*/
         deep_search(g, v, seen); //Then change v fot i
   //}
   printf("End.\nSeen: ");
   for(i = 0; i < g->num_vert; i++)
      printf("%d ", seen[i]);
}

void deep_search2(Graph *g, int v, int *seen){
   Node *aux;
   Stack *st;
   st = make_stack();

   push(st, v);
   while(!empty(st)){
      v = top(st);
      pop(st);
      if(!seen[v]){
         printf("%d -> ", v);
         seen[v] = 1;
      }
      for(aux = g->edge[v]; aux != NULL; aux = aux->prox){
         if(!seen[aux->vert])
            push(st, aux->vert);
      }
   }
   free_stack(st);
}

void iterative_dfs(Graph *g, int v){
   int *seen,i;
   seen = (int*) calloc(g->num_vert, sizeof(int));
   /*for(i = 0; i < g->num_vert; i++){ Use this for not connected graph
      if(!seen[i])*/
         deep_search2(g, v, seen); //Then change v for i
   //}
}

void bfs(Graph *g, int v){
   int *seen;
   seen = (int*) calloc(g->num_vert, sizeof(int));

   int u;
   Node *aux;
   Queue *q;
   q = make_queue();

   seen[v] = 1;
   enqueue(q, v);
   while(!empty_queue(q)){
      u = front(q);
      dequeue(q);
      printf("%d -> ", u);

      for(aux = g->edge[u]; aux != NULL; aux = aux->prox){
         if(!seen[aux->vert]){
            seen[aux->vert] = 1;
            enqueue(q, aux->vert);
         }
      }
   }
   free_queue(q);
   printf("\nSeen: ");
   int i;
   for(i = 0; i < g->num_vert; i++)
      printf("%d ", seen[i]);
}

void bfs2(Graph *g, int v, int *seen, Queue *q){
   seen[v] = 1;
   Node *aux;
   if(!empty_queue(q)){
      dequeue(q);
      printf("%d -> ", v);

      for(aux = g->edge[v]; aux != NULL; aux = aux->prox){
         if(!seen[aux->vert]){
            seen[aux->vert] = 1;
            enqueue(q, aux->vert);
         }
      }
      if(!empty_queue(q))
         bfs2(g, front(q), seen, q);
   }
}

void recursive_bfs(Graph *g, int v){
   int *seen;
   Queue *q;
   seen = (int*) calloc(g->num_vert, sizeof(int));
   q = make_queue();

   enqueue(q, v);
   /*int i;
   for(i = 0; i < g->num_vert; i++){ Use this for not connected graph
      if(!seen[i])*/
         bfs2(g, v, seen, q); //Then change v for i
   //}
   free_queue(q);
}

void show_path(int init, int end, int *path){
   if(init == end)
      printf("%d", init);
   else if(path[end] == -1)
      printf("Nao existe caminho de %d para %d\n", init,end);
   else{
      show_path(init, path[end], path);
      printf("%4d", end);
   }
}

int min_distance(int *dist, int *seen, int n){
   int min = MAX, minpos,i;
   for(i = 0; i < n; i++){
      if(!seen[i] && dist[i] < min){
         min = dist[i];
         minpos = i;
      }
   }
   return minpos;
}

void dijkstra(Graph *g, int init, int end){
   //Change aux->data for 1 to use unweigthed graph.
   int *dist,*seen,*path,i,j;
   path = (int*) malloc(g->num_vert*sizeof(int));
   seen = (int*) calloc(g->num_vert, sizeof(int));
   dist = (int*) malloc(g->num_vert*sizeof(int));

   for(i = 0; i < g->num_vert; i++)
      dist[i] = MAX, path[i] = -1;

   dist[init] = 0;
   Node *aux;

   for(i = 0; i < g->num_vert-1; i++){
      int u = min_distance(dist, seen, g->num_vert);
      seen[u] = 1;

      for(aux = g->edge[u]; aux != NULL; aux = aux->prox){
         if(!seen[aux->vert] && dist[u] != MAX && (dist[u] + aux->data < dist[aux->vert])){
            dist[aux->vert] = dist[u] + aux->data;
            path[aux->vert] = u;
         }
      }
   }
   printf("Shortest distance between %d and %d: %d\nShortest path: ", init,end,dist[end]);
   show_path(init, end, path);
}

int verify_all_adj(Graph *g, int v){
   int i,data;
   for(i = 0; i < g->num_vert; i++){
      if(i != v){
         if(!consult_edge(g, v, i, &data))
            return 0;
      }
   }
   return 1;
}

int verify_disconected_vert(Graph *g, int v){
   int i,data;
   for(i = 0; i < g->num_vert; i++){
      if(i != v){
         if(consult_edge(g, v, i, &data))
            return 0;
      }
   }
   return 1;
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
