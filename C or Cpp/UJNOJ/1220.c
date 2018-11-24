#include<stdio.h>
int cou(char a[100]);
int main()
{
    int t;
    char a[100];
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        gets(a);
        printf("%d\n",cou(a));
    }
    return 0;
}
int cou(char a[100])
{
    int i,count=0;
    for(i=0;a[i]!='\0';i++)
    {
        if(a[i]>='0'&&a[i]<='9')
            count++;
    }
    return count;
}
