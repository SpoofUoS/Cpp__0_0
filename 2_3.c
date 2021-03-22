#include<stdio.h>

int main(){
    int array[5] = {10, 11, 12, 13, 14, 15};
    int* parray = array;
    int i;

    printf("array의 주소값: %p \n", array);
    printf("parray의 주소값: %p \n", parray);

    for(i = 0; i < 5; i++){
        printf("%d \n", *(parray + i));  //printf("%d \n", *(array + i)); 도 가능
    }
    printf("\nparray의 주소값 %p \n", parray);

    for(i=0;i<5;i++){
        printf("%d \n", *(parray ++)); // printf("%d \n", *(array ++)); 는 오류 발생
    }
    printf("\nparray의 주소값 %p \n", parray);
}