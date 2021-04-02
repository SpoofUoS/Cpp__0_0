#include<stdio.h>
#include<stdlib.h>

#define MAX_STACK_SIZE 100         // 스택의 최대 크기     // 스택이 전역변수로 구현된다.
typedef int element;               // 데이터의 자료형
element stack[MAX_STACK_SIZE];     // 1차원 배열 
int top = -1;

int is_empty()  // 공백 상태 검출 함수 
{ 
    return (top == -1); 
}

int is_full()  // 포화 상태 검출 함수 
{
    return (top == (MAX_STACK_SIZE -1));
}

void push(element item) // 삽입 함수
{
    if (is_full()) {
        fprintf(stderr, "스택 포화 에러 \n");
        exit(1);
    }
    else stack[++top] = item;
}

element pop()
{
    if (is_empty()) {
        fprintf(stderr, "스택 공백 에러 \n");
    }
    else return stack[top--];
}

element peak()
{
    if (is_empty()){
        fprintf(stderr, "스택 공백 에러 \n");
        exit(1);
    }
    else return stack[top];
}

int main(void)
{
    push(1);
    push(2);
    push(3);
    printf("%d\n",pop());
    printf("%d\n",pop());
    printf("%d\n",pop());
}