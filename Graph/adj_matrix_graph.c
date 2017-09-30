//Graph using adjacency matrix

#include <stdio.h>
#include <stdlib.h>

typedef struct graph{
   int num_vert, num_edge;
   int *degree;
   int **edge;
}Graph;

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
      g->edge[i] = (int*) calloc(num_vert,sizeof(int**));
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
   if(g == NULL || v1 < 0 || v1 > g->num_vert || v2 < 0 || v2 > g->num_vert)
      return -1;

   if(!g->edge[v1][v2])
      return 0;

   return 1;
}

int insert_edge(Graph *g, int v1, int v2, int data){
   if(verify_edge(g, v1, v2) == -1)
      return -1;

   if(verify_edge(g, v1, v2) != 0)
      return 0;

   g->edge[v1][v2] = data;
   g->edge[v2][v1] = data; //Without this the graph turns to directional
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
   g->edge[v2][v1] = 0; //Without this the graph turns to directional
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
   if(g == NULL || v < 0 || v > g->num_vert){
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
         printf("%d ", g->edge[i][j]);
      }
      printf("\n");
   }
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

int main(){

   int num_vert;
   Graph *g;

   g = make_graph(4);
   insert_edge(g, 0, 1, 3);
   insert_edge(g, 1, 2, 5);
   insert_edge(g, 3, 1, 7);
   insert_edge(g, 2, 3, 4);
   insert_edge(g, 3, 2, 8);
   insert_edge(g, 0, 3, 2);

   print(g);

   remove_edge(g, 2, 3);
   remove_edge(g, 1, 2);

   printf("\nRemoved edge:\n");
   print(g);
   printf("\n");
   show_graph(g);

   destroy(&g);

   return 0;
}
