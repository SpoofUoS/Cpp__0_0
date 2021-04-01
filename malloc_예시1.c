#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define SIZE 10 // 배열 크기 저장

int main()
{
    int *p;

    p = (int *)malloc(SIZE * sizeof(int));
    if (p == NULL) {
        fprintf(stderr, "NULL.\n");
        exit(1);
    }

    for (int i = 0; i<SIZE; i++) p[i] = i;
    for (int i = 0; i<SIZE; i++) printf("%d ", p[i]);
}