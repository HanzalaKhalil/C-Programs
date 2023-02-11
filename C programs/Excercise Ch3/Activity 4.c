#include<stdio.h>
void main()
{
    float per;
    printf("Enter percentage of intermediate marks: ");
    scanf("%f",&per);
    if(per>80)
    {
        printf("Eligible of BSSE program");
    }
    else if(per>70)
    {
        printf("Eligible of BSCS program");
    }
    else if(per>60)
    {
        printf("Eligible of BSIT program");
    }
}
