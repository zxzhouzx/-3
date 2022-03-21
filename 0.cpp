#include<stdio.h>
#include<string.h>
void main()
{
	char a[100];
	char b[100];
	char *p=a;
	int c=0;
	printf("请输入字符串:");
	gets(a);
	strlwr(a);
	printf("\n");
	printf("请输入你想要查找的内容:");
	gets(b);
	printf("\n");
	while((p=strstr(p,b))!=NULL)
	{
        c++;
		p++;
	}
	printf("查找内容的个数为:%d\n",c);
 }

