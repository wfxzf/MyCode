#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
struct Node
{
	int r,c,dir;
	Node(int r=0,int c=0,int dir=0):r(r),c(c),dir(dir){}
};
Node p[10][10][4];
int has_edge[10][10][4][3];
int d[10][10][4];
int r0,c0,r1,c1,r2,c2,dir;


const char *dirs="NESW" ;
const char *turn="FLR" ;
int dir_id(char ch)
{
	return strchr(dirs,ch)-dirs;
}
int turn_id(char ch)
{
	return strchr(turn,ch)-turn;
}

int dr[]={-1,0,1,0};
int dc[]={0,1,0,-1};

Node walk(Node &u,int turn)
{
	int dir=u.dir;
	if(turn==1)
	{
		dir=(dir+3)%4;
	}
	if(turn==2)
	{
		dir=(dir+1)%4;
	}
	return Node(u.r+dr[dir],u.c+dc[dir],dir);
}

bool inside(int r,int c)
{
	if(r>9||c>9||r<0||c<0)
	{
		return false;
	}
	return true;
 } 

void printf_ans(Node u)
{
	vector<Node> nodes;
	while(1)
	{
		nodes.push_back(u);
		if(d[u.r][u.c][u.dir]==0)
		break;
		u=p[u.r][u.c][u.dir];
	}
		nodes.push_back(Node(r0,c0,dir));
		
		
	int count=0;
	for(int i=nodes.size()-1;i>=0;i--)
	{
		printf("(%d,%d)",nodes[i].r,nodes[i].c);
		 if(++count==10)
		 {
           printf("\n");
         }
	}
}


void solve()
{
	queue<Node> q;
	memset(d,-1,sizeof(d));
	Node u(r1,c1,dir);
	q.push(u);
	d[u.r][u.c][u.dir]=0;
	while(!q.empty())
	{ 
		Node u=q.front();
		q.pop();
		if(u.r==r2&&u.c==c2)
		{
			printf_ans(u);
			return;
		}
		for(int i=0;i<3;i++)
		{
			Node v=walk(u,i);
			if(inside(v.r,v.c)&&
			  d[v.r][v.c][v.dir]<0&&
			  has_edge[v.r][v.c][v.dir][i]
			  )
			{
				d[v.r][v.c][v.dir]=	d[u.r][u.c][u.dir]+1;
				p[v.r][v.c][v.dir]=u;
				q.push(v);
			}
		 } 
	}
	printf("No solution possible!\n");
}



bool read_case()
{
	char s[100],s2[100];
	if(scanf("%d%d%s%d%d",&r0,&c0,&s,&r2,&c2)!=5)return false;
	dir=dir_id(s2[0]);
	r1=r0+dr[dir];
	c1=c1+dr[dir];
	
	memset(has_edge,0,sizeof(has_edge));
	
	while(1)
	{
		int r,c;
		scanf("%d",&r);
		if(r==0)
		{
			break;
		}
		scanf("%d",&c);
		while(scanf("%s",s)==1&&s[0]!='*')
		{
			for(int i=1;i<strlen(s);i++)
			{
				has_edge[r][c][dir_id(s[0])][turn_id(s[i])]=1;
			}
		}
	}
	return true;
}


int main()
{
  while(read_case()) 
  {
    solve();
  }
    return 0;
}
