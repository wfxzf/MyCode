#include<stdio.h>  
int main()  
{  
   char x;  
   x=getchar();  
   if(x>=65&&x<=90||x>=97&&x<=122)  
       printf("alpha");  
   else if(x>=48&&x<=57)  
       printf("numeric");  
   else
       printf("other");  
return 0;  
}  
  
