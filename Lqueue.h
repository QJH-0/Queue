#include <conio.h>
#include <stdlib.h>
#include "menu.h"
#define MAXQSIZE 101//实际可排100个号满牺牲一个空间


int work=0;//标记是否签到上班 
typedef int ElemType;
typedef struct QNode
{
	ElemType data;//数据域 
	struct QNode *next;//指针域 
} QNode,*LQueue;
typedef struct
{
	LQueue front; //队头指针
	LQueue rear; //队尾指针
} LinkQueue;

int QueueEmpty1(LinkQueue Q) //若队列Q为空队列，则返回1,否则返回0
{
	if(Q.front == NULL)
		return 1;
	else
		return 0;
}

void InitQueue1(LinkQueue *Q) //队列初始化，同时让标记变量work标记为1；
{
	Q->front=NULL;
	Q->rear=NULL;
	work=1;
}


int PushQueue1(LinkQueue *Q, ElemType e) //插入元素e为Q的新的队尾元素
{
	LQueue p = (LQueue)malloc(sizeof(QNode));
	p->data = e;
	p->next = NULL;
	if(Q->rear==NULL)
		Q->front=Q->rear=p;
	else
		{
			Q->rear->next = p;
			Q->rear = p;
		}
return 1;
}


int DeQueue1(LinkQueue *Q, ElemType *e) //元素e出队，并用e来返回
{	LQueue p;
	if(Q->front == NULL)
		return 0;
	else
	{
		p = Q->front;
		*e = p->data;
		Q->front = p->next;
		if(Q->front==NULL)
			Q->rear = NULL;
		free(p);
		return 1;
	}
}

int GetHead1(LinkQueue Q, ElemType *e) //获得队头元素,并返回1，否则返回0
{
	if(Q.front==NULL)
	{
		return 0;
	}
	else
	{
		*e=Q.front->data;
		return 1;
	}

}

int QueueLength1(LinkQueue Q) //求队列长度
{
	LQueue p;
	int length = 0;
	p = Q.front;
	while(p!=NULL)
	{
		length ++;
		p = p->next;
	}
return length;
}

int clear(LinkQueue *Q)//清空队列 
{
	LQueue p,t;
	p=Q->front;
	Q->front=NULL;
	Q->rear=NULL;
	while(p){
		t = p -> next;	
		free(p);	
		p = t;
	}
	return 1;
}


void Lque()//链式 
{
	void Menu();
	int QueueEmpty1(LinkQueue Q);
	int PushQueue1(LinkQueue *Q,ElemType e);
	int DeQueue1(LinkQueue *Q,ElemType *e);
	void InitQueue1(LinkQueue *Q);
	int GetHead1(LinkQueue Q,ElemType *e);
	int QueueLength1(LinkQueue Q);
	
	system("cls"); 
	int num=0;//出号的序号 
	LinkQueue Q;
	ElemType e;
	char chos;
	while(1)
	{
				system("cls");
		Menu();
		fflush(stdin);
		scanf("%c",&chos);

		switch(chos)
		{
			case '1':
				InitQueue1(&Q);
			       printf("@@签到成功，开始上班\n\n");
			       getch();
//			       system("pause");
				break;
			case '2':
				if (!work ) 
				   {
					   printf("@@请先签到\n\n");
					   getch();
					   break;
				   }
				   else
				   {
				   		PushQueue1(&Q, ++num) ;
						printf("@@当前是%d号，前面还有%d人等待。\n\n",num,QueueLength1(Q)-1);
						getch();
								       
					   break;
				   }

			case '3':
			 	if (!work ) 
				   {
					   printf("@@请先签到\n\n");
					  getch();
					   break;
				   }
				   else
				   {
						if(DeQueue1(&Q, &e))
						{
							printf("@@到%d号办理！目前还有%d个人等待办理。\n\n",e,QueueLength1(Q));
							  getch();
						}
							   
						   else
						   {
						   		printf("@@目前暂无需要办理业务的顾客！\n\n");
						   		getch();
						   }
		                       
					       break;
				   }
			case '4':
				 	if (!work ) 
				   {
					   printf("@@请先签到\n\n");
					  getch();
					   break;
				   }
				   else
				   {
						clear(&Q);
						printf("清除成功");
						getch();
						break;
				   }

			case '0':
				if (!work ) 
				   {
					   printf("请请先签到！\n\n");
					  getch();
					   break;
				   }
				   else
				   {
				        if(QueueEmpty1(Q))   
						{
							printf("@@签退成功，回家！\n\n"); 
							work=0;
							getch();
							return;
						} 
						else
						{
							printf("@@目前还有%d已排号未办理业务的顾客，暂不能下班\n\n",QueueLength1(Q));
							getch();
							break;
						}
				   }
	
			default:
				system("cls");
				continue;
		}
		
	}
return;
 } 
