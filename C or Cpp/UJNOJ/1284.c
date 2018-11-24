#include<stdio.h>
#include<string.h>
char zhuan(char ch);
int main()
{
    char a[100];
    int up=0,lw=0,nu=0,ot=0,sp=0,i;
    gets(a);
    for(i=0;a[i];i++)
    {

        if(a[i]>='A'&&a[i]<='Z')
         up++;

        else if(a[i]>='a'&&a[i]<='z')
        lw++;
         else if(a[i]>='0'&&a[i]<='9')
            nu++;
         else if(a[i]==' ')
            sp++;
         else
            ot++;
    }
    printf("%d %d %d %d %d",up,lw,nu,sp,ot);
return 0;
}
