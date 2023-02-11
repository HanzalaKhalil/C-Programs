#include<stdio.h>
void main()
{
    float disc,d_Price,rate,TB;
    printf("Enter total bill: ");
    scanf("%f",&TB);
    if(TB>=10000)
        {
            rate=50;
        }
    else if(TB>=5000)
        {
            rate=35;
        }
    else if(TB>=2500)
        {
            rate=20;
        }
    else if(TB>=1000)
        {
            rate=10;
        }
    else
        rate=0;
    disc=rate/100.0*(TB);
    d_Price=TB-disc;
    printf("\nDiscount= %.2f \nDiscounted price= %.2f",disc,d_Price);
}
