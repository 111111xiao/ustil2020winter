#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct QNode {
	int data;
	struct QNode* next;
}QNode;

QNode* initQueue() {//创建
	QNode* queue = (QNode*)malloc(sizeof(QNode));
	queue->next = NULL;
	return queue;
}

void enQueue(QNode* rear, int data) {
	QNode* enElem = (QNode*)malloc(sizeof(QNode));
	printf("请输入入队的一个数据(对，只能一个）：");
	scanf_s("%d", &data);
	enElem->data = data;
	enElem->next = NULL;
	/*使用尾插法向链队列中添加元素*/
	rear->next = enElem;
	rear = enElem;
}

QNode* DeQueue(QNode* top, QNode* rear) {

	if (top->next == NULL) {
		printf("队列为空");
		return rear;
	}
	QNode* p = top->next;
	printf("%d ", p->data);
	top->next = p->next;
	if (rear == p) {
		rear = top;
	}
	free(p);
	return rear;
}

QNode* DeleteNode(QNode*list) {
	QNode* temp = list;
	printf("输入你想要删除的数据位置：");
	int n;
	scanf_s("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		temp = temp->next;
	}
	QNode* Delete = temp->next;
	temp->next = temp->next->next;
	free(Delete);
}

void ChangeNode(int data,QNode* queue) {
	int index=0;
	QNode* p = queue;
	printf("请输入您要修改的数据 : ");
	gets(data);
	if (SearchIndex(data, queue, &index) == 0)
		printf("没有此数据\n");
	else {
		while (index > 0) {
			index--;
			p = p->next;
		}

		printf("请输入修改后的数据: \n");
	}

}

int SearchIndex(int data, QNode* queue,int*index) {
	QNode* p = queue;
	while (p->next) {
		p = p->next;
		(*index)++;
		if (p->data==data)
			return 1;
	}
	return 0;
}

void Search(int data,QNode*queue) {
	printf("请输入您要查找的一个数据：");
	scanf_s("%d", &data);
	int index = 0;
	if (SearchIndex(data, queue,&index) == 0)
		printf("未查询到该数据! \n");
	else
		printf("队列中有该数据！\n");

}

void Selection(int data, QNode * queue, QNode * top, QNode * rear) {
		switch (data)
		{
		case 1:
			system("cls");
			enQueue(rear, data);
			break;
		case 2:
			system("cls");
			DeleteNode(queue);
			break;
		case 3:
			system("cls");
			ChangeNode(data,queue);
			break;
		case 4:
			system("cls");
			Search(data,queue);
			break;
		case 5:
			system("cls");
			rear = DeQueue(top, rear);
			break;
		case 6:
			break;
		default:
			printf("请正确输入操作指令\n");
			break;
		}
}

void pause() {
	system("pause");
	system("cls");
}

void UserInterface() {
	printf("请输入按键执行链表的操作 : \n");
	printf("输入 1 进行 增加 操作 : \n");
	printf("输入 2 进行 删除 操作 : \n");
	printf("输入 3 进行 修改 操作 : \n");
	printf("输入 4 进行 查找 操作 : \n");
	printf("输入 5 进行 遍历 操作 : \n");
	printf("输入 6 关闭程序 : \n");
	printf("  链表管理系统 >  ");
}

void List() {
	QNode* queue, * top, * rear;
	queue = top = rear = initQueue();
	int x,data=0;
	UserInterface();
	while (~scanf_s("%d", &x)) {
		getchar();
		if (6 == x)
			break;
		Selection(x, queue,top,rear);//调用函数
		pause();//y
		UserInterface();//y
	}
}

int main() {
	List();
	return 0;
}
