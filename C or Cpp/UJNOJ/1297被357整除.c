#include <stdio.h>
  int main()
{
  int a;
  scanf("%d",&a);
    if(a%15==0)
    printf("������ͬʱ��3��5����");
    else if((a%3)==0&&(a%5)!=0)
    printf("�����ܱ�����һ��������");
    else if((a%5)==0&&(a%3)!=0)
    printf("�����ܱ�����һ��������");
    else
    printf("�����Ȳ��ܱ�3����Ҳ���ܱ�5����");
   return 0;
}
 