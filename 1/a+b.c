#include<stdio.h>
int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    __asm__(
            "add %0,%1"
            :"=r"(b)
            :"r"(a),"r"(b)
           );
    printf("%d",b);
}
