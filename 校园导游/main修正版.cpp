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
	strcpy(G.Scenic[count].data.name,"������");
	strcpy(G.Scenic[count].data.Introduce,"ѧУ���ţ��ż�ʱ���������");
	count++;
	G.Scenic[count].num=2;
	strcpy(G.Scenic[count].data.number,"V2");
	strcpy(G.Scenic[count].data.name,"��������");
	strcpy(G.Scenic[count].data.Introduce,"�����и����˶��ĳ���");
	count++;
	G.Scenic[count].num=3;
	strcpy(G.Scenic[count].data.number,"V3");
	strcpy(G.Scenic[count].data.name,"��Է������");
	strcpy(G.Scenic[count].data.Introduce,"���ɶ����ĺ�ȥ��");
	count++;
	G.Scenic[count].num=4;
	strcpy(G.Scenic[count].data.number,"V4");
	strcpy(G.Scenic[count].data.name,"��Ȫ�㳡");
	strcpy(G.Scenic[count].data.Introduce,"��¥�����Ȫ");
	count++;
	G.Scenic[count].num=5;
	strcpy(G.Scenic[count].data.number,"V5");
	strcpy(G.Scenic[count].data.name,"����Է");
	strcpy(G.Scenic[count].data.Introduce,"һ���ļ��ٻ���ţ���������,����!");
	count++;
	G.Scenic[count].num=6;
	strcpy(G.Scenic[count].data.number,"V6");
	strcpy(G.Scenic[count].data.name,"�ڰ�ʳ��");
	strcpy(G.Scenic[count].data.Introduce,"������Ҫ�Ľ�ѧ¥����¥����ʮ�ֺ�");
	count++;
	G.Scenic[count].num=7;
	strcpy(G.Scenic[count].data.number,"V7");
	strcpy(G.Scenic[count].data.name,"����կɽ");
	strcpy(G.Scenic[count].data.Introduce,"�ս��õ�ɽ�幫԰���������ѧУ");
	count++;
	G.Scenic[count].num=8;
	strcpy(G.Scenic[count].data.number,"V8");
	strcpy(G.Scenic[count].data.name,"ʮ��");
	strcpy(G.Scenic[count].data.Introduce,"��Ҫ�Ľ�ѧ�գ����۸��ӣ�������·");
	count++;
	G.Scenic[count].num=9;
	strcpy(G.Scenic[count].data.number,"V9");
	strcpy(G.Scenic[count].data.name,"ʮ����");
	strcpy(G.Scenic[count].data.Introduce,"��ϢѧԺ���ڵأ������Ƕ���У��õĽ���");
	count++;
	G.Scenic[count].num=10;
	strcpy(G.Scenic[count].data.number,"V10");
	strcpy(G.Scenic[count].data.name,"ͼ���");
	strcpy(G.Scenic[count].data.Introduce,"��˵��ɽ�����ĵ���ͼ��ݣ�ѧϰ��Χ��Ũ��");
	count++;
	G.Scenic[count].num=11;
	strcpy(G.Scenic[count].data.number,"V11");
	strcpy(G.Scenic[count].data.name,"�����㳡");
	strcpy(G.Scenic[count].data.Introduce,"ѧУ�ĵر�");
	count++;
	G.Scenic[count].num=12;
	strcpy(G.Scenic[count].data.number,"V12");
	strcpy(G.Scenic[count].data.name,"�ݷ�¥");
	strcpy(G.Scenic[count].data.Introduce,"�Ƚ��µĽ�����ѧУ�����");
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
	printf("�Ƿ�����һ�������·��s�Ӿ��㣬r��·�������˳�\n");
	char chose;
	scanf("%c",&chose);
	if(chose == 's')
    {
        char nnn[Max_n];
        char nam[Max_n];
        char intr[Max_n];
        snum++;
        printf("���뾰����Ϣ:\n");
        printf("���뾰����ţ�");
        scanf("%s",nnn);
        printf("���뾰�����ƣ�");
        scanf("%s",nam);
        printf("���뾰���飺");
        scanf("%s",intr);
        strcpy(G.Scenic[snum].data.number,nnn);
	    strcpy(G.Scenic[snum].data.name,nam);
        strcpy(G.Scenic[snum].data.Introduce,intr);
        G.D[snum][snum]=0;
    }
    else if (chose == 'r')
    {
        int a,b,c;
        printf("����Ҫ�����·����ʽ����� �յ� ����");
            scanf("%d%d%d",&a,&b,&c);
            G.D[a][b]=c;
            G.D[b][a]=c;
    }
}

void ViewSpeMes(int i){
	printf("���Ϊ%d�ľ������ϢΪ:\n",i);
	printf("---------------------------------------------\n");
	printf("�������:%s\n",G.Scenic[i].data.number);
	printf("��������:%s\n",G.Scenic[i].data.name);
	printf("������:%s\n",G.Scenic[i].data.Introduce);
	printf("---------------------------------------------\n");
}

void ViewMes(){
	printf("��������Ҫ�鿴�ľ�����Ϣ�ı��:");
	int chose;
	scanf("%d",&chose);
	ViewSpeMes(chose);
	printf("��ѯ���!�Ƿ������ѯ?(y/n)");
	char a;
	scanf(" %c",&a);
	if(a=='y'){
		printf("��ѡ���˼�����ѯ!\n");
		ViewMes();
	}
	printf("��ѯ����,Enter������������\n");
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
	printf(">>·��Ϊ:\n");
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

	printf("����У԰ƽ��ͼ,��������ǰ���ھ��㼰��Ҫȥ�ľ���ı��:");
	int s,e;
	scanf("%d%d",&s,&e);
	dijksrra(s);
	if(s<=snum&&s>=0&&e<=snum&&e>=0){
		printf(">>%s��%s�����·������Ϊ: %d\n",G.Scenic[s].data.name,G.Scenic[e].data.name,dist[e]);
		OutPath(s,e);
		printf(">>��Enter������������");
		system("pause");
		system("cls");
	}else{
		printf("����������,������������ȷ�ľ�����!\n");
		printf("��Enter����������");
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
    printf("���뿪ʼ������\n");
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
    printf("������Ҫ�����ľ��������");
    scanf("%d",&n);
    for(int i=1; i<=n; ++i)
        {
         scanf("%d",&str[i]);
        }
    //printf("1111111111111");
    len = Perm(str, 1, n,kkk);
    //printf("2222222222222");
    printf("��̳���Ϊ��%d\n·����",len);
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
	printf("----------------��ӭ����У԰����ϵͳ----------------\n");
	printf("\n----------------------------------------------------\n");
	printf("1.�鿴��������������·��\n");
	printf("2.�޸ľ�����Ϣ\n");
	printf("3.�鿴���������Ϣ\n");
	printf("4.���·����ѯ\n");
	printf("5.�����������·����ѯ\n");
	printf("6.��ʾ��ͼ\n");
	printf("7.�˳�ϵͳ\n");
	printf("----------------------------------------------------\n");
	printf("��������Ҫѡ��Ĺ���:");
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
			printf("����ѡ������,������ѡ��!");
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
        printf("����������");
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
	        printf("������ȷ,��������������");
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
