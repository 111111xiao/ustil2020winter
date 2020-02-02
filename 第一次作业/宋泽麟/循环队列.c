#include<stdio.h>
#define max 5
int enQueue(int* a, int front, int rear,int data) {
	/*如果rear超过max大小，则直接将从a[0]重新开始存储，如果rear+1和front重合，则表示数据已满*/
	if ((rear + 1) % max == front) {
		printf("空间已满");
		return rear;
	}
	a[rear % max] = data;
	rear++;
	return rear;
}
int deQueue(int* a, int front, int rear) {
	/*如果front==rear队列为空*/
	if (front == rear%max) {
		printf("队列为空");
		return front;
	}
	printf("%d ", a[front]);
	/*如果不是直接+1，而是+1后同max进行比较，如果=max，直接跳转到a[0]*/
	front = (front + 1) % max;
	return front;
}
int main() {
	int a[max];
	int front, rear;
	front = rear = 0;
	/*入队*/
	    rear = enQueue(a, front, rear, 1);
		rear = enQueue(a, front, rear, 2);
		rear = enQueue(a, front, rear, 3);
		rear = enQueue(a, front, rear, 4);
		/*出队*/
		front = deQueue(a, front, rear);
		/*入队*/
		rear = enQueue(a, front, rear, 5);
		/*出队*/
		front = deQueue(a, front, rear);
		/*入队*/
		rear = enQueue(a, front, rear, 6);
		/*出队*/
		front = deQueue(a, front, rear);
		front = deQueue(a, front, rear);
		front = deQueue(a, front, rear);
		front = deQueue(a, front, rear);
	return 0;
}
