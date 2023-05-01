#include "grafuri.h"

Graph* create()
{
int i, j;
srand(time(NULL));
Graph *g=( Graph*)malloc(sizeof(Graph));

    if (g== NULL )
    {
        printf("memerror");
        return NULL;
    }

g->V=20;
g->a=(int**)malloc(g->V*sizeof(int*));

    for (i=0;i<g->V;i++)
        g->a[i] = ( int *)calloc(g->V,sizeof(int));

    if(g->a== NULL )
    {
        printf("memerror");
        return NULL;
    }

g->E=0;

   for(i=0;i<g->V && g->E<190;i++)
        for (j=0;j<i;j++)
        {
            g->a[i][j]=(rand()%2)*10;
            g->a[j][i]=g->a[i][j];
        if(g->a[i][j]!=0)
            g->E+=1;
        }

    return g;
}
void printGraph(Graph *g)
{
int i, j;
for (i=0;i<g->V;i++){
    for (j=0;j<g->V;j++)
        printf ("%2d ",g->a[i][j]);
    printf ("\n");

    }
     printf("%d", g->E);
}
void egonet(Graph *g)
{
    int i,j;
    int n= rand()%20 +1;
    printf("%d\n",n);
    for(i=0; i<g->V && i!=n-1; i++)
    {
        if(g->a[i][n-1]!=0)
            {
                g->a[i][n-1]+=10;
                g->a[n-1][i]+=10;
                for(j=0; j<g->V && j!=n-1 && j!=i; j++)
                {
                    if(g->a[j][i]!=0 && g->a[j][n-1]==0)
                        g->a[i][j]=14;
                        g->a[j][i]=14;
                }
            }
    }
}
