#include <stdio.h>
#include <stdlib.h>
#include "Squeue.h"
#include "Lqueue.h" 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	void Lque();
	void Sque();
	void chose();
	
	
	char chos;
		while(1)
		{
			chose();
			scanf("%c",&chos);
			switch(chos)
			{
				case '1':
					Lque();//��ʽ 
					continue;
				case '2':
					Sque();//˳�� 
					continue;
				case '0'://�˳� 
					exit('0');
				default:
					system("cls");
					continue;
			}
			
		}
		return 0;
}
