#include<stdio.h>
int enQueue(int* a, int rear, int data) {
	a[rear] = data;
	rear++;
	return rear;
}
void deQueue(int* a, int front, int rear) {
	while (front != rear)/*队列为空时*/ {
		printf("出队元素：%d\n", a[front]);
		front++;
	}
}
int main() {
	int a[100];
	int front, rear,data,t;
	front = rear = 0;
	/*入队*/
	for (t = 0; t < 100; t++) {
		scanf_s("%d", &data);
		rear = enQueue(a, rear, data);
		deQueue(a, front, rear);
	}
	return 0;
}
