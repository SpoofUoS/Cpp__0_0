#include <stdio.h>
#define SIZE 6   // �迭�� ũ��

void get_nums(int list[])
{
    for (int i = 0; i < SIZE; i++) scanf("%d", &list[i]);
}

int cal_sum(int list[])
{
    int sum = 0;
    for(int i = 0; i < SIZE; i++) sum += *(list + i); // i �� ���� 1�� ũ�⿡ �ش�
    return sum;
}

int main()
{
    int list[SIZE];
    get_nums(list);
    printf("sum: %d", cal_sum(list));
}