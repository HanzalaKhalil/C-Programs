#include<stdio.h>
void main()
{
    for(int i = 1;i <= 7;i++)
    {
        int fact = 0;
        for(int j = i;j > 0;j--)
        {
            fact = fact + j;
        }
        printf("%d",fact);
    }
}
