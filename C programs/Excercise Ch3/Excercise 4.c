#include<stdio.h>
void main()
{
    float OP,SP;
    printf("Enter Original Price: ");
    scanf("%f",&OP);
    printf("Enter Sale price: ");
    scanf("%f",&SP);
    if(SP>OP)
    {
        printf("Sold on profit\nProfit ");
    }
    else
    {
        printf("Sold on loss\nLoss ");
    }
    float PLP;
    PLP=(SP/OP)*100.0;
    printf("Percentage= %.2f",PLP);
}
