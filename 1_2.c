#include<stdio.h>

int main(){
    char cvalue = 'a';
    int ivalue = 10;
    long lvalue = 201;
    double dvalue = 3.14;

    char* cp = &cvalue;
    int* ip = &ivalue;
    long* lp = &lvalue;
    double* dp = &dvalue;

    printf("char의 메모리 크기: %d \n int의 메모리 크기: %d \n long의 메모리 크기: %d \n double의 메모리 크기: %d \n\n",
        sizeof(char), sizeof(int), sizeof(long), sizeof(double));
    


}