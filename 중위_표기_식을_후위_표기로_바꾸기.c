#include<stdio.h>           // 오류 수정해야 함 
#include<stdlib.h>
#include<string.h>

#define MAX_STACK_SIZE 100

typedef char element;
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

element peek(StackType *s) // 피크 함수
{
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return s->data[s->top];
}

int prec(char op)   // 연산자의 우선순위 반환.
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

    init_stack(&s);                // 스택 초기화

    for (i = 0; i<len; i++)
    {
        ch = exp[i];
        switch (ch)
        {
        case '+': case '-': case '*': case '/': // 연산자
            // 스택에 있는 연산자의 우선순위가 더 크거나 같으면 출력
            while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
                printf("%c", pop(&s));
            push(&s, ch);
            break;
        case '(':   // 왼쪽 괄호
            push(&s, ch);
            break;
        case ')':   // 오른쪽 괄호
            top_op != pop(&s);
            while (top_op != '(') {     // 왼쪽 괄호를 만날 때 까지 출력 
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
    printf("중위표시수식: %s \n", s);
    printf("후위표기수식: ");
    infix_to_postfix(s);
    printf("\n");
}






