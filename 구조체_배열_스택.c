#include<stdio.h>
#include<stdlib.h>
#define MAX_STACK_SIZE 100
#define MAX_STRING 100

typedef struct {                  // 스택에 저장되는 데이터를 구조체로 저장한다.
    int student_no;
    char name[MAX_STRING];
    char address[MAX_STRING];
} element;

element stack[MAX_STACK_SIZE];
int top = -1;

int is_empty()  // 공백 상태 검출 함수 
{
    return (top == - 1);
}

int is_full() // 포화 상태 검출 함수
{
    return (top == (MAX_STACK_SIZE - 1));
}

void push(element item)  // 삽입 함수
{
    if (is_full()) {
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    else stack[++top] = item;
}

element pop()
{
    if (is_empty()){
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return stack[top--];
}

element peek()
{
    if(is_empty()){
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return stack[top];
}

int main()
{
    element ie = { 20210001,
    "Hong",
    "Seoul" };

    element oe;
    push(ie);
    oe = pop();

    printf("학번: %d\n", oe.student_no);
    printf("이름: %s\n", oe.name);
    printf("주소: %s\n", oe.address);
}