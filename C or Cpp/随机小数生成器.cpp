#include <iostream>
#include<stdlib.h>
#include<time.h>
#include<iomanip>
using namespace std;


int main()
{
    /*
    int N=999999999,x;
    double num[50];                 //num为存储随机产生且精度为小数点后7位的小数的数组
    srand(time(NULL));              //设置随机数种子，使每次产生的随机序列不同精度为小数点后4位
	for (int i=0;i<50;i++)
	{
	    x=rand();
		num[i]=(x*x)%(N+1)/(double)(N+1);
		cout<<num[i]<<endl;
	}
*/



    int N=8999999,x;
    double num[50];                 //num为存储随机产生且精度为小数点后7位的小数的数组
    srand(time(NULL));              //设置随机数种子，使每次产生的随机序列不同精度为小数点后4位
	for (int i=0;i<50;i++)
	{
	    x=rand();
		num[i]=((x*x)%N+1000000)/(double)10000000;
		cout<<fixed<<setprecision(7)<<num[i]<<endl;
	}
}
