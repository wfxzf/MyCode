#include<stdio.h>
int main()
{
	char a[100],ch;
	int i,j;
;	while(gets(a)!=NULL)
	{
        ch=getchar();
        getchar();
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]==ch)
		  for(j=i;a[j-1]!='\0';j++)
		    {
		    	a[j]=a[j+1];

			 }
		if(a[i]==ch)
	        i--;
	}
	puts(a);
}
return 0;
}
