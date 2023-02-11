#include<stdio.h>
void main()
{
    int a,b;
    printf("Enter two integer   ");
    scanf("%d%d",&a,&b);
    int rem;
    rem=b%a;
    if(rem==0)
        printf("a is the factor of b");
    else
        printf("a is not the factor of b");
}
