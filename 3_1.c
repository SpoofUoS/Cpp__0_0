#include<stdio.h>

int main()
{
    int row, col;

    int score[3][4] = {{70,75,80,76}, {80,85,90,95}, {80,90,85,90}};
    for(row=0;row<3;row++)
    {
        for(col=0;col<4;col++)
        {
            printf(" %2d", score[row][col]);
        }
        printf("\n");
    }
}
