#include <iostream>
#include <iomanip>
#include<cstdio>
#include<cstdlib>
using namespace std;
//#define matrixline 4

class relation
{
public:
    relation(int m);
    void input();
    void output();
    bool reflexivity();    //自反，反自反
    bool symmetry();   //对称，反对称
    bool transitivity();  //传递性
    void reflexivityclosure();    //自反闭包
    void symmetryclosure();   //对称闭包
    void transitivityclosure();  //传递闭包
    void adjacency_matrix();
    void reachable_matrix();
    void incidence_matrix();
    void distance_matrix();
private:
   // int matrix[matrixline][matrixline];

   int **matrix;
   int matrixline;
};

relation::relation(int m)
{
    int i,j;  //循环变量
    matrix=new int*[m];
    for(i=0;i<m;i++)
        matrix[i]=new int[m];
    matrixline=m;
    for(i=0;i<matrixline;i++)
        for(j=0;j<matrixline;j++)
            matrix[i][j]=0;
}

void matrix_multiplication(int **matrix1,int **matrix2,int **goal_matrix,int n)//矩阵相乘
{
	int i,j,m;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			goal_matrix[i][j]=0;
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			for(m=0;m<n;m++)
			{
					goal_matrix[i][j]+=matrix1[i][m]*matrix2[m][j];
			}
		}
	}
}

void relation::input()
{
    int a,b; //字符转换数字型
    char ca,cb;//字符型输入
    char c; //吸收多余字符
    cout<<"请输入有序对,以正整数表示，以<*,*> 结束"<<endl;
    while(1)
    {
        cin>>c>>ca>>c>>cb>>c;
        if (ca>='0'&&ca<='9')
            a=ca-'0';
        if (ca>='a'&&ca<='z')
            a=ca-'a'+1;
        if (ca>='A'&&ca<='Z')
            a=ca-'A'+1;
        if (cb>='0'&&cb<='9')
            b=cb-'0';
        if (cb>='a'&&cb<='z')
            b=cb-'a'+1;;
        if (cb>='A'&&cb<='Z')
            b=cb-'A'+1;
        if(ca=='*'&&cb=='*')
            break;
        if (a<=0||b<=0)
        {
            cout<<"错误，请继续输入"<<endl;
            continue;
        }
        matrix[a-1][b-1]=1;
    }
}

void relation::output()
{
    int i,j;
    for(i=0;i<matrixline;i++)
        {
            for(j=0;j<matrixline;j++)
                cout<<matrix[i][j]<<"   ";
            cout<<endl;
        }
}


bool relation::reflexivity()    //自反性
{
    int i,j=0,k=0;
    for(i=0;i<matrixline;i++)
    {
        if (matrix[i][i]!=1)
            j=1;
        if (matrix[i][i]!=0)
            k=1;
    }
    if (j==0)
    {
        cout<<"关系具有自反性"<<endl;
        return true;
    }
return false;
}

bool relation::symmetry()    //对称性
{
    int i,j,k=0,l=0;
    for(i=0;i<matrixline;i++)
        for(j=0;j<matrixline;j++)
            if(matrix[i][j]!=matrix[j][i])
                k=1;
    if (k==0)
        {cout<<"关系具有对称性"<<endl;return true;}
return false;
}

bool relation::transitivity() //传递性
{
    int i,j,k,l=2;
    for(i=0;i<matrixline;i++)
    {
        for(j=0;j<matrixline;j++)
        {
            for(k=0;k<matrixline;k++)
                {
                    if(matrix[i][j]==1&&matrix[j][k]==1)
                        {
                            if(matrix[i][k]==1)
                            l=0;
                            else
                            {
                                l=1;break;
                            }
                        }
                }
            if(l==1) break;
        }
        if(l==1) break;
    }
    if(l==0)
        {cout<<"关系具有传递性"<<endl;return true;}
return false;
}


void relation::reflexivityclosure()   //自反闭包
{
    int i,j;
    //int temp[matrixline][matrixline];
    int **temp;
    temp=new int*[matrixline];
    for(i=0;i<matrixline;i++)
        temp[i]=new int[matrixline];

    for(i=0;i<matrixline;i++)
        for(j=0;j<matrixline;j++)
            temp[i][j]=matrix[i][j];
    for(i=0;i<matrixline;i++)
        temp[i][i]=1;

    if(reflexivity()==true)
     for(i=0;i<matrixline;i++)
       for(j=0;j<matrixline;j++)
         temp[j][i]=matrix[j][i];

    for(i=0;i<matrixline;i++)
        {
            for(j=0;j<matrixline;j++)

                cout<<temp[i][j]<<"   ";
            cout<<endl;
        }
}

void relation::symmetryclosure()   //对称闭包
{

    int i,j;
    //int temp[matrixline][matrixline];
    int **temp;
    temp=new int*[matrixline];
    for(i=0;i<matrixline;i++)
        temp[i]=new int[matrixline];
    for(i=0;i<matrixline;i++)
        for(j=0;j<matrixline;j++)
            temp[i][j]=matrix[i][j];
    for(i=0;i<matrixline;i++)
        for(j=0;j<matrixline;j++)
            if(temp[i][j]==1)
                temp[j][i]=1;
    if(symmetry()==true)
     for(i=0;i<matrixline;i++)
       for(j=0;j<matrixline;j++)
         temp[j][i]=matrix[j][i];
    for(i=0;i<matrixline;i++)
        {
            for(j=0;j<matrixline;j++)
                cout<<temp[i][j]<<"   ";
            cout<<endl;
        }
}
void relation::transitivityclosure()  //传递闭包
{
    int i,j,k;
    int **temp;
    temp=new int*[matrixline];
    for(i=0;i<matrixline;i++)
        temp[i]=new int[matrixline];
    for(i=0;i<matrixline;i++)
        for(j=0;j<matrixline;j++)
            temp[i][j]=matrix[i][j];
    for(i=0;i<matrixline;i++)
    {
        for(j=0;j<matrixline;j++)
        {
            if(temp[j][i])
            {

                for(k=0;k<matrixline;k++)
                {
                   temp[j][k]=(temp[j][k] | temp[i][k]);
                }
            }
        }
    }

    if(transitivity()==true)
     for(i=0;i<matrixline;i++)
       for(j=0;j<matrixline;j++)
         temp[j][i]=matrix[j][i];
    for(i=0;i<matrixline;i++)
        {
            for(j=0;j<matrixline;j++)
                cout<<temp[i][j]<<"   ";
            cout<<endl;
        }
}
void relation::adjacency_matrix()    //邻接矩阵
{
    int i,j;
    int temp[matrixline][matrixline];
    for(i=0;i<matrixline;i++)
        for(j=0;j<matrixline;j++)
            temp[i][j]=matrix[i][j];

    for(i=0;i<matrixline;i++)
        {
        for(j=0;j<matrixline;j++)
            if(i==j)
                temp[i][j]=0;
        }

    for(i=0;i<matrixline;i++)
        {
            for(j=0;j<matrixline;j++)
                cout<<temp[i][j]<<"   ";
            cout<<endl;
        }
}
void relation::reachable_matrix()
{
    int i,j,k;
    int **temp;
    temp=new int*[matrixline];
    for(i=0;i<matrixline;i++)
        temp[i]=new int[matrixline];
    for(i=0;i<matrixline;i++)
        for(j=0;j<matrixline;j++)
            temp[i][j]=matrix[i][j];

    for(i=0;i<matrixline;i++)
    {
        for(j=0;j<matrixline;j++)
        {
            if(temp[j][i])
            {

                for(k=0;k<matrixline;k++)
                {
                   temp[j][k]=(temp[j][k] | temp[i][k]);

                   //----------利用定义--------------------
                   //if(temp[i][j]==1&&temp[j][k]==1)
                    //temp[i][k]=1;
                    //----------定义end'---------------------

                }
            }
        }
    }



     for(i=0;i<matrixline;i++)
        {
            for(j=0;j<matrixline;j++)
                cout<<temp[i][j]<<"   ";
            cout<<endl;
        }

}

void relation::distance_matrix()    //获得距离矩阵
{
	int i,j,m,n,distance_matrix[200][200];
	int ** check_matrix;
	int ** result_matrix;
	check_matrix=new int * [200];
	result_matrix=new int * [200];
	for(i=0;i<200;i++)
    {
        check_matrix[i]=new int[200];
	   result_matrix[i]=new int[200];
    }                                           //创建空矩阵


	for(i=0;i<matrixline;i++)
	{
		for(j=0;j<matrixline;j++)
		{
			distance_matrix[i][j]=matrix[i][j];
			result_matrix[i][j]=matrix[i][j];
		}
	}

	for(i=2;i<matrixline;i++)     //循环，求A^2  A^3 A^4~~~
	{
		matrix_multiplication(result_matrix,matrix,check_matrix,matrixline);
		for(m=0;m<matrixline;m++)
		{
			for(n=0;n<matrixline;n++)
			{
				if(distance_matrix[m][n]==0&&check_matrix[m][n]!=0)
				{
					distance_matrix[m][n]=i;
				}
			}
		}

		for(m=0;m<matrixline;m++)
		{
			for(n=0;n<matrixline;n++)
			{
				result_matrix[m][n]=check_matrix[m][n];
			}
		}
	}

	for(i=0;i<matrixline;i++)
        {
            for(j=0;j<matrixline;j++)
                if(distance_matrix[i][j]==0)
                    distance_matrix[i][j]=-1;
        }

	for(i=0;i<matrixline;i++)
        {
            for(j=0;j<matrixline;j++)
                if(i==j)
                    distance_matrix[i][j]=0;
        }
     for(i=0;i<matrixline;i++)
        {
            for(j=0;j<matrixline;j++)
                cout<<setw(3)<<distance_matrix[i][j]<<"   ";
            cout<<endl;
        }
}


void relation::incidence_matrix()  //关联矩阵
{
    int i,j,k=0,l[100],c[100];
    for(i=0;i<matrixline;i++)
        for(j=0;j<matrixline;j++)
            if(matrix[i][j]==1)
                {
                    l[k]=i;
                    c[k++]=j;
                }
    int temp[k][matrixline];
    for(i=0;i<k;i++)
        for(j=0;j<matrixline;j++)
            temp[i][j]=0;
    for(i=0;i<k;i++)
    {
        temp[i][l[i]]=1;
        temp[i][c[i]]=-1;
    }
    for(i=0;i<k;i++)
    {
        for(j=0;j<matrixline;j++)
            cout<<setw(3)<<temp[i][j]<<"   ";
        cout<<endl;
    }

}
int inp(int * matrixline)  //判定元素个数
{
    int i,j=0;
    char s[200];
    for(i=0;i<200;i++) s[i]='\0';

    int ds[200];
    for(i=0;i<200;i++) ds[i]=0;

    cout<<"请输入集合元素"<<endl;
    cin.getline(s,500,'\n');
    for(i=0;i<200;i++)
    {
        if(s[i]<='9'&&s[i]>='0')
                ds[j++]=s[i]-'0';
        else if(s[i]<='z'&&s[i]>='a')
                ds[j++]=s[i]-'a'+1;
        else if(s[i]<='Z'&&s[i]>='A')
                 ds[j++]=s[i]-'A'+1;
    }

    for(i=0;i<200;i++)
        if(*matrixline<ds[i])
           *matrixline=ds[i];

    cout<<*matrixline;
}


int main()
{
    int matrixline=0,i=0,j=0,judge=0;
    inp(&matrixline);
    relation A(matrixline);
    A.input();
    A.output();
    A.reflexivity();
    A.symmetry();
    A.transitivity();
    while(1)
    {
        cout<<"输入 1 for 求自反闭包，2 for 对称闭包，3 for 传递闭包,4 for 邻接矩阵,5 for 可达矩阵，6 for 距离矩阵，7 for 关联矩阵,0 for 退出";
        cin>>judge;
        if(judge==1)
        {
            cout<<"---------------------自反闭包---------------------"<<endl;
            A.reflexivityclosure();
            cout<<"---------------------自反闭包end---------------------"<<endl<<endl;
        }
        else if(judge==2)
        {
            cout<<"---------------------对称闭包---------------------"<<endl;
            A.symmetryclosure();
            cout<<"---------------------对称闭包end---------------------"<<endl<<endl;
        }

        else if(judge==3)
        {
        cout<<"---------------------传递闭包---------------------"<<endl;
        A.transitivityclosure();
        cout<<"---------------------传递闭包end---------------------"<<endl<<endl;
        }
        else if(judge==4)
        {
        cout<<"---------------------邻接矩阵---------------------"<<endl;
        A.adjacency_matrix();
        cout<<"---------------------邻接矩阵end---------------------"<<endl<<endl;
        }
        else if(judge == 5)
        {
        cout<<"---------------------可达矩阵---------------------"<<endl;
        A.reachable_matrix();
        cout<<"---------------------可达矩阵end---------------------"<<endl<<endl;
        }
        else if(judge==6)
        {
        cout<<"---------------------距离矩阵---------------------"<<endl;
        A.distance_matrix();
        cout<<"---------------------距离矩阵end---------------------"<<endl<<endl;
        }
        else if(judge==7)
        {
        cout<<"---------------------关联矩阵---------------------"<<endl;
        A.incidence_matrix();
        cout<<"---------------------关联矩阵end---------------------"<<endl<<endl;
        }
        else if(judge==0)
            break;
        else
        {
            cout<<"输入有误，请重试"<<endl;
            continue;
        }
    }
return 0;
}


//{1,2,3,4} <1,2> <2,1> <2,3> <3,4> <*,*>

//{a,b,c,d}      <a,b> <b,a> <b,c> <c,d> <*,*>

// {1,2,3,4,5}    <1,2> <2,3> <2,4> <3,1> <3,2> <3,4> <3,5> <4,1> <4,5> <*,*>
