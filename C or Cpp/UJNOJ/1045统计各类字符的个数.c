#include<stdio.h>
int main()
{   
   char i;
   int d=0,x=0,k=0,s=0,q=0;
   while(1)
   {
	   scanf("%c",&i);
	   if(i=='\n')
		   break;
	   else if(i>='A'&&i<='Z')
          d++;
	   else if(i>='a'&&i<='z')
		   x++;
	   else if(i==' ')
	       k++;
	   else if(i<='9'&&i>='0')
           s++;
	   else
		   q++;
   }
printf("%d %d %d %d %d",d,x,k,s,q);

}