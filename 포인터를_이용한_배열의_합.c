#include <stdio.h>
#define SIZE 6   // 배열의 크기

void get_nums(int list[])
{
    for (int i = 0; i < SIZE; i++) scanf("%d", &list[i]);
}

int cal_sum(int list[])
{
    int sum = 0;
    for(int i = 0; i < SIZE; i++) sum += *(list + i); // i 가 정수 1개 크기에 해당
    return sum;
}

int main()
{
    int list[SIZE];
    get_nums(list);
    printf("sum: %d", cal_sum(list));
}