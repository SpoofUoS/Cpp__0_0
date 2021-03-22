#include<stdio.h>

int main()
{
    int num = 10;
    int* ptr;
    ptr = &num;

    printf("%d \n", num);
    printf("%d \n", *ptr);
    printf("%p \n", &num);
    printf("%p \n", ptr);
    printf("%p \n", &ptr);
}