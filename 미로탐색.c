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

void init_stack(StackType *s) // 스택 초기화 함수
{
    s->top = -1;
}

int is_empty(StackType *s)  // 공백 상태 검출 함수
{
    return (s->top == -1);
}

int is_full(StackType *s)  // 포화 상태 검출 함수 
{
    return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType *s, element item)  // 삽입 함수
{
    if (is_full(s)) {
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    else s->data[++(s->top)] = item;
}

element pop(StackType *s) // 삭제 함수
{
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return s->data[(s->top)--];
}

element peek(StackType *s)  // 피크 함수
{
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
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