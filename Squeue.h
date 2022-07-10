#include <conio.h>
#include "menu.h"
#define MAXQSIZE 101//ʵ�ʿ���100����������һ���ռ�


int Work=0;//����Ƿ�ǩ���ϰ� 
typedef int ElemType;

typedef struct
{
	ElemType data[MAXQSIZE];
	int front;
	int rear;
}SqQueue;

int QueueEmpty(SqQueue Q)//�ж϶����Ƿ�Ϊ��
{
	if(Q.front==Q.rear)
		return 1;
	else
		return 0;
}
int QueueFull(SqQueue Q)//�ж϶����Ƿ���������һ���ռ� 
{
	if((Q.rear+1)%MAXQSIZE==Q.front)
		return 1;
	return 0;
}

int PushQueue(SqQueue *Q,ElemType e)//Ԫ��e���β
{
	if(QueueFull(*Q)) return 0;
	Q->data[Q->rear]=e;
	Q->rear=(Q->rear+1)%MAXQSIZE;
	return 1;
}

int DeleteQueue(SqQueue *Q,ElemType *e)//Ԫ��e���ӣ�����e������
{
	if(QueueEmpty(*Q)) return 0;
	*e=Q->data[Q->front];
	Q->front=(Q->front+1)%MAXQSIZE;
	return 1;
}

void InitQueue(SqQueue *Q)//���г�ʼ����ͬʱ�ñ�Ǳ���Work���Ϊ1��
{
	Q->front=Q->rear=0;
    Work = 1;
}

int GetHead(SqQueue Q,ElemType *e)//��ö�ͷԪ��
{
	if(QueueEmpty(Q)) return 0;
	*e=Q.data[Q.front];
	return 1;
}

int QueueLength(SqQueue Q)//����г���
{
	return (Q.rear+MAXQSIZE-Q.front)%MAXQSIZE;
}


int clear1(SqQueue *Q)//��ն��� 
{
	Q->front=Q->rear=0;
	return 1;
  }  

void Sque()//˳����� 
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
	int num=0;//���ŵ���� 
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
			       printf("@@ǩ���ɹ�����ʼ�ϰ�\n\n");
			       getch();
//			       system("pause");
				break;
			case '2':
				if (!Work ) 
				   {
					   printf("@@����ǩ��\n\n");
					   getch();
					   break;
				   }
				if(!QueueFull(Q))
				{
					PushQueue(&Q, ++num) ;
					printf("@@��ǰ��%d�ţ�ǰ�滹��%d�˵ȴ���\n\n",num,QueueLength(Q)-1);
					getch();
				}
			       else
			       {
				       	printf("@@����������\n\n");
					       getch();
				   }
				       
				   break;
			case '3':
			 	if (!Work ) 
				   {
					   printf("@@����ǩ��\n\n");
					  getch();
					   break;
				   }
				if(DeleteQueue(&Q, &e))
				{
					printf("@@��%d�Ű���Ŀǰ����%d���˵ȴ�����\n\n",e,QueueLength(Q));
					  getch();
				}
					   
				   else
				   {
				   		printf("@@Ŀǰ������Ҫ����ҵ��Ĺ˿ͣ�\n\n");
				   		getch();
				   }
                       
			       break;
			case '4':
				 	if (!Work ) 
				   {
					   printf("@@����ǩ��\n\n");
					  getch();
					   break;
				   }
				   else
				   {
						clear1(&Q);
						printf("����ɹ�");
						getch();
						break;
				   }
			case '0':
				if (!Work ) 
				   {
					   printf("������ǩ����\n\n");
					  getch();
					   break;
				   }
		        if(QueueEmpty(Q))   
				{
					printf("@@ǩ�˳ɹ����ؼң�\n\n"); 
					Work=0;
					getch();
					return;
				} 
				else
				{
					printf("@@Ŀǰ����%d���ź�δ����ҵ��Ĺ˿ͣ��ݲ����°�\n\n",QueueLength(Q));
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
