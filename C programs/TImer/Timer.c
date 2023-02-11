/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <unistd.h>

void main()
{
    int temp;
    printf("Enter time in seconds: ");
    scanf("%d",&temp);
    for(int i=temp;i>0;i--)
    {
     sleep(1);
     printf("%d\n",i-1);
    }
    printf("\a");
}

