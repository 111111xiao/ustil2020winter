#include<stdio.h>
#include<string.h>
#include<math.h>
#include<Windows.h>
typedef struct Student
{
	int data;
	char name[7];
	char sex[3];
	char birth[13];
	int Math;
	int English;
	int Chinese;
	struct Student* next;
}student;
void import(student* s)
{
	printf("*************\n");
	printf("请输入第学生姓名\n");
	gets(s->name);
	printf("请输入第学生性别\n");
	gets(s->sex);
	printf("请输入学生学号\n");
	scanf_s("%d", &s->data);
	getchar();
	printf("请输入学生出生日期 例：2000 00 00\n");
	gets(s->birth);
	printf("请输入学生数学成绩\n");
	scanf_s("%d", &s->Math);
	getchar();
	printf("请输入学生英语成绩\n");
	scanf_s("%d", &s->English);
	getchar();
	printf("请输入学生语文成绩\n");
	scanf_s("%d", &s->Chinese);
	getchar();
	system("cls");
}
student* main1()
{
	student* head = (student*)malloc(sizeof(student));
	student* p = head;
	for (int i = 0; i < 3; i++)
	{
		student* s = (student*)malloc(sizeof(student));
		import(s);
		p->next = s;
		s->next = NULL;
		p = p->next;
	}
	return head;
}
void add(student*head)
{
	student* s = (student*)malloc(sizeof(student));
	student* p = head;
	while( p->next != NULL)
		p = p->next;
	p->next = s;
	s->next = NULL;
	import(s);
}
int insert(student* head)
{
	char standard[7];
	printf("请输入插入位置（前位学生名字）\n");
	gets(standard);
	student* s =(student*) malloc(sizeof(student));
	s->next = NULL;
	student* p = head;
	while (strcmp(p->name,standard)&&p->next)
		p = p->next;
	if (strcmp(standard,p->name))
	{
		printf("查无此人\n");
		return 0;
	}
	if (p->next)
	{
		s->next = p->next;
		p->next=s;
		import(s);
		return 0;
	}
	else
	{
		s->next = NULL;
		p->next = s;
		import(s);
		return 0;
	}
}
int change(student* head)
{
	student* p = head;
	student* s = (student*)malloc(sizeof(student));
	printf("请输入需要修改学生姓名\n");
	char standard[7];
	gets(standard);
	p = p->next;
	while (strcmp(standard, p->name)&&p->next)
		p = p->next;
	if (strcmp(p->next->name, standard))
	{
		printf("查无此人\n");
		return 0;
	}
	if (!(p->next))
	{
		s->next = NULL;
		p->next = s;
		import(s);
	}
	else
	{
		s->next = p->next->next;
		p->next = s;
		import(s);
	}
	return 0;
}
int load(student* head)
{
	char standard[7];
	int average,total;
	printf("请输入查找内容\n");
	gets(standard);
	student* p = head;
	while (strcmp(standard, p->name) && p->next)
		p = p->next;
	if (!(p->next))
	{
		printf("查无此人\n");
		return 0;
	}
	total = (p->Chinese) + (p->English) + (p->Chinese);
	printf("正在读取\n");
	Sleep(2000);
	printf("****************\n该学生平均成绩为%d 总成绩为%d\n", total / 3, total);
	return 0;
}
void displaylist(student* head)
{
	int i=1;
	student* p = head;
	while ( p->next)
	{
		p = p->next;
		printf("*************\n");
		printf("第%d个学生的信息是\n",i++);
		puts(p->name);
		puts(p->sex);
		printf("%d\n", p->data);
		puts(p->birth);
		printf("%d\n", p->Math);
		printf("%d\n", p->English);
		printf("%d\n", p->Chinese);
	}
}
int main()
{
	student* head = main1();
	displaylist(head);
	printf("增加请按1 插入请按2 修改请按3 读取请按4 #键结束\n");
	char key = 0;
	while (1)
	{
		key=getchar();
		getchar();
		system("cls");
		if (key == '#')
			break;
		switch (key)
		{
		case '1':add(head); break;
		case '2':insert(head); break;
		case '3':change(head); break;
		case '4':load(head);
		}
		displaylist(head);
		printf("增加请按1 插入请按2 修改请按3 读取请按4 #键结束\n");
	}
	return 0;
}
