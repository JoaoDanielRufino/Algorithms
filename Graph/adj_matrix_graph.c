//Graph using adjacency matrix

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "queue.h"
#define MAX 10101010

struct graph{
   int num_vert, num_edge;
   int *degree;
   int **edge;
};

Graph* make_graph(int num_vert){
   if(num_vert <= 0)
      return NULL;

   int i,j;
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

   g->edge = (int**) malloc(num_vert*sizeof(int*));
   if(g->edge == NULL){
      free(g->edge);
      free(g);
      return NULL;
   }

   for(i = 0; i < num_vert; i++){
      g->edge[i] = (int*) calloc(num_vert,sizeof(int));
      if(g->edge[i] == NULL){
         for(j = 0; j < i; j++)
            free(g->edge[j]);
         free(g->edge);
         free(g->degree);
         free(g);
         return NULL;
      }
   }
   return g;
}

int verify_edge(Graph *g, int v1, int v2){
   if(g == NULL || v1 < 0 || v1 >= g->num_vert || v2 < 0 || v2 >= g->num_vert)
      return -1;

   if(!g->edge[v1][v2])
      return 0;

   return 1;
}

int insert_edge(Graph *g, int v1, int v2, int data){
   if(verify_edge(g, v1, v2) == -1)
      return -1;

   if(verify_edge(g, v1, v2) == 1)
      return 0;

   g->edge[v1][v2] = data;
   g->edge[v2][v1] = data; //Without this, the graph turns to directional
   g->num_edge++;
   g->degree[v1]++;
   g->degree[v2]++;

   return 1;
}

int remove_edge(Graph *g, int v1, int v2){
   if(verify_edge(g, v1, v2) == -1)
      return -1;

   if(!verify_edge(g, v1, v2))
      return 0;

   g->edge[v1][v2] = 0;
   g->edge[v2][v1] = 0; //Without this, the graph turns to directional
   g->num_edge--;
   g->degree[v1]--;
   g->degree[v2]--;

   return 1;
}

int consult_edge(Graph *g, int v1, int v2, int *data){
   if(verify_edge(g, v1, v2) == -1)
      return -1;

   if(!verify_edge(g, v1, v2))
      return 0;

   *data = g->edge[v1][v2];

   return 1;
}

void show_adj(Graph *g, int v){
   if(g == NULL || v < 0 || v >= g->num_vert){
      printf("Invalid graph!!\n");
      return;
   }

   int i,count = 0;
   for(i = 0; i < g->num_vert; i++){
      if(g->edge[v][i] != 0 && !count){
         printf("%d -> %d = %d", v,i,g->edge[v][i]);
         count++;
      }
      else if(g->edge[v][i] != 0 && count != 0){
         printf(", %d -> %d = %d", v,i,g->edge[v][i]);
         count++;
      }
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

void print(Graph *g){
   if(g == NULL){
      printf("Invalid graph!!\n");
      return;
   }

   if(!g->num_edge){
      printf("Empty graph!!\n");
      return;
   }

   int i,j;
   printf("Degree: ");
   for(i = 0; i < g->num_vert; i++)
      printf("%d ", g->degree[i]);

   printf("\nGraph:\n");
   for(i = 0; i < g->num_vert; i++){
      for(j = 0; j < g->num_vert; j++){
         printf("%3d", g->edge[i][j]);
      }
      printf("\n");
   }
}

void deep_search(Graph *g, int v, int *seen){
   seen[v] = 1;
   printf("%d -> ", v);

   int i;
   for(i = 0; i < g->num_vert; i++){
      if(!seen[i] && g->edge[v][i] != 0)
         deep_search(g, i, seen);
   }
}

void dfs(Graph *g, int v){
   int *seen,i;
   seen = (int*) calloc(g->num_vert, sizeof(int));
   /*for(i = 0; i < g->num_vert; i++){ Use this for not connected graph
      if(!seen[i])*/
         deep_search(g, v, seen); //Then change v fot i
   //}
   printf("\n");
}

void deep_search2(Graph *g, int v, int *seen){
   int u,i;
   Stack *st;
   st = make_stack();

   push(st, v);
   while(!empty(st)){
      u = top(st);
      pop(st);
      if(!seen[u]){
         seen[u] = 1;
         printf("%d -> ", u);
      }
      for(i = 0; i < g->num_vert; i++){
         if(!seen[i] && g->edge[u][i] != 0)
            push(st, i);
      }
   }
   free_stack(st);
}

void iterative_dfs(Graph *g, int v){
   int *seen,i;
   seen = (int*) calloc(g->num_vert, sizeof(int));
   /*for(i = 0; i < g->num_vert; i++){ Use this for not connected graph
      if(!seen[i])*/
         deep_search(g, v, seen); //Then change v fot i
   //}
   printf("\n");
}

void bfs(Graph *g, int v){
   int *seen;
   seen = (int*) calloc(g->num_vert, sizeof(int));

   int u,i;
   Queue *q;
   q = make_queue();

   seen[v] = 1;
   enqueue(q, v);
   while(!empty_queue(q)){
      u = front(q);
      dequeue(q);
      printf("%d -> ", u);

      for(i = 0; i < g->num_vert; i++){
         if(!seen[i] && g->edge[u][i] != 0){
            seen[i] = 1;
            enqueue(q, i);
         }
      }
   }
   free_queue(q);
}

void bfs2(Graph *g, int v, int *seen, Queue *q){
   seen[v] = 1;
   if(!empty_queue(q)){
      dequeue(q);
      printf("%d -> ", v);

      int i;
      for(i = 0; i < g->num_vert; i++){
         if(!seen[i] && g->edge[v][i] != 0){
            seen[i] = 1;
            enqueue(q, i);
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
   //Change g->edge[][] for 1 to use unweigthed graph.
   int *dist,*seen,*path,i,j;
   path = (int*) malloc(g->num_vert*sizeof(int));
   seen = (int*) calloc(g->num_vert, sizeof(int));
   dist = (int*) malloc(g->num_vert*sizeof(int));

   for(i = 0; i < g->num_vert; i++)
      dist[i] = MAX, path[i] = -1;

   dist[init] = 0;
   for(i = 0; i < g->num_vert-1; i++){
      int u = min_distance(dist, seen, g->num_vert);
      seen[u] = 1;

      for(j = 0; j < g->num_vert; j++){
         if(!seen[j] && g->edge[u][j] != 0 && dist[u] != MAX && (dist[u] + g->edge[u][j] < dist[j])){
            dist[j] = dist[u] + g->edge[u][j];
            path[j] = u;
         }
      }
   }
   printf("Menor distancia entre %d e %d: %d\nMenor caminho: ", init,end,dist[end]);
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
   for(i = 0; i < (*g)->num_vert; i++)
      free((*g)->edge[i]);
   free((*g)->edge);
   free((*g)->degree);
   free((*g));
   *g = NULL;
}
