#include<stdio.h>
#include<stdlib.h>

// ���� �ڵ� ����

#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

void init_stack(StackType *s) // ���� �ʱ�ȭ �Լ�
{
    s->top = -1;
}

int is_empty(StackType *s)  // ���� ���� ���� �Լ�
{
    return (s->top == -1);
}

int is_full(StackType *s)  // ��ȭ ���� ���� �Լ� 
{
    return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType *s, element item)  // ���� �Լ�
{
    if (is_full(s)) {
        fprintf(stderr, "���� ��ȭ ����\n");
        return;
    }
    else s->data[++(s->top)] = item;
}

element pop(StackType *s) // ���� �Լ�
{
    if (is_empty(s)) {
        fprintf(stderr, "���� ���� ����\n");
        exit(1);
    }
    else return s->data[(s->top)--];
}

// ���� �ڵ��� ��

int main()
{
    StackType s;
    init_stack(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
}