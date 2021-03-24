#include<stdio.h>

int main(){
    int array[3][4];
    int (*ptr)[4] = array;
    int i,j;

    printf("array=%p \n", array);
    printf("array[0] = %p \n", array[0]);
    printf("array[1] = %p \n", array[1]);
    printf("array[2] = %p \n\n", array[2]);

    printf("ptr = %p \n", ptr);
    printf("ptr + 1 = %p \n", ptr + 1);
    printf("prt + 2 = %p \n\n", ptr + 2);

    printf("array = %p", array);
    printf("array + 1 = %p \n", array + 1);
    printf("array + 2 = %p \n\n", array + 2);

    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
            printf("array [%d][%d] = %p\n", i, j, &array[i][j]);
        }
    }
}