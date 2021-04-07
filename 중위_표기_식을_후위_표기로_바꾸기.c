#include<stdio.h>           // ���� �����ؾ� �� 
#include<stdlib.h>
#include<string.h>

#define MAX_STACK_SIZE 100

typedef char element;
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

element peek(StackType *s) // ��ũ �Լ�
{
    if (is_empty(s)) {
        fprintf(stderr, "���� ���� ����\n");
        exit(1);
    }
    else return s->data[s->top];
}

int prec(char op)   // �������� �켱���� ��ȯ.
{
    switch (op)
    {
    case '(': case ')': return 0;
    case '+': case '-': return 1;
    case '*': case '/': return 2;
    }
    return -1;
}

void infix_to_postfix(char exp[])
{
    int i = 0;
    char ch, top_op;
    int len = strlen(exp);
    StackType s;

    init_stack(&s);                // ���� �ʱ�ȭ

    for (i = 0; i<len; i++)
    {
        ch = exp[i];
        switch (ch)
        {
        case '+': case '-': case '*': case '/': // ������
            // ���ÿ� �ִ� �������� �켱������ �� ũ�ų� ������ ���
            while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
                printf("%c", pop(&s));
            push(&s, ch);
            break;
        case '(':   // ���� ��ȣ
            push(&s, ch);
            break;
        case ')':   // ������ ��ȣ
            top_op != pop(&s);
            while (top_op != '(') {     // ���� ��ȣ�� ���� �� ���� ��� 
                printf("%c", top_op);
                top_op = pop(&s);
            }
            break;
        default:
            printf("%c", ch);
            break;
        }
    }
    while (!is_empty(&s)) printf("%c", pop(&s));
}

int main()
{
    char *s = "(2+3)*4+9";
    printf("����ǥ�ü���: %s \n", s);
    printf("����ǥ�����: ");
    infix_to_postfix(s);
    printf("\n");
}






