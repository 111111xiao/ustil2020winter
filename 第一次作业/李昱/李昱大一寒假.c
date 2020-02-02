//顺序队列
#include<stdio.h>
int enQueue(int* a, int rear, int date)
{
	a[rear] = date;
	rear++;
	return rear;
}
void deQueue(int* a, int front, int rear)
{
	//如果front==rear，表示队列为空
	while (front != rear)
	{
		printf("出队元素：%d\n", a[front]);
		front++;
	}
}
int main()
{
	int a[100];
	int front, rear;
	//设置队头指针和尾指针，当队列中没有元素时，
	//队头和队尾指向同一块地址
	front = rear = 0;
	//入队
	rear = enQueue(a, rear, 1);
	rear = enQueue(a, rear, 2);
	rear = enQueue(a, rear, 3);
	rear = enQueue(a, rear, 4);
	//出队
	deQueue(a, front, rear);
	return 0;
}

//循环队列
#include<iostream>
#define MAXSIZE 5//最大队列长度
using namespace std;
template<class T>
class RQueue
{
public:
	RQueue()
		:_base(NULL)
		, _front(0)
		, _rear(0)
	{
		_base = (T*)malloc(MAXSIZE * sizeof(T));
		if (!_base)
		{
			cout << "开辟空间失败" << endl;

		}
	}
	//返回队列元素个数
	int Length()
	{
		return(_rear - _front + MAXSIZE) % MAXSIZE

	}
	//插入元素
	bool Insert(const T& x)
	{
		if ((_rear + 1) % MAXSIZE == _front)//队列满
		{
			cout << "队列已满！" << endl;
			return false;
		}
		_base[_rear] = x;
		_rear = (_rear + 1) % MAXSIZE;
		return ture;
	}
private:
	T* _base;//初始化的动态分配储存空间
	int _front;//头指针，若队列不空，指向队列头元素
	int _rear;//尾指针，若队列不空，指向队列尾元素的下一个位置
};

//单向链表
struct link
{
	int date;
	struct link* next;
};
//数据域：data    用来存储节点数据
//指针域：struct link*next   用来存储下一个节点的地址
main()
{
	int i = 0;
	char c;
	Queue q;//链式队列首尾指针和长度
	q.front = q.rear = NULL;//首尾指针初始化
	q.length = 0;//链式队列长度初始化
	q = init(q);//初始化队列
	printf("Do you want to append a new node(Y/N)?");
	scanf_s("%c", &c);
	while (c == 'Y' || c == 'y')
	{
		q = AppendNode(q);//入队列
		DisplyNode(q);//按先进先出对队列进行打印
		printf("Do you want to delete node(Y/N)?");
		scanf_s("%c", &c);
		while (c == 'Y' || c == 'y')
		{
			q = DeletNode(q);
			DisplyNode(q);
			printf("Do you want to delete node(Y/N)?");
			scanf_s("%c", &c);

		}
		return 0;


	}

	//初始化队列和入队列---实现代码
	//函数功能：初始化队列（其实就是拿个头节点放在队列里面）
	//单独拿个子函数来初始化队列是为了方便入队列的时候判断队列是否为空
	Queue init(Queue p)
	{
		p.front = p.rear = (Node*)malloc(sizeof(Node));
		if (p.front == NULL && p.rear == NULL)
		{
			printf("initialization failed");
			exit(0);

		}
		p.front->next = NULL;
		return p;
	}
	//函数功能：新建节点并添加到队列中，记录队列长度
	Queue AppendNode(Queue p)
	{
		int data;
		Node* q;
		q = (Node*)malloc(sizeof(Node));
		if (q == NULL)//判断分配内存是否失败
		{
			printf("No enough memory to allocate");
			exit(0);

		}
		p.rear->next = q;
		//最后一个节点的指针指向新建节点
		p.rear = q;
		//队尾指针指向新建节点
		printf("Input node data\n");
		scanf("%d", &data);
		p.rear->next = NULL;
		p.length++;
		return p;
	}
	//分析出队时首尾指针的变化，
	//出队时要用到判断队列是否为空的一个子函数
	int IsemptyQueue(Queue p)
	{
		if (p.front == p.rear)
			//队首指针和队尾指针重合队列为空

		{
			return Empty;

		}
		else
		{
			return NoEmpty;
		}
	}
	//出队实现代码
	Queue DeletNode(Queue p)
	{
		Node* del;
		if (IsemptyQueue(p) == Empty)
			//判断队列是否为空
		{
			printf("队列为空，无法出队");
			return p;

		}
		else //队列不为空
		{
			if (p.front->next == p.rear)
				//如果出队的节点为最后一个节点
			{
				printf("出队节点的数据为%d----"，p.rear->data);
				free(p.rear);
				//释放最后一个节点
				p.rear = p.front;
				//队首指针和队尾指针都指向头节点
			
				p.front->next = NULL;
				p.length--;
			}
			else
			{
				del = p.front->next;
             printf("出队节点的数据为%d----", del->data);
			 p.front->next = p.front->next->next;
			 //使头节点的指针域指向出队列节点的下一个节点
			 free(del);
			 //释放出队的节点
			 p.lengh--;
			}
			return p;

		}
	}
		
}
