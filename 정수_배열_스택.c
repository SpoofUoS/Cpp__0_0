#include<stdio.h>
#include<stdlib.h>

#define MAX_STACK_SIZE 100         // ������ �ִ� ũ��     // ������ ���������� �����ȴ�.
typedef int element;               // �������� �ڷ���
element stack[MAX_STACK_SIZE];     // 1���� �迭 
int top = -1;

int is_empty()  // ���� ���� ���� �Լ� 
{ 
    return (top == -1); 
}

int is_full()  // ��ȭ ���� ���� �Լ� 
{
    return (top == (MAX_STACK_SIZE -1));
}

void push(element item) // ���� �Լ�
{
    if (is_full()) {
        fprintf(stderr, "���� ��ȭ ���� \n");
        exit(1);
    }
    else stack[++top] = item;
}

element pop()
{
    if (is_empty()) {
        fprintf(stderr, "���� ���� ���� \n");
    }
    else return stack[top--];
}

element peak()
{
    if (is_empty()){
        fprintf(stderr, "���� ���� ���� \n");
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