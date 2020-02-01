#ifndef __SEQQUEUE_H__
#define __SEQQUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 10
typedef int datatype;      /*定义队列中数据元素的数据类型*/

typedef struct seqqueue {
	datatype data[MAXSIZE];    //用数组作为队列的储存空间
	int front, rear;     /*指示队头位置和队尾位置的指针*/
}seq_queue, * seq_pqueue;

#include "seqqueue.h"

seq_pqueue init1_seqqueue(void)     //创建队列
{
	seq_pqueue q;
	q = (seq_pqueue)malloc(sizeof(seq_queue));
	if (q == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	q->front = q->rear = MAXSIZE - 1;

	return q;
}

void init_seqqueue(seq_pqueue* Q)      //创建队列（同上）
{
	*Q = (seq_pqueue)malloc(sizeof(seq_queue));
	if ((*Q) == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	(*Q)->front = (*Q)->rear = MAXSIZE - 1;

	return;
}
//判断队列是否满
bool is_full_seqqueue(seq_pqueue q)
{
	if ((q->rear + 1) % MAXSIZE == q->front)
		return true;
	else
		return false;
}
//入队
bool in_seqqueue(datatype data, seq_pqueue q)
{
	//判断队列是否满
	if (is_full_seqqueue(q)) {
		printf("队列已满!\n");
		return false;
	}

	//入队
	q->rear = (q->rear + 1) % MAXSIZE;
	q->data[q->rear] = data;
	return true;
}
bool is_empty_seqqueue(seq_pqueue q)    //判断队列是否为空队列
{
	if (q->rear == q->front)
		return true;
	else
		return false;
}
//出队
bool out_seqqueue(seq_pqueue q, datatype* D)
{
	//判断队列是否空
	if (is_empty_seqqueue(q)) {
		printf("队列已空!\n");
		return false;
	}

	//出队
	q->front = (q->front + 1) % MAXSIZE;
	*D = q->data[q->front];

	return true;
}

void show_seqqueue(seq_pqueue q)      //从队头到队尾依次显示队列中的数据
{
	int i;
	if (is_empty_seqqueue(q))
		return;
	//非空时，从对头打印到队尾
	for (i = (q->front + 1) % MAXSIZE; i != (q->rear + 1) % MAXSIZE; i = (i + 1) % MAXSIZE)
	{
		printf("%d\t", q->data[i]);
	}
	printf("\n");
}


void free_seqqueue(seq_pqueue q)  //释放队列
{
	free(q);
}

extern seq_pqueue init1_seqqueue(void);    //创建队列
extern void init_seqqueue(seq_pqueue* Q);    //创建队列（同上）
extern bool is_full_seqqueue(seq_pqueue q);   //判断队列是否为满队列
extern bool is_empty_seqqueue(seq_pqueue q);    //判断队列是否为空队列
extern bool in_seqqueue(datatype data, seq_pqueue q);    //入队
extern bool out_seqqueue(seq_pqueue q, datatype* D);   //出队
extern void show_seqqueue(seq_pqueue q);    //从队头到队尾依次显示队列中的数据
extern void free_seqqueue(seq_pqueue q);  //释放队列

#endif
