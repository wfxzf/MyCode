
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <string.h>

//这个数据结构就是内存当中，规则的形式，就是if then 当中，if 和then 中间的前件
//众多的前件用 next指针连接起来

struct CAUSE_TYPE{
char * cause;
struct CAUSE_TYPE * next;
};
//这个数据结构就是内存当中规则库的形式，就是if then 这个规则
//其中，result 为后件也就是结论，lastflag标记了该结论是否为最终结论，仔细阅读MarkKB函数
//明确其值为：0/1的区别
//cause_chain 表明了规则的前件
//众多的规则采用next进行连接
//这个数据结构，翻译成为规则就是： if cause_chain then result
struct RULE_TYPE{
char * result;//结论
int lastflag;//最终结论的标记
struct CAUSE_TYPE * cause_chain;//
struct RULE_TYPE * next;
};

struct CAUSE_TYPE * DataBase;//用来存放知识库的
struct CAUSE_TYPE * Conclusion;//这是中间推出的结论，也称综合数据库
struct RULE_TYPE * KnowledgeBase;//这个是用户录入的事实库。
struct RULE_TYPE * Used;//这个是用户使用过的规则库列表

void freeKB(struct RULE_TYPE *);//释放所有的规则库列表
void freeDB(struct CAUSE_TYPE *);//释放知识库，内存回收
int FindCause(char *);//知识库进行数据的匹配，if 和 then 中间的前件知识。
void markKB();//这个函数主要是划分中间结论和最终结论。
void creatKB();//创建知识库
void inputDB();//数据事实
void think();//推理机进行推理
void explain();//显示整个推理的过程


void main()
{
  creatKB();
  inputDB();
  think();
  explain();
  printf("sucessed\n");

}

//解释省略
void freeDB(struct CAUSE_TYPE * cPoint)
{
  struct CAUSE_TYPE * cp;
  while(cPoint)
  {
    cp=cPoint->next;
    free(cPoint->cause);
    cPoint->cause=NULL;
    cPoint->next=NULL;
    free(cPoint);
    cPoint=cp;
  }
}

//解释省略
void freeKB(struct RULE_TYPE * rPoint)
{
  struct RULE_TYPE * rp;
  while(rPoint)
  {
    rp=rPoint->next;
    freeDB(rPoint->cause_chain);
    rPoint->cause_chain=NULL;
    free(rPoint->result);
    rPoint->result=NULL;
    rPoint->next=NULL;
    free(rPoint);
    rPoint=rp;
  }
}

//这个函数主要是划分中间结论和最终结论。
void markKB()
{
	struct RULE_TYPE * rp1,* rp2;
	struct CAUSE_TYPE * cp;
	rp1=KnowledgeBase;
	cp=rp1->cause_chain;
	while(rp1)
	{ rp1->lastflag=1;//初始化，默认的是最终数据
	rp1=rp1->next;}
	rp1=KnowledgeBase;
	
	while(rp1)
	{
		cp=rp1->cause_chain;//当前规则的前件
		
		while(cp)
		{
			rp2=KnowledgeBase;
			while(rp2)
			{
				
				if(strcmp(rp2->result,cp->cause)==0)//在另一个规则的结论，是当前规则的前件
					rp2->lastflag=0;//另一规则的结论就应该是中间结论
				rp2=rp2->next;
			}
			cp=cp->next;
		}
		rp1=rp1->next;
	}
}
//创建知识库。
void creatKB()
{
	FILE * fp;
	struct CAUSE_TYPE * cp=NULL;
	struct RULE_TYPE * rp=NULL;
	int i,j;
	static char sp[80];
	char ch;
	float CF,r,cf,w;
	
	freeKB(KnowledgeBase);
	freeKB(Used);
	KnowledgeBase=Used=NULL;
	if((fp=fopen("rule.dat","r"))==NULL)
	{
		printf("\n knowledgebase is not exist,to establish!\n");
		for(i=1;;i++)
		{
			printf("\n********NO  %d  rule********",i);
			printf("\n**conclusino:(is/can/has)");//首先输入结论
			
			gets(sp);
			if(*sp=='\0')  break;
			rp=(struct RULE_TYPE *)malloc(sizeof(struct RULE_TYPE));//创建规则链表
			rp->result=(char *)malloc(strlen(sp)+1);
			strcpy(rp->result,sp);//结论的赋值
			rp->cause_chain=NULL;
			rp->next=KnowledgeBase;//插入到规则链表中去
			KnowledgeBase=rp;			
			for(j=1;;j++)
			{
				printf("\n***tiao(%d)(is/can/has):",j);//输入支持结论的前件(条件)
				
				gets(sp);
				if(*sp=='\0')  break; //回车表示,前件录入结束
				cp=(struct CAUSE_TYPE *)malloc(sizeof(struct CAUSE_TYPE));
				cp->cause=(char *)malloc(strlen(sp)+1);
				strcpy(cp->cause,sp);
				cp->next=rp->cause_chain;
				rp->cause_chain=cp;
			}
		}
		if(!KnowledgeBase)
		{
			printf("\n There is no rule in the Knowledgebase!\n");
			return;
		}
		
		if((fp=fopen("rule.dat","w"))==NULL)
		{
			printf("\n write file is error!\n");
			exit(1);
		}
		else {
			
			rp=KnowledgeBase;//将数据保存到文件当中,一共下一次进行数据的调用
			while(rp)
			{
				fputs(rp->result,fp);
				fputc('\n',fp);
				cp=rp->cause_chain;
				while(cp)
				{
					fputs(cp->cause,fp);
					fputc('\n',fp);
					cp=cp->next;
				}
				fputs("\\\n",fp);//规则和规则之间用字符"\"分开
				rp=rp->next;
			}
			fclose(fp);
		}
	}
	
	else 
	{//表示知识库已经存在了,可以进行数据的加载了		
		while(!feof(fp))
		{
			fgets(sp,80,fp);
			if(*sp=='\0'||*sp=='\\')//新的规则的标记
				break;
			rp=(struct RULE_TYPE *)malloc(sizeof(struct RULE_TYPE));
			rp->result=(char *)malloc((i=strlen(sp))+1);
			sp[i-1]='\0';
			strcpy(rp->result,sp);//类似前面的内容
			rp->cause_chain=NULL;
			rp->next=KnowledgeBase;
			KnowledgeBase=rp;
			fgets(sp,80,fp);			
			while(*sp!='\\')//表示的是前件
			{
				cp=(struct CAUSE_TYPE *)malloc(sizeof(struct CAUSE_TYPE));
				cp->cause=(char *)malloc((i=strlen(sp))+1);
				sp[i-1]='\0';
				strcpy(cp->cause,sp);
				cp->next=rp->cause_chain;
				rp->cause_chain=cp;
				fgets(sp,80,fp);
		}   }
		fclose(fp);
	}
	markKB();
}

//用户录入推理的事实
void inputDB()
{
  int i;
  static char sp[80];
  struct CAUSE_TYPE * cp;
  float cf,w;

  freeDB(DataBase);
  freeDB(Conclusion);
  DataBase=Conclusion=NULL;
  printf("\n*****please input the knowledge:\n");
  for(i=1;;i++)
  {
    printf("\n**tiao jian(%d)(is/can/has):",i);
    gets(sp);
    if(*sp=='\0')  break;
    cp=(struct CAUSE_TYPE *)malloc(sizeof(struct CAUSE_TYPE));//创建事实库的链表
    cp->cause=(char *)malloc(strlen(sp)+1);
    strcpy(cp->cause,sp);
    cp->next=DataBase;
    DataBase=cp;
  }
}



int FindCause(char *sp)//这个是需要匹配的事实,就是说当前的事实是否能够匹配数据库和结论库当中的数据
{
	struct CAUSE_TYPE * cp2;
	
	cp2=DataBase;//知识库匹配
	while(cp2)
		if(strcmp(sp,cp2->cause)==0)
		{
			return(1);//匹配成功输出1
		}
		else cp2=cp2->next;
		
		cp2=Conclusion;//中间结论库
		while(cp2)
			if(strcmp(sp,cp2->cause)==0)
			{
				return(1);//匹配成功输出1
			}
			else cp2=cp2->next;
			return (0);
}
//这个是推理的核心模块
void think()
{
	struct RULE_TYPE * rp1,* rp2,* rp3;
	struct CAUSE_TYPE * cp1, * cp2,* cp3;
	int RuleCount,i;
	static char sp[80];
	//用户使用过的规则,添加到数据库当中,因为使用过的规则被裁减下来,放到used当中去了
	if(Used)
	{
		rp1=Used;
		while(rp1->next)  rp1=rp1->next;
		rp1->next=KnowledgeBase;
		KnowledgeBase=Used;
		Used=NULL;
	}
	//将结论的表进行清空,以便于进行新的推理解释
	if(Conclusion)
	{
		freeDB(Conclusion);
		Conclusion=NULL;
	}
	//正式开始进行推理了.
	do{
		
		RuleCount=0;
		rp1=KnowledgeBase;//通过定位两个知识的指针,来进行知识的匹配
		rp2=KnowledgeBase;
		while(rp1)
		{
			
			cp1=rp1->cause_chain;//第一个规则的前件
			
			while(cp1)
			{
				if(FindCause(cp1->cause)==0)//找到第一个规则当中的数据是否跟用户给出的事实进行匹配,如果有不匹配的退出
				{
					break;
				}
				else {
					cp1=cp1->next;
				}
			}
			if(cp1)//证明没有完全匹配的前件,所以知识库的结果下移动一个位置
			{
				rp2=rp1;
				rp1=rp1->next;
			}
			else if(FindCause(rp1->result)==0)
			{
				/*若该条规格的结论文新事实,将该结论加入结论链表,并将该条规则从知识库中取出,插入已经使用的规则链表中*/
				
				cp1=(struct CAUSE_TYPE *)malloc(sizeof(struct CAUSE_TYPE));
				cp1->cause=(char *)malloc(strlen(rp1->result)+1);
				strcpy(cp1->cause,rp1->result);
				cp1->next=Conclusion;
				Conclusion=cp1;
				if(rp1->result==rp2->result)
				{
					rp2=rp2->next;
					rp1->next=Used;
					Used=rp1;
				}
				
				else
				{
					rp2->next=rp1->next;
					rp1->next=Used;
					Used=rp1;
				}
				
				rp1=rp2;
				RuleCount++;
				if(Used->lastflag==1)//若该规则为结论性规则,推理结束.
				{
					RuleCount=0;
					break;
				}
			}
			else {
				rp2=rp1;
				rp1=rp1->next;
			} 
			
			
		}
	}
	while(RuleCount>0);
	if(!Conclusion||Used->lastflag==0)
	{
		printf("\n know is not enough!Please add the knowledge:\n");
		cp1=DataBase;
		
		printf("\n*****the known knowledge:\n");
		for(i=1;cp1;i++)
		{
			printf("\n**tiao jian(%d):(is/can/has)%s",i,cp1->cause);
			cp1=cp1->next;
		}
		printf("\n*****The add knowledge:\n");
		for(;;i++)
		{
			printf("\n**tiao jian(%d):(shi/can/has)",i);
			gets(sp);
			if(*sp=='\0')  break;
			cp1=(struct CAUSE_TYPE *)malloc(sizeof(struct CAUSE_TYPE));
			cp1->cause=(char *)malloc(strlen(sp)+1);
			strcpy(cp1->cause,sp);
			cp1->next=DataBase;
			DataBase=cp1;
		}
		think();
	}
	else
	{
		printf("\n this animal is:(is/can/has)\"%s\"\n",Conclusion->cause);
		
	}
}
//解释的过程就是把Used的链表安推理的顺序输出,这样就形成了推理的过程
void explain()
{
  struct RULE_TYPE * rp,* rp2;
  struct CAUSE_TYPE * cp;
  float cf;
  int i;
  rp=Used;
  rp2=Used;
  i=0;

  while(rp)
  {
    printf("\n*this animal is(is/can/has)\"%s\",because:\n",rp->result);//数据相关的结论,前件在后面输出
    cp=rp->cause_chain;
   while(cp)
    {
      printf("**(%d)--it(is/can/has)\"%s\"\n",i++,cp->cause);//输出相关的前件
      cp=cp->next;
    }
    rp=rp->next;
  }

}

