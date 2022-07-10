#include <conio.h>
#include <stdlib.h>
#include "menu.h"
#define MAXQSIZE 101//ʵ�ʿ���100����������һ���ռ�


int work=0;//����Ƿ�ǩ���ϰ� 
typedef int ElemType;
typedef struct QNode
{
	ElemType data;//������ 
	struct QNode *next;//ָ���� 
} QNode,*LQueue;
typedef struct
{
	LQueue front; //��ͷָ��
	LQueue rear; //��βָ��
} LinkQueue;

int QueueEmpty1(LinkQueue Q) //������QΪ�ն��У��򷵻�1,���򷵻�0
{
	if(Q.front == NULL)
		return 1;
	else
		return 0;
}

void InitQueue1(LinkQueue *Q) //���г�ʼ����ͬʱ�ñ�Ǳ���work���Ϊ1��
{
	Q->front=NULL;
	Q->rear=NULL;
	work=1;
}


int PushQueue1(LinkQueue *Q, ElemType e) //����Ԫ��eΪQ���µĶ�βԪ��
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


int DeQueue1(LinkQueue *Q, ElemType *e) //Ԫ��e���ӣ�����e������
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

int GetHead1(LinkQueue Q, ElemType *e) //��ö�ͷԪ��,������1�����򷵻�0
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

int QueueLength1(LinkQueue Q) //����г���
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

int clear(LinkQueue *Q)//��ն��� 
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


void Lque()//��ʽ 
{
	void Menu();
	int QueueEmpty1(LinkQueue Q);
	int PushQueue1(LinkQueue *Q,ElemType e);
	int DeQueue1(LinkQueue *Q,ElemType *e);
	void InitQueue1(LinkQueue *Q);
	int GetHead1(LinkQueue Q,ElemType *e);
	int QueueLength1(LinkQueue Q);
	
	system("cls"); 
	int num=0;//���ŵ���� 
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
			       printf("@@ǩ���ɹ�����ʼ�ϰ�\n\n");
			       getch();
//			       system("pause");
				break;
			case '2':
				if (!work ) 
				   {
					   printf("@@����ǩ��\n\n");
					   getch();
					   break;
				   }
				   else
				   {
				   		PushQueue1(&Q, ++num) ;
						printf("@@��ǰ��%d�ţ�ǰ�滹��%d�˵ȴ���\n\n",num,QueueLength1(Q)-1);
						getch();
								       
					   break;
				   }

			case '3':
			 	if (!work ) 
				   {
					   printf("@@����ǩ��\n\n");
					  getch();
					   break;
				   }
				   else
				   {
						if(DeQueue1(&Q, &e))
						{
							printf("@@��%d�Ű���Ŀǰ����%d���˵ȴ�����\n\n",e,QueueLength1(Q));
							  getch();
						}
							   
						   else
						   {
						   		printf("@@Ŀǰ������Ҫ����ҵ��Ĺ˿ͣ�\n\n");
						   		getch();
						   }
		                       
					       break;
				   }
			case '4':
				 	if (!work ) 
				   {
					   printf("@@����ǩ��\n\n");
					  getch();
					   break;
				   }
				   else
				   {
						clear(&Q);
						printf("����ɹ�");
						getch();
						break;
				   }

			case '0':
				if (!work ) 
				   {
					   printf("������ǩ����\n\n");
					  getch();
					   break;
				   }
				   else
				   {
				        if(QueueEmpty1(Q))   
						{
							printf("@@ǩ�˳ɹ����ؼң�\n\n"); 
							work=0;
							getch();
							return;
						} 
						else
						{
							printf("@@Ŀǰ����%d���ź�δ����ҵ��Ĺ˿ͣ��ݲ����°�\n\n",QueueLength1(Q));
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
