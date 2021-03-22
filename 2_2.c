#include<stdio.h>

int main()
{
    int array[5] = {10, 11, 12, 13 ,14};

    for(int i = 0; i<5; i++)
    {
        printf("array[%d]의 주소값은 %p \n", i, &array[i]);
        printf("array + %d의 주소값은 %p \n", i, array + i);
    }

    printf("\n");

    for(int i = 0; i<5; i++)
    {
        printf("array[%d]에 저장된 값은 %d \n", i, array[i]);
        printf("*(array + %d)에 저장된 값은 %d \n", i, *(array + i));
    }
}