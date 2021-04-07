#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STACK_SIZE 6

typedef struct {
    short r;
    short c;
} element;


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

element peek(StackType *s)  // ��ũ �Լ�
{
    if (is_empty(s)) {
        fprintf(stderr, "���� ���� ����\n");
        exit(1);
    }
    else return s->data[s->top];
}

element here = { 1, 0 }, entry = { 1, 0 };

char maze[MAX_STACK_SIZE][MAX_STACK_SIZE] = {
    {'1','1','1','1','1','1'},
    {'e','0','1','0','0','1'},
    {'1','0','0','0','1','1'},
    {'1','0','1','0','1','1'},
    {'1','0','1','0','0','x'},
    {'1','1','1','1','1','1'},
};

void push_loc(StackType *s, int r, int c)
{
    if (r<0 || c<0) return;

}