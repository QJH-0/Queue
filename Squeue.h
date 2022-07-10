#include <conio.h>
#include "menu.h"
#define MAXQSIZE 101//实际可排100个号满牺牲一个空间


int Work=0;//标记是否签到上班 
typedef int ElemType;

typedef struct
{
	ElemType data[MAXQSIZE];
	int front;
	int rear;
}SqQueue;

int QueueEmpty(SqQueue Q)//判断队列是否为空
{
	if(Q.front==Q.rear)
		return 1;
	else
		return 0;
}
int QueueFull(SqQueue Q)//判断队列是否已满牺牲一个空间 
{
	if((Q.rear+1)%MAXQSIZE==Q.front)
		return 1;
	return 0;
}

int PushQueue(SqQueue *Q,ElemType e)//元素e入队尾
{
	if(QueueFull(*Q)) return 0;
	Q->data[Q->rear]=e;
	Q->rear=(Q->rear+1)%MAXQSIZE;
	return 1;
}

int DeleteQueue(SqQueue *Q,ElemType *e)//元素e出队，并用e来返回
{
	if(QueueEmpty(*Q)) return 0;
	*e=Q->data[Q->front];
	Q->front=(Q->front+1)%MAXQSIZE;
	return 1;
}

void InitQueue(SqQueue *Q)//队列初始化，同时让标记变量Work标记为1；
{
	Q->front=Q->rear=0;
    Work = 1;
}

int GetHead(SqQueue Q,ElemType *e)//获得队头元素
{
	if(QueueEmpty(Q)) return 0;
	*e=Q.data[Q.front];
	return 1;
}

int QueueLength(SqQueue Q)//求队列长度
{
	return (Q.rear+MAXQSIZE-Q.front)%MAXQSIZE;
}


int clear1(SqQueue *Q)//清空队列 
{
	Q->front=Q->rear=0;
	return 1;
  }  

void Sque()//顺序队列 
{
	void Menu();
	int QueueEmpty(SqQueue Q);
	int QueueFull(SqQueue Q);
	int PushQueue(SqQueue *Q,ElemType e);
	int DeleteQueue(SqQueue *Q,ElemType *e);
	void InitQueue(SqQueue *Q);
	int GetHead(SqQueue Q,ElemType *e);
	int QueueLength(SqQueue Q);
	
	system("cls"); 
	int num=0;//出号的序号 
	SqQueue Q;
	ElemType e;
	char chos;
	while(1)
	{
				system("cls");
		Menu();
		scanf("%c",&chos);

		switch(chos)
		{
			case '1':
				InitQueue(&Q);
			       printf("@@签到成功，开始上班\n\n");
			       getch();
//			       system("pause");
				break;
			case '2':
				if (!Work ) 
				   {
					   printf("@@请先签到\n\n");
					   getch();
					   break;
				   }
				if(!QueueFull(Q))
				{
					PushQueue(&Q, ++num) ;
					printf("@@当前是%d号，前面还有%d人等待。\n\n",num,QueueLength(Q)-1);
					getch();
				}
			       else
			       {
				       	printf("@@人数已满！\n\n");
					       getch();
				   }
				       
				   break;
			case '3':
			 	if (!Work ) 
				   {
					   printf("@@请先签到\n\n");
					  getch();
					   break;
				   }
				if(DeleteQueue(&Q, &e))
				{
					printf("@@到%d号办理！目前还有%d个人等待办理。\n\n",e,QueueLength(Q));
					  getch();
				}
					   
				   else
				   {
				   		printf("@@目前暂无需要办理业务的顾客！\n\n");
				   		getch();
				   }
                       
			       break;
			case '4':
				 	if (!Work ) 
				   {
					   printf("@@请先签到\n\n");
					  getch();
					   break;
				   }
				   else
				   {
						clear1(&Q);
						printf("清除成功");
						getch();
						break;
				   }
			case '0':
				if (!Work ) 
				   {
					   printf("请请先签到！\n\n");
					  getch();
					   break;
				   }
		        if(QueueEmpty(Q))   
				{
					printf("@@签退成功，回家！\n\n"); 
					Work=0;
					getch();
					return;
				} 
				else
				{
					printf("@@目前还有%d已排号未办理业务的顾客，暂不能下班\n\n",QueueLength(Q));
					getch();
					break;
				}	
			default:
				system("cls");
				continue;
		}
		
	}
return;
 } 
