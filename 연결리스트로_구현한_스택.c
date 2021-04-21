#include<stdio.h>
#include<malloc.h>

typedef int element;
typedef struct StackNode {
    element data;
    struct StackNode *link;
} StackNode;

typedef struct {
    StackNode *top;
} LinkedStackType;

void init(LinkedStackType *s)
{
    s->top = NULL;
}

int is_empty(LinkedStackType *s)
{
    return (s->top == NULL);
}

int is_full(LinkedStackType *s)
{
    return 0;
}

void push(LinkedStackType *s, element item)
{
    StackNode *temp = (StackNode *)malloc(sizeof(StackNode));
    temp->data = item;
    temp->link = s->top;
    s->top = temp;
}

void print_stack(LinkedStackType *s)
{
    for(StackNode *p = s->top; p != NULL; p = p->link) printf("%d->", p->data);
    printf("NULL \n");
}

element pop