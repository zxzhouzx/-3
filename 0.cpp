#include<stdio.h>
#include<string.h>
void main()
{
	char a[100];
	char b[100];
	char *p=a;
	int c=0;
	printf("�������ַ���:");
	gets(a);
	strlwr(a);
	printf("\n");
	printf("����������Ҫ���ҵ�����:");
	gets(b);
	printf("\n");
	while((p=strstr(p,b))!=NULL)
	{
        c++;
		p++;
	}
	printf("�������ݵĸ���Ϊ:%d\n",c);
 }

