#include "grafuri.h"

int main()
{
    Graph *g=create();
    egonet( g);
    printGraph(g);
    return 0;
}
