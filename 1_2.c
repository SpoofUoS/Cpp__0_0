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

    printf("char�� �޸� ũ��: %d \n int�� �޸� ũ��: %d \n long�� �޸� ũ��: %d \n double�� �޸� ũ��: %d \n\n",
        sizeof(char), sizeof(int), sizeof(long), sizeof(double));
    


}