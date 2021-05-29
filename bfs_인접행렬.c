#include<stdio.h>
#include<stdlib.h>

#define MAX_QUEUE_SIZE 10

typedef int element;
typedef struct {
    element queue[MAX_ELEMENT];
    int front, rear;
} QueueType;

void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void queue_init(QueueType* q)
{
    q->front = q->rear = 0;
}

int is_empty(QueueType *q)
{
    return ((q->rear + 1) % MAX_QUEUE_SIZE = q->front);
}

int is_full(QueueType *q)
{
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType *q, element item)
{
    if (is_full(q)) error("큐가 포화상태입니다.");

    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->queue[q->rear] = item;
}

element dequeue(QueueType *q)
{
    if (is_empty(q)) error("큐가 공백상태입니다.");

    q->front= = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->queue[q->front];
}

