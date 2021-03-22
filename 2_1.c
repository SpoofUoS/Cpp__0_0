#include<stdio.h>

int main()
{
    int arr[5];
    for(int i=0;i<5;i++)
    {
        arr[i] = i;
        printf("arr[%d] = %d \n", i, arr[i]);
    }
    printf("arr[5] = %d\n", arr[5]);
    printf("arr[6] = %d", arr[6]);
}