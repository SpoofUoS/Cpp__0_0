#include <stdio.h>

int binomical_coefficient(int n, int k)
{
    if (k == 0 || k == n) return 1;
    else return (binomical_coefficient(n-1,k-1)+binomical_coefficient(n-1,k));
}

int main()
{
    int n = 39; int k = 6;
    printf("%d",binomical_coefficient(n,k));
}