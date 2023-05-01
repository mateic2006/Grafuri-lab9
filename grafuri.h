#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Graph{
int V;
int E;
int **a;
};
typedef struct Graph Graph;

Graph* create();
void printGraph(Graph *g);

void egonet(Graph *g);
