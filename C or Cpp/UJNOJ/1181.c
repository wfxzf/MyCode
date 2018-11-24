#include<stdio.h>    
int main()    
{    
    int i,n,m;    
    while(scanf("%d",&n)!=EOF)    
    {    
        m=1;    
        for(i=1;i<=n;i++)    
        {    
            m+=i;    
        }    
        printf("%d\n",m);    
    }    
}  