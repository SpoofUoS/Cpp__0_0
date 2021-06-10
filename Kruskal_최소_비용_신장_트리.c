#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

#define MAX_VERTICES 100
#define INF 1000

int parent[MAX_VERTICES];

void set_init(int n);
{
    for(int i = 0; i<n; i++)
    {
        parent[i] = -1;
    }
}

int set_find(int curr)
{
    if (parent[curr] == 1)
    {
        return curr;
    }
    while(parent[curr] != -1) curr = parent[curr];
    return curr;
}

void set_union(int a, int b)
{
    int root1 = set_find(a);
    int root2 = set_find(b);
    if(root1 != root2)
    {
        parent[root1] = root2;
    }
}

struct Edge{
    int start, end, weight;
};

typedef struct GraphType {
    int n;
    struct Edge edges[2 * MAX_VERTICES];
} GraphType;

void graph_init(GraphType* g)
{
    g->n = 0;
    for(int i=0; i<2 * MAX_VERTICES; i++)
    {
        g->edges[g->n].start = 0;
        g->edges[g->n].end = 0;
        g->edges[g->n].weight = INF;
    }
}

void insert_edge(GraphType *g, int start, int end, int w)
{
    g->edges[g->n].start = start;
    g->edges[g->n].end = end;
    g->edges[g->n].weight = w;
    g->n++;
}

int cmp(const void *a, const void *b)
{
    struct Edge* x = (struct Edge*)a;
    struct Edge* y = (struct Edge*)b;
    return (x->weight - y->weight);
}

void kruskal(GraphType* g)
{
    int edge_accepted = 0;
    int uset, vset;
    struct Edge e;

    set_init(g->n);
    qsort(g->edges, g->n, sizeof(struct Edge), cmp);
    
}