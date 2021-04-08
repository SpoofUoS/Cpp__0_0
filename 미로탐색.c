#include<stdio.h>                    // 문제가 있음
#include<stdlib.h>
#include<string.h>

#define MAZE_SIZE 6
#define MAX_STACK_SIZE 100

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

char maze[MAZE_SIZE][MAZE_SIZE] = {
    {'1','1','1','1','1','1'},
    {'e','0','1','0','0','1'},
    {'1','0','0','0','1','1'},
    {'1','0','1','0','1','1'},
    {'1','0','1','0','0','x'},
    {'1','1','1','1','1','1'},
};

void push_loc(StackType *s, int r, int c)    // 위치를 스택에 삽입 
{
    if (r<0 || c<0) return;
    if (maze[r][c] != '1' && maze[r][c] != '.') {
        element tmp;
        tmp.r = r;
        tmp.c = c;
        push(s, tmp);
    }
}

void maze_print(char maze[MAZE_SIZE][MAZE_SIZE])
{
    printf("\n");
    for (int r= 0; r < MAZE_SIZE; r++){
        for (int c = 0; c < MAZE_SIZE; c++) {
            printf("%c", maze[r][c]);
        }
        printf("\n");
    }
}

int main()
{
    int r, c;
    StackType s;

    init_stack(&s);
    here = entry;
    while (maze[here.c][here.r] != 'x') {
        r = here.r;
        c = here.c;
        maze[r][c] = '.';
        maze_print(maze);
        push_loc(&s, r-1, c);
        push_loc(&s, r+1, c);
        push_loc(&s, r, c-1);
        push_loc(&s, r, c+1);
        if (is_empty(&s)) {
            printf("실패\n");
            return;
        }
        else here = pop(&s);
    }
    printf("성공\n");
    return 0;
}