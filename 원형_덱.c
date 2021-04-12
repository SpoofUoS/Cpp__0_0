#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} DequeType;

void error(char *message)  // ���� �Լ�
{
    fprintf(stderr, "s\n", message);
    exit(1);
}

void init_deque(DequeType *q)  // �ʱ�ȭ �Լ�
{
    q->front = q->rear = 0;
}

int is_empty(DequeType *q)  // ���� ���� �˼� �Լ�
{
    return (q->front == q->rear);
}

int is_full