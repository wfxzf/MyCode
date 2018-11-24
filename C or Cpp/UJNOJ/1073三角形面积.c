#include<stdio.h>
#include<math.h>

int main()
{
    double a,b,c,s,S,temp;
    while(scanf("%lf %lf %lf",&a,&b,&c)!=EOF)
    {
        if(a+b>c&&a+c>b&&b+c>a)
           {
               s = (a + b + c)/2;
               temp = s * (s - a) *(s - b) * (s - c);
               S = sqrt(temp);
               printf("%.2lf\n",S);
           }
        else if(a==0&&b==0&&c==0)
            break;
        else
                printf("NO\n");
    }
}
