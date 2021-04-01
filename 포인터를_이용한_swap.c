#include <stdio.h>

void swap(int *px, int*py)
{
    int tmp;
    tmp = *px;
    *px = *py;
    *py = tmp;
}
int main()
{
    int a = 1; int b = 2;
    printf("before a: %d, b: %d \n",a ,b);
    swap(&a, &b);
    printf("after  a: %d, b: %d",a, b);
}