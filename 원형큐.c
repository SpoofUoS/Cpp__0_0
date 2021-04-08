#include<stdio.h>
#include<stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

void error(char *message)
{
    fprintf(stderr, "&s\n", message);
    exit(1);
}

void init_queue(QueueType *q) // 큐 호기화 함수 
{
    q->front = q->rear = 0;
}

int is_empty(QueueType *q) // 공백 상태 검출 함수
{
    return (q->front == q->rear);
}

int is_full(QueueType *q) // 포화 상태 검출 함수
{
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void queue_print(QueueType *q)
{
    printf("Queue(front = %d, rear = %d) = ", q->front, q->rear);
    if (!is_empty(q)) {
        int i = q->front;
        
    }
}

void enqueue(QueueType *q, element item)
{
    if (is_full(q)) error("큐가 포화 상태 입니다.");
    q->rear = (q->rear+1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}