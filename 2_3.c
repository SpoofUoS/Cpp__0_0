#include<stdio.h>

int main(){
    int array[5] = {10, 11, 12, 13, 14, 15};
    int* parray = array;
    int i;

    printf("array�� �ּҰ�: %p \n", array);
    printf("parray�� �ּҰ�: %p \n", parray);

    for(i = 0; i < 5; i++){
        printf("%d \n", *(parray + i));  //printf("%d \n", *(array + i)); �� ����
    }
    printf("\nparray�� �ּҰ� %p \n", parray);

    for(i=0;i<5;i++){
        printf("%d \n", *(parray ++)); // printf("%d \n", *(array ++)); �� ���� �߻�
    }
    printf("\nparray�� �ּҰ� %p \n", parray);
}