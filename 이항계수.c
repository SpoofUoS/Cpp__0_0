#include <stdio.h>

int binomical_coefficient(int n, int k)
{
    if (k == 0 || k == n) return 1;
    else return (binomical_coefficient(n-1,k-1)+binomical_coefficient(n-1,k));
}

int main()
{
    int n = 5; int k = 2;
    printf("%d",binomical_coefficient(5,2));
}