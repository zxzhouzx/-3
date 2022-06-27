#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
int Y;
int language()
{
	int m;
	scanf("%d",&m);
	getchar();
	if (m)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}
struct Account
{
	char name[100];//����
	char username[100];//�˻�
	char password[100];//����
	char idCard[100];//���֤
	char phone[100];//�绰����
	float money;

	struct Account *next;
};

typedef struct Account Account;

Account *head = NULL;
Account *tail = NULL;

void getpasswd(Account* pa)
{
	

	char c;
	int i = 0;
	while ((c = getch()) != '\r')
	{
		if (c == '\b')
		{
			pa->password[--i] = NULL;
			printf("\b");
			printf(" ");
			printf("\b");
			
		}
		else
		{
			pa->password[i] = c;
			putchar('*');
			i++;
		}
		
		
	}
		pa->password[i]='\0';
		if (Y)
		{
			printf("\n---����ɹ����س�����---");
		}
		else
		{
			printf("\n---Enter successfully, press Enter to continue---");
		}
	return;

}

void addNode(Account *node)//Account���������
{
	node->next = NULL;
	if (head == NULL)
	{
		head = node;
		tail = node;
	}
	else
	{
		tail->next = node;
		tail = node;
	}
}


struct TransactionRecord   //���׼�¼
{
	char username[100];
	time_t timestamp;//ʱ��� 
	char type[20];//��������
	float amount;//���� 
	float money;//��ǰ���

	struct TransactionRecord * next;
};
typedef struct TransactionRecord TR;

TR * trHead = NULL;
TR * trTail = NULL;

void addNodeTR(TR *oNode)//TR���������
{
	oNode->next = NULL;
	if (trHead == NULL)
	{
		trHead = oNode;
		trTail = oNode;
	}
	else
	{
		trTail->next = oNode;
		trTail = oNode;
	}
}


int init()
{
	FILE* fp = fopen("D:\\VS2015\\atm.txt", "r");
	FILE* fp2=fopen("D:\\VS2015\\transation_record.txt", "r");
	if ((fp == NULL)&&(fp2==NULL))
	{
		return 0;
	}

	else {
				while (!feof(fp))//���ļ��������д���ṹ��������
				{
					//����һ���ڴ�ռ䣬Ȼ��ѵ�ַ��ֵ��ָ��newNodeP 
					Account * newNodeP = (Account *)malloc(sizeof(Account));
					fscanf(fp, "%s %s %s %s %s %f\n", newNodeP->name, newNodeP->username, newNodeP->password, newNodeP->idCard, newNodeP->phone, &newNodeP->money);

					addNode(newNodeP);
				}
				while (!feof(fp2))
				{
					TR * newNodeTr=(TR *)malloc(sizeof(TR));
					fscanf(fp2, "%s %ld %s %f %f\n", newNodeTr->username, &newNodeTr->timestamp, newNodeTr->type, &newNodeTr->amount,&newNodeTr->money);

					addNodeTR(newNodeTr);
				}
				return 1;
				fclose(fp);
				fclose(fp2);
		}
}


void printLinkedList()//��������������
{
	Account *curP = head;
	TR* curP1 = trHead;
	while (curP != NULL)
	{
			if (Y)
			{
			printf("����:%-10s�˺�:%-10s����:%-10s���֤:%-25s�绰:%-12s���:%f\n"
			, curP->name, curP->username, curP->password, curP->idCard, curP->phone, curP->money);
			}
			else
			{
			printf("name:%-10s ID:%-10s password:%-10s identity card:%-25s phone:%-12s balance:%f\n"
			, curP->name, curP->username, curP->password, curP->idCard, curP->phone, curP->money);
			}
			
		
		curP = curP->next;
	}
	while (curP1 != NULL)
	{
		if (Y)
		{
			printf("�˺ţ�%s\tʱ�䣺%ld\t�������ͣ�%s\t���׽�%f\tʣ���%f\n", curP1->username, curP1->timestamp, curP1->type, curP1->amount,curP1->money);
		}
		else
		{
			printf("ID��%s\t time��%ld\t trade type��%s\t transaction amount��%f\t balance��%f\n", curP1->username, curP1->timestamp, curP1->type, curP1->amount,curP1->money);
		}

		curP1 = curP1->next;
	}
}

void exitFunction()//�������������д��atm.txt�ļ���
{
	FILE* fp = fopen("D:\\VS2015\\atm.txt", "w");
	Account * curP = head;
	while (curP != NULL)
	{
		fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%f\n", curP->name, curP->username, curP->password, curP->idCard, curP->phone, curP->money);
		curP = curP->next;
	}
	fclose(fp);
}

void saveTransactionRecord()//���׼�¼�洢���ļ�transation_record.txt��
{
	FILE* fP = fopen("D:\\VS2015\\transation_record.txt", "w");
	TR* curP = trHead;
	while (curP != NULL)
	{
		fprintf(fP, "%s\t%ld\t%s\t%f\t%f\n", curP->username, curP->timestamp, curP->type, curP->amount,curP->money);
		curP = curP->next;
	}
	fclose(fP);
}



void signUp()//����
{
	Account * newNodeP = (Account *)malloc(sizeof(Account));
		if (Y)
		{
			printf("����������:\n");
			scanf("%s", newNodeP->name);

			printf("�������ʺ�:\n");
			scanf("%s", newNodeP->username);

			printf("����������:\n");
			scanf("%s", newNodeP->password);

			printf("���������֤����:\n");
			scanf("%s", newNodeP->idCard);

			printf("������绰����:\n");
			scanf("%s", newNodeP->phone);
			getchar();

			newNodeP->money = 0.0f;

			addNode(newNodeP);

			printf("�����ɹ���\n");
		}
		else
		{
			printf("Please enter your name:\n");
			scanf("%s", newNodeP->name);

			printf("Please enter the account number:\n");
			scanf("%s", newNodeP->username);

			printf("enter your PIN:\n");
			scanf("%s", newNodeP->password);

			printf("please enter your ID number:\n");
			scanf("%s", newNodeP->idCard);

			printf("Please enter your phone number:\n");
			scanf("%s", newNodeP->phone);
			getchar();

			newNodeP->money = 0.0f;

			addNode(newNodeP);

			printf("for user admin��\n");
		}
	
	system("pause");
	getchar();
	system("cls");
}
Account * curAccount = NULL;//ָ��ǰ��¼�˻���ָ�� 
int findAccount(Account a)//�жϵ�½�˻��Ƿ����
{
	Account *curP = head;
	while (curP != NULL)
	{
		if ((strcmp(curP->username, a.username) == 0) && (strcmp(curP->password, a.password) == 0))
		{
			curAccount = curP;
			return 1;
		}
		curP = curP->next;
	}
	return 0;
}

void updatePassword()//�����޸ĺ���
{
		if (Y)
		{
			printf("�����������:\n");
			char oldPassword[100] = { '\0' };
			scanf("%s", oldPassword);
			if (strcmp(oldPassword, curAccount->password) == 0)
			{
				//�����޸� 
				printf("�����������룺\n");
				scanf("%s", curAccount->password);
				getchar();
				printf("�޸ĳɹ���\n");
			}
			else
			{
				printf("������������󣬾ܾ��޸ģ�\n");
			}
		}
		else
		{
			printf("Please importation of old passwords:\n");
			char oldPassword[100] = { '\0' };
			scanf("%s", oldPassword);
			if (strcmp(oldPassword, curAccount->password) == 0)
			{
				//�����޸� 
				printf("please enter new password��\n");
				scanf("%s", curAccount->password);
				printf("modify successfully��\n");
			}
			else
			{
				printf("The old password is incorrect and cannot be changed��\n");
			}
		}
		getchar();
		system("cls");
	
}

void homePage()
{
	system("cls");
	updatePassword();
}



void saveMoney()//����
{
		float money;
		if (Y)
		{
			printf("�������Ǯ��");
			scanf("%f", &money);
			getchar();
			curAccount->money += money;
			printf("���ɹ���\n");
		}
		else
		{
			printf("Please enter the deposit amount��");
			
			scanf("%f", &money);
			getchar();
			curAccount->money += money;
			printf("Deposit successfully��\n");
		}
		getchar();
		system("cls");
	

		exitFunction();//�������ݣ�Account��

		TR *newNode = (TR *)malloc(sizeof(TR));

		char t[20] = { "���/����" };

		strcpy(newNode->username, curAccount->username);
		strcpy(newNode->type, t);        //��¼��������
		newNode->amount = money;         //��¼���׽��
		newNode->timestamp = time(NULL); //��¼��ǰʱ���
		newNode->money=curAccount->money;//���浱ǰ���

		addNodeTR(newNode);     //�������ӣ�TR��
		saveTransactionRecord();//�������ݣ�TR��
	
}

void drawMoney()//ȡ���
{
	if (Y)
	{
		printf("������ȡ����:");
	}
	else
	{
		printf("Please enter the withdrawal amount:");
	}
	
	float money;
	scanf("%f", &money);
	getchar();

	if (money>curAccount->money)
	{
		if (Y)
		{
			printf("---���㣡---");
		}
		else
		{
			printf("---insufficient fund��---");
		}
		
	}
	else
	{
		curAccount->money = curAccount->money - money;
		if (Y)
		{
			printf("---ȡ��ɹ���---\n");
		}
		else
		{
			printf("---Withdrawals success��---\n");
		}
		getchar();
		system("cls");

		exitFunction();   //�������ݣ�Account��

		TR *newNode = (TR *)malloc(sizeof(TR));
		char t[20] = { "ȡ��/֧��" };
		strcpy(newNode->username, curAccount->username);
		strcpy(newNode->type, t);          //��¼��������
		newNode->amount = money;           //��¼���׽��
		newNode->timestamp = time(NULL);   //��¼��ǰʱ���
		newNode->money=curAccount->money;  //���浱ǰ���

		addNodeTR(newNode);     //�������ӣ�TR��
		saveTransactionRecord();//�������ݣ�TR��
		return;
		
	}
}

Account * findOtherAccount(char otherUsername[])
{
	Account * curp = head;
	while (curp != NULL)
	{
		if (strcmp(curp->username, otherUsername) == 0)
		{
			return curp;
		}
		curp = curp->next;
	}
	return NULL;
}


void transfer()
{
	if (Y)
	{
		printf("������Է��˻���");
	}
	else
	{
		printf("Please enter your account��");
	}
	char otherUsername[100];
	scanf("%s", otherUsername);
	Account * otherAccont = findOtherAccount(otherUsername);
	if (otherAccont == NULL)
	{
		if (Y)
		{
			printf("�˻������ڣ�\n");
		}
		else
		{
			printf("Account does not exist��\n");
		}
		
	}
	else
	{
		while(1)
		{
			if (Y)
			{
				printf("������ת�˽�");
			}
			else
			{
				printf("Please enter the transfer amount��");
			}
			
			int money;
			scanf("%d", &money);
			getchar();

			if(money>curAccount->money)
			{
				if (Y)
				{
				printf("��ǰ�˻����㣡\n");
				}
				else
				{
				printf("The current account balance is insufficient��\n");
				}
				getchar();
				system("cls");
			}
			else
			{
		
				//��ǰ�˻����仯������ 
				curAccount->money = curAccount->money - money;
				//�Է��˻����仯������
				otherAccont->money = otherAccont->money + money;


				if (Y)
				{
					printf("ת�˳ɹ���\n");
				}
				else
				{
					printf("Transfer success��\n");
				}
				getchar();
				system("cls");
				

				exitFunction();//�������ݣ�Account��

				TR *newNode = (TR *)malloc(sizeof(TR));

				char t[20] = { "ת��/ת��" };

				strcpy(newNode->username, curAccount->username);
				strcpy(newNode->type, t);        //��¼��������
				newNode->amount = money;         //��¼���׽��
				newNode->timestamp = time(NULL); //��¼��ǰʱ���
				newNode->money = curAccount->money;//���浱ǰ���

				addNodeTR(newNode);     //�������ӣ�TR��

				TR *newNode1 = (TR *)malloc(sizeof(TR));
				char other[20] = { "ת��/ת��" };

				strcpy(newNode1->username, otherAccont->username);
				strcpy(newNode1->type, other);        //��¼��������
				newNode1->amount = money;             //��¼���׽��
				newNode1->timestamp = time(NULL);     //��¼��ǰʱ���
				newNode1->money = otherAccont->money; //���浱ǰ���

				addNodeTR(newNode1);     //�������ӣ�TR��
				saveTransactionRecord();//�������ݣ�TR��
				break;
			}
		}

	}


}



void signIn() //��¼����
{
	for (int i = 0; i<3;i++)
	{

		Account a;
		if (Y)
		{
			printf("---��ӭ��¼---\n");
			printf("�������˺ţ�");
			scanf("%s", a.username);
			getchar();

			printf("���������룺");
		}
		else
		{
			printf("---Welcome to Log on---\n");
			printf("Please enter mail account username��");
			scanf("%s", a.username);
			getchar();

			printf("enter your PIN��");
		}
		
		//scanf("%s", a.password);
		
		getpasswd(&a);
		getchar();
		system("cls");
		printf("---��¼�ɹ���---\n");
		getchar();
		while (1)
		{
			if (findAccount(a))
			{
				
				if (Y)
				{
					system("cls");
					printf("---��1���޸�����---\n");
					printf("---��2����Ҫȡ��---\n");
					printf("---��3����Ҫ���---\n");
					printf("---��4����Ҫת��---\n");
					printf("---��5���˳���¼---\n");
				}
				else
				{
					system("cls");
					printf("---login successfully��---\n");
					printf("---��1��change password---\n");
					printf("---��2��Need to withdraw money---\n");
					printf("---��3��liquid funds---\n");
					printf("---��4��Need to transfer---\n");
					printf("---��5��Logout---\n");
				}
				
				int iIint;
				scanf("%d", &iIint);
				getchar();
				if (iIint == 1)
				{
					system("cls");
					homePage();  //�޸�����
				}
				else if (iIint == 2)
				{
					system("cls");
					drawMoney(); //ȡ��
				}
				else if (iIint == 3)
				{
					system("cls");
					saveMoney(); //���
				}
				else if (iIint == 4)
				{
					system("cls");
					transfer();//ת��
				}
				else if (iIint == 5)
				{
					system("cls"); return;
				}
			}
			else
			{
				if (Y)
				{
					printf("---��¼ʧ��!---\n");
				}
				else
				{
					printf("---Logon failed!---\n");
				}
				getchar();
				system("cls");
				break;
			
			}
		}
		
	}

}



int main()
{
	system("color f4");
	printf("************************\n");
	printf("********��ӭʹ��********\n");
	printf("************************\n");
	printf("\033[30;05;37m*****�����������*****\033[0m\r\n");
	getchar();
	system("color f4");
	system("cls");
	printf("***��1������(Chinese)***\n");
	printf("\n");
	printf("***��0��Ӣ��(English)***\n");
	printf("\n");
	Y=language();
	system("cls");
	int q = init();
	if (Y)
	{
		if (q == 0)
		{
			printf("---����ʧ�ܣ�---\n");
		}
		else
		{
			printf("---���سɹ���---\n");
		}
	}
	else
	{
		if (q == 0)
		{
			printf("---Load Fail��---\n");
		}
		else
		{
			printf("---onload Function��---\n");
		}
	}
	
	char c;
	while (1)
	{
		if (Y)
		{
			printf("---��1������---\n");
			printf("---��2����¼---\n");
			printf("---��3���˳�---\n");
		}
		else
		{
			printf("---��1��open an account---\n");
			printf("---��2��Login---\n");
			printf("---��3��exit---\n");
		}
		scanf("%c", &c);
		getchar();

		switch (c)
		{
			case '1':system("cls");signUp(); break;
			case '2':system("cls");signIn(); break;
			case '3':
			{
				system("cls");
				printLinkedList();
				saveTransactionRecord();
				exitFunction();
				system("pause");
				exit(NULL);
			}
		}
	}

	return 0;
}
