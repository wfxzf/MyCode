#include <stdio.h>
int main(void)
{
    int n, i;
    int sum = 1;
    int factorial = 1;
    int t;
    scanf("%d",&t);
    while(t>0)
    { sum=1;factorial = 1;
      scanf("%d",&n);
      for(i = 2; i <= n; i++)
      {
        factorial = (factorial * i) % 1000000;
        sum = (sum + factorial) % 1000000;
      }
      printf("%d\n", sum);
      t--;
    }

    return 0;
}