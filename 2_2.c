#include<stdio.h>

int main()
{
    int array[5] = {10, 11, 12, 13 ,14};

    for(int i = 0; i<5; i++)
    {
        printf("array[%d]�� �ּҰ��� %p \n", i, &array[i]);
        printf("array + %d�� �ּҰ��� %p \n", i, array + i);
    }

    printf("\n");

    for(int i = 0; i<5; i++)
    {
        printf("array[%d]�� ����� ���� %d \n", i, array[i]);
        printf("*(array + %d)�� ����� ���� %d \n", i, *(array + i));
    }
}