#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,i,j=0,temp,b[10];
    scanf("%d",&a);
    for(i=a;i>2000;i-=12)
        {b[j]=i;j++;}
    for(i=a+12;i<2100;i+=12)
        {b[j]=i;j++;}
        for(i=0;i<8;i++)
             for(j=0;j<8-i-1;j++)
        {
            if(b[j]>b[j+1])
            {
                temp=b[j];
                b[j]=b[j+1];
                b[j+1]=temp;
            }
        }
        for(i=0;i<7;i++)
            printf("%d ",b[i]);
        printf("%d",b[i]);
    return 0;
}