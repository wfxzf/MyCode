#include<stdio.h>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include <malloc.h>
#include<conio.h>
#include<windows.h>

#define inf 50000
#define SC 50
using namespace std;

const int Max_n=1000;

int n,u,v;
int ans[SC];
int vis[SC] = {0};
int str[20];

int dist[SC];
int c[SC][SC];
int prev[SC];


int snum = 12;

typedef struct {
	char name[Max_n];
	char number[Max_n];
	char Introduce[Max_n];
}DataType;

typedef struct {
	int num;
	DataType data;
}Scenic;

typedef struct {
	Scenic Scenic[SC];
	int D[SC][SC];
}Map;

Map G;
int D[SC][SC];


void InitMes(){
	int count=1;
	G.Scenic[count].num=1;
	strcpy(G.Scenic[count].data.number,"V1");
	strcpy(G.Scenic[count].data.name,"新西门");
	strcpy(G.Scenic[count].data.Introduce,"学校大门，放假时人流量最大");
	count++;
	G.Scenic[count].num=2;
	strcpy(G.Scenic[count].data.number,"V2");
	strcpy(G.Scenic[count].data.name,"主体育场");
	strcpy(G.Scenic[count].data.Introduce,"这里有各种运动的场地");
	count++;
	G.Scenic[count].num=3;
	strcpy(G.Scenic[count].data.number,"V3");
	strcpy(G.Scenic[count].data.name,"南苑体育场");
	strcpy(G.Scenic[count].data.Introduce,"自由锻炼的好去处");
	count++;
	G.Scenic[count].num=4;
	strcpy(G.Scenic[count].data.number,"V4");
	strcpy(G.Scenic[count].data.name,"绿泉广场");
	strcpy(G.Scenic[count].data.Introduce,"钟楼与大喷泉");
	count++;
	G.Scenic[count].num=5;
	strcpy(G.Scenic[count].data.number,"V5");
	strcpy(G.Scenic[count].data.name,"滋兰苑");
	strcpy(G.Scenic[count].data.Introduce,"一年四季百花齐放，适宜游玩,拍照!");
	count++;
	G.Scenic[count].num=6;
	strcpy(G.Scenic[count].data.number,"V6");
	strcpy(G.Scenic[count].data.name,"第八食堂");
	strcpy(G.Scenic[count].data.Introduce,"靠近主要的教学楼，三楼环境十分好");
	count++;
	G.Scenic[count].num=7;
	strcpy(G.Scenic[count].data.number,"V7");
	strcpy(G.Scenic[count].data.name,"马武寨山");
	strcpy(G.Scenic[count].data.Introduce,"刚建好的山体公园，俯瞰整个学校");
	count++;
	G.Scenic[count].num=8;
	strcpy(G.Scenic[count].data.number,"V8");
	strcpy(G.Scenic[count].data.name,"十教");
	strcpy(G.Scenic[count].data.Introduce,"主要的教学凑，错综复杂，容易迷路");
	count++;
	G.Scenic[count].num=9;
	strcpy(G.Scenic[count].data.number,"V9");
	strcpy(G.Scenic[count].data.name,"十二教");
	strcpy(G.Scenic[count].data.Introduce,"信息学院所在地，可能是东半校最好的建筑");
	count++;
	G.Scenic[count].num=10;
	strcpy(G.Scenic[count].data.number,"V10");
	strcpy(G.Scenic[count].data.name,"图书馆");
	strcpy(G.Scenic[count].data.Introduce,"据说是山东最大的单体图书馆，学习氛围很浓厚");
	count++;
	G.Scenic[count].num=11;
	strcpy(G.Scenic[count].data.number,"V11");
	strcpy(G.Scenic[count].data.name,"升华广场");
	strcpy(G.Scenic[count].data.Introduce,"学校的地标");
	count++;
	G.Scenic[count].num=12;
	strcpy(G.Scenic[count].data.number,"V12");
	strcpy(G.Scenic[count].data.name,"逸夫楼");
	strcpy(G.Scenic[count].data.Introduce,"比较新的建筑，学校的最东边");
	count++;
	for(int i=1;i<=SC;i++){
		for(int j=1;j<=SC;j++){
			if(i==j){
				G.D[i][j]=0;
				D[i][j]=0;
			}else{
				G.D[i][j]=inf;
				D[i][j]=inf;
			}
		}
	}
	G.D[1][2]=230;
	G.D[1][3]=900;
	G.D[2][4]=300;
	G.D[3][4]=430;
	G.D[4][5]=490;
	G.D[4][6]=450;
	G.D[4][7]=640;
	G.D[6][8]=300;
	G.D[8][10]=100;
	G.D[9][10]=100;
	G.D[10][11]=100;
	G.D[9][12]=540;
	G.D[10][12]=680;

	G.D[2][1]=230;
	G.D[3][1]=900;
	G.D[4][2]=300;
	G.D[4][3]=430;
	G.D[5][4]=490;
	G.D[6][4]=450;
	G.D[7][4]=640;
	G.D[8][6]=300;
	G.D[10][8]=100;
	G.D[10][9]=100;
	G.D[11][10]=100;
	G.D[12][9]=540;
	G.D[13][10]=680;
}




void  ChangeMes(){
    getchar();
	printf("是否增加一个景点或路？s加景点，r加路，其他退出\n");
	char chose;
	scanf("%c",&chose);
	if(chose == 's')
    {
        char nnn[Max_n];
        char nam[Max_n];
        char intr[Max_n];
        snum++;
        printf("输入景点信息:\n");
        printf("输入景点代号：");
        scanf("%s",nnn);
        printf("输入景点名称：");
        scanf("%s",nam);
        printf("输入景点简介：");
        scanf("%s",intr);
        strcpy(G.Scenic[snum].data.number,nnn);
	    strcpy(G.Scenic[snum].data.name,nam);
        strcpy(G.Scenic[snum].data.Introduce,intr);
        G.D[snum][snum]=0;
    }
    else if (chose == 'r')
    {
        int a,b,c;
        printf("输入要加入的路，格式：起点 终点 距离");
            scanf("%d%d%d",&a,&b,&c);
            G.D[a][b]=c;
            G.D[b][a]=c;
    }
}

void ViewSpeMes(int i){
	printf("编号为%d的景点的信息为:\n",i);
	printf("---------------------------------------------\n");
	printf("景点代号:%s\n",G.Scenic[i].data.number);
	printf("景点名称:%s\n",G.Scenic[i].data.name);
	printf("景点简介:%s\n",G.Scenic[i].data.Introduce);
	printf("---------------------------------------------\n");
}

void ViewMes(){
	printf("请输入您要查看的景点信息的编号:");
	int chose;
	scanf("%d",&chose);
	ViewSpeMes(chose);
	printf("查询完毕!是否继续查询?(y/n)");
	char a;
	scanf(" %c",&a);
	if(a=='y'){
		printf("您选择了继续查询!\n");
		ViewMes();
	}
	printf("查询结束,Enter键进入主界面\n");
	system("pause");
	system("cls");
}


void dijksrra(int v)
{
    for(int i=1;i<snum+1;i++){
		for(int j=1;j<snum+1;j++){
			c[i][j]=G.D[i][j];
		}
	}

  int i,j;
  bool s[SC];
  for (i=1;i<=snum;i++)
  {
      dist[i]= c[v][i];
      s[i]=false;
      if(dist[i]>inf) prev[i] = 0;
      else prev[i] = v;
  }

  dist[v] = 0;
  s[v] = true;
  for(i=1;i<snum;i++)
  {
      int tmp = inf;
      int u = v;
      for(j=1;j<=snum;j++)
          if((!s[j])&&(dist[j]<tmp))
          {
              u=j;
              tmp = dist[j];
          }
      s[u]=1;
      for(j=1;j<=snum;j++)
          if((!s[j])&&c[u][j]<inf)
          {
            int newdist = dist[u]+c[u][j];
            if(newdist<dist[j])
            {
                dist[j] = newdist;
                prev[j] = u;
            }
          }
  }

}



void OutPath(int s,int e){
	int next=s;
	int pre = e;
	printf(">>路径为:\n");
    printf("%s<--",G.Scenic[e].data.name);
    pre = prev[e];
	do{
        next = pre;
		printf("%s<--",G.Scenic[pre].data.name);
		pre = prev[pre];
	}while(prev[next]!=s);
	printf("%s\n",G.Scenic[s].data.name);
}

void PrintPath(){

	printf("对照校园平面图,输入您当前所在景点及您要去的景点的编号:");
	int s,e;
	scanf("%d%d",&s,&e);
	dijksrra(s);
	if(s<=snum&&s>=0&&e<=snum&&e>=0){
		printf(">>%s到%s的最短路径长度为: %d\n",G.Scenic[s].data.name,G.Scenic[e].data.name,dist[e]);
		OutPath(s,e);
		printf(">>按Enter键返回主界面");
		system("pause");
		system("cls");
	}else{
		printf("编号输入错误,请重新输入正确的景点编号!\n");
		printf("按Enter键重新输入");
		system("pause");
		system("cls");
		PrintPath();
	}

}



void print(int s,int e)
{
    for(int i = s;i<e;i++)
    {
        cout << "-->"<<G.Scenic[ans[i]].data.name;
    }
    cout << endl;
}
void DFS(int k,int start)
{
    if(start == v)
    {

        print(1,k);
        return;
    }
    vis[start] = 1;
    for(int i = 1;i<=snum;i++)
    {
        if(vis[i]==1 || (G.D[start][i]==0||G.D[start][i]==inf))
        continue;
        ans[k] = i;
        DFS(k+1,i);
    }
    vis[start] = 0;
}


void allroad()
{
    printf("输入开始结束点\n");
           scanf("%d%d",&u,&v);
		    ans[1]= u;
			DFS(2,u);
}


void Swap(int &a, int &b)
{
        int tmp;
		tmp= a;
        a = b;
        b = tmp;
}

int minlen = 50000;
int pathmin[2000];
int wei;
int jjj = 100;
int lll;
//int strr[100];
int Perm(int *str, int k, int m,int &kkk)
{
        int i;
        int xxx;
        int len = 0;
        int pathm[200];
        //int nnext;
        //int pre;
        //int judge;
        int pa[20];
        if(k == m)
        {
                for(i=1; i<m; ++i)
					{
					    int j = 0;
                      dijksrra(str[i]);
                        len+= dist[str[i+1]];
                        //printf("3333333333333");
                        int next=str[i];
	                    int pre = str[i+1];

                        pre = prev[str[i+1]];

                        xxx = str[m];
                        //printf()
                        //int preee;
	                    do{
                            //nnext = next;
                            next = pre;
		                    pa[j++]=pre;
		                    //preee = prev[pre];
		                    pre = prev[pre];

                         }while(prev[next]!=str[i]);
                         pa[j]=str[i];





                         for(j=j;j>=0;j--)
                            pathm[jjj--]=pa[j];

                        //printf("%d%d%d%d%d",i,i,i,i,i);
                    }
                //printf("555555555555555");
                int judge = 1;
                minlen > len && len >100?judge = 2:judge = 1;
                if(judge == 2)
                    {
                      minlen = len;
                    lll=0;
                      for(jjj=jjj+1;jjj<=100;jjj++)
                         {pathmin[lll++] = pathm[jjj];}
                      wei = xxx;
                     //kkk = jjj;
                    }


                jjj = 100;
                return len;
        }
        /*
        if(k == m)
        {

                for(i=1; i<m-1; ++i)
					{
                      dijksrra(str[i]);
                        len+= dist[str[i+1]];
                        xxx = str[m];


                            do{
                            next = pre;
		                    pathm[jjj++]=pre;
		                    pre = prev[pre];
                         }while(prev[next]!=str[i]);
					}


                   //printf("5555555555");


                judge = 1;
                minlen > len && len >100?judge = 2:judge = 1;
                if(judge == 2)
                    {
                      minlen = len;
                      for(i = 0;i<jjj;i++)
                      pathmin[i] = pathm[i];
                      wei = xxx;
                     kkk = m;
                    }

                judge = 1;
                jjj = 0;
                return len;
        }
*/
        for(i=k; i<=m; ++i)
        {
                Swap(str[k], str[i]);
                Perm(str, k+1, m,kkk);
                Swap(str[k], str[i]);
        }
return minlen;
}





void multroad()
{
    int i;
    int n;
    int kkk;
    int len;
    printf("请输入要游览的景点个数：");
    scanf("%d",&n);
    for(int i=1; i<=n; ++i)
        {
         scanf("%d",&str[i]);
        }
    //printf("1111111111111");
    len = Perm(str, 1, n,kkk);
    //printf("2222222222222");
    printf("最短长度为：%d\n路径：",len);
    for(i=lll-1;i>=0;i--)
    {
        if(pathmin[i] == pathmin[i-1])
            continue;
        printf("-->%s",G.Scenic[pathmin[i]].data.name);
    }

    printf("-->%s\n",G.Scenic[wei].data.name);

    minlen = 500000;


}




void Menu(){
	printf("----------------欢迎进入校园导游系统----------------\n");
	printf("\n----------------------------------------------------\n");
	printf("1.查看两个景点间的所有路径\n");
	printf("2.修改景点信息\n");
	printf("3.查看景点基本信息\n");
	printf("4.最短路径查询\n");
	printf("5.多个景点的最短路径查询\n");
	printf("6.显示地图\n");
	printf("7.退出系统\n");
	printf("----------------------------------------------------\n");
	printf("请输入您要选择的功能:");
	int chose;
	scanf("%d",&chose);
	switch(chose){
		case 1: {
		    allroad();
			Menu();
		}
		case 2: {
			ChangeMes();
			Menu();
		}
		case 3: {
			ViewMes();
			Menu();
		}
		case 4: {
			PrintPath();
			Menu();
		}
		case 5: {
			multroad();
			Menu();
		}
		case 6: {
			system("mspaint map.bmp");
            Menu();
		}
		case 7: {
			exit(0);
		}
		default : {
			printf("您的选择有误,请重新选择!");
			Menu();
		}
	}
}

int main(){

   char passwd[20];
     char c;
    int i = 0;
    int len = 20;


    while(1)
    {
        printf("请输入密码");
        i = 0;
        while ((c = getch()) !='\r')
        {
            passwd[i] = c;
            putchar('*');
            //printf("%d",i);
            i++;
            if (i >= len)
            {
                break;
            }
        }
        passwd[i] = '\0';
        printf("\n");
        if(strcmp(passwd,"password")==0)
        {
            InitMes();
	        printf("密码正确,即将进入主界面");
            for (int k=0;k<5;k++)
            {
	            Sleep(100);
	            printf(".");
	            Sleep(100);
	            printf(".");
	            Sleep(100);
	            printf(".");
	            Sleep(100);
	            printf(".");
	            Sleep(100);
	            printf(".");
	            Sleep(100);
	            printf(".");
	            printf("\b\b\b\b\b\b      ");
                printf("\b\b\b\b\b\b");
            }
	        system("cls");
	        Menu();
        }

    }

	return 0;
}
