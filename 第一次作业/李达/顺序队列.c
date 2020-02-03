#define maxSize 100
typedef int elemType;
typedef struct MyStruct
{
	int date[maxSize];
	int front;
	int rear
}myStruct;

int increaseQueue(myStruct *Q, int a)
{
	if (Q->front == (Q->rear + 1) % maxSize)
		return 0;
	Q->date[Q->rear++] = a;
	return 1;
}

int deleteQueue(myStruct* Q)
{
	if (Q->front == Q->rear)
		return 0;
	free(Q->date[Q->rear--]);	
	return 1;
}

int change(myStruct* Q, int purpose, int aim)
{
	int index=0;
	if (Q->date[index] != aim && index < Q->rear)
		index++;
	if (Q->date[index] != aim)
		return 0;
	Q->date[index] = purpose;
	return 1;
}

int checkQueue(myStruct* Q, int aim)
{
	if (aim >= Q->rear)
		return 0;
	return Q->date[aim];
}

int main()
{
	myStruct *Q;
	Q->front = Q->rear = 0;
	printf("入列请按1 出列请按2 修改请按3 插入请按4\n");
	int order;
	scanf_s("%d", &order);
	int result;
	switch (order)
	{
	case 1: int standard; printf("请输入增加内容\n"); scanf_s("%d", &standard); 
		if (!increaseQueue(&Q, standard))
			printf("数列已满");
		break;
	case 2:deleteQueue(&Q); break;
	case 3:int standard, aim, purpose; printf("请输入要修改的内容\n"); scanf_s("%d", &aim); printf("请输入新的内容\n"); scanf_s("%d", &purpose);
		if (!changeQueue(&Q, purpose, aim))
			printf("请重试\n");
		break;
	case 4:printf("请输入要查找项目序号"); int aim; scanf_s("%d", &aim);
		if (!checkQueue(&Q, aim))
			printf("请重试\n");
		printf("%d", checkQueue(&Q, aim)); return 0;
	}
	return 0;
}
