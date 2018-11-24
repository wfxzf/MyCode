#include<stdio.h>
int letter(char c);
int main()
{
    char a[100];
    int i,j,n;
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        gets(a);
        for(i=j=0;a[i]!='\0';i++)
        {
            if(letter(a[i])==1)
                a[j++]=a[i];
        }
        a[j]='\0';
        puts(a);
    }
    return 0;
}
int letter(char c)
{
    if(('a'<=c&&c<='z')||('A'<=c&&c<='Z'))
       return 1;
    return 0;
}
