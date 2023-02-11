#include<stdio.h>
void main()
{
    int BS,OS,WHOE,OHOE,TS;
    int P_rate=200,O_rate=300;
    printf("Enter working and overtime hours\n");
    scanf("%d%d",&WHOE,&OHOE);
    BS=WHOE*P_rate;
    OS=OHOE*O_rate;
    TS=BS+OS;
    printf("Total salary=%d",TS);
}
