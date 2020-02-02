#include<stdio.h>
#include<stdlib.h>
typedef struct QNode {
	int data;
	struct QNode* next;
}QNode;
QNode*initQueue(){
	QNode* queue = (QNode*)malloc(sizeof(QNode));
	queue->next = NULL;
	return queue;
}
QNode* enQueue(QNode* rear, int data) {//入队
	QNode*enElem= (QNode*)malloc(sizeof(QNode));//Elem 元素
	enElem->data = data;
	enElem->next = NULL;
	/*使用尾插法向链队列中添加元素*/
	rear->next = enElem;
	rear = enElem;
	return rear;
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
int main() {
	QNode* queue, * top, * rear;
	queue = top = rear = initQueue();
	int x, t, data;
	scanf_s("%d", &x);
	for (t = 0; t < x; t++) {
		scanf_s("%d", &data);
		rear = enQueue(rear, data);
	}
	for (t = 0; t <= x/*体现出队列为空所以有“=”*/; t++) {
		rear = DeQueue(top, rear);
	}
	return 0;
}
