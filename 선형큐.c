#include<stdio.h>
#include<stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
} Queue_type;

void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_queue(Queue_type *q)
{
    q->rear = -1;
    q->front = -1;
}

void queue_print(Queue_type *q)
{
    for (int i = 0; i < MAX_QUEUE_SIZE; i++){
        if (i <= q->front || i > q->rear) printf(" | ");
        else printf("%d | ", q->data[i]);
    }
    printf("\n");
}

int is_full(Queue_type *q)
{
    if (q->rear == MAX_QUEUE_SIZE - 1) return 1;
    else return 0;
}

int is_empty(Queue_type *q)
{
    if (q->rear == q->rear) return 1;
    else return 0;
}

void enqueue(Queue_type *q, element item)
{
    if (is_full(q)) {
        error("큐가 포화상태입니다.");
        return;
    }
    q->data[++(q->rear)] = item;
}

int dequeue(Queue_type *q)
{
    if (is_empty(q)) {
        error("큐가 공백상태입니다.");
        return -1;
    }
    int item = q->data[++(q->front)];
    return item;
}

int main()
{
    int item = 0;
    Queue_type q;

    init_queue(&q);

    enqueue(&q, 10); queue_print(&q);
    enqueue(&q, 20); queue_print(&q);
    enqueue(&q, 30); queue_print(&q);

    item = dequeue(&q); queue_print(&q);
    item = dequeue(&q); queue_print(&q);
    item = dequeue(&q); queue_print(&q);

}