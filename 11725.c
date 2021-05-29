#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int top;
    int* stack;
} stack_type;

void init_s(stack_type* s, int n)
{
    s->top = 0;
    s->stack = (int*)malloc(n*sizeof(int));
}

void push(stack_type* s, int k)
{
    s->stack[s->top++] = k;
}

int pop(stack_type* s)
{
    return s->stack[--(s->top)];
}

int is_empty(stack_type* s)
{
    return(s->top == 0);
}

typedef struct graph_node
{
    int vertex; // 정점
    struct graph_node* link;
} graph_node;

typedef struct graph_type
{
    int n; // 정점의 갯수
    graph_node** adj_list;
} graph_type;

void init_g(graph_type* g, int x)
{
    g->n = x;
    g->adj_list = (graph_node**)malloc(x * sizeof(graph_node*));
    for(int i=0; i<x; i++)
    {
        g->adj_list[i] = NULL;
    }
}

void insert_edge(graph_type* g, int u, int v)
{
    graph_node* node;

    node = (graph_node*)malloc(sizeof(graph_node));
    node->vertex = v;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;
}

void dfs(graph_type* g, int v, int n, int* arr)
{
    graph_node* w;
    int* visited;
    visited = (int*)calloc(n, sizeof(int));
    stack_type* s;
    s = (stack_type*)malloc(sizeof(stack_type));
    init_s(s, n);

    visited[v] = 1;
    push(s, v);

    while(!is_empty(s))
    {
        v = pop(s);
        if(visited[v])
        {
            visited[v] = 1;
            for(w = g->adj_list[v]; w; w = w->link)
            {
                if(!visited[w->vertex])
                {
                    visited[w->vertex] = 1;
                    arr[w->vertex] = v;
                    push(s, w->vertex);
                }
            }
        }
    }
}

int main()
{
    graph_type* g;
    g = (graph_type*)malloc(sizeof(graph_type));
    
    int n;
    scanf("%d",&n);

    init_g(g, n);
    int* arr;
    arr =  (int*)malloc(n*sizeof(int));

    int a, b;
    for(int i=0; i<n-1; i++)
    {
        scanf("%d %d",&a,&b);
        a--; b--;
        insert_edge(g, a, b);
        insert_edge(g, b, a);
    }
    dfs(g,0,n,arr);

    for(int i=1; i<n; i++)
    {
        printf("%d\n",arr[i]+1);
    }

    free(g);
    free(arr);
}