#include <stdio.h>

int delay(int);
void main()
{
     int length,temp=1,limit=1;
     printf("Enter length of the side of diamond: ");
     scanf("%d",&length);
     for(int i=length;i>=1;i--)
     {
          delay(100000000);
          for(int j=1;j<i;j++)
          {
               printf(" ");
          }
          for(int k=1;k<=1;k++)
          {     
               printf("*");
          }
          for(int l=length;l>i;l--)
          {     
               printf(" ");
          }
          for(int m=length-1;m>i;m--)
          {     
               printf(" "); 
          }
          if(i<length)
          {
               printf("*");
          }
          printf("\n");
          if(i<=temp && limit<=length )
          {
               i=i+2;
               temp=temp+2;
               limit++;
          }
          if(limit==length+1)
          {
              i=0; 
          }
     }
     printf(" ");
}
int delay(int para){
     int temp;
     for(int i=1;i<=para;i++)
     {
          temp=temp*2;
     }
     return 0;
}





