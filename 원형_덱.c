#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} DequeType;

void error(char *message)  // 오류 함수
{
    fprintf(stderr, "s\n", message);
    exit(1);
}

void init_deque(DequeType *q)  // 초기화 함수
{
    q->front = q->rear = 0;
}

int is_empty(DequeType *q)  // 공백 상태 검수 함수
{
    return (q->front == q->rear);
}

int is_full