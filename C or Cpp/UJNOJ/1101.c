#include<stdio.h>
int main()
{
    int a[52],i,j,t,n,max,min,temp;
    scanf("%d",&t);
    while(t--)
    {   scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        min=max=a[0];
        j=0;
        for(i=0;i<n;i++)
        {
            if(min>a[i])
            {
                min=a[i];
                j=i;
            }
        }
            temp=a[j];
            a[j]=a[0];
            a[0]=temp;
        for(i=1;i<n;i++)
        {
            if(a[i]>max)
            {
                max=a[i];
                j=i;
            }
        }
            temp=a[j];
            a[j]=a[n-1];
            a[n-1]=temp;
        for(i=0;i<n-1;i++)
            printf("%d ",a[i]);
        printf("%d\n",a[n-1]);
    }
 
return 0;
}