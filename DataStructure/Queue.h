#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>

typedef struct QueueNode
{
	int i_data;
	struct QueueNode* pNext;
}QUEUENODE, * PQUEUENODE;

typedef struct LinkQueue          //动态队列
{
	PQUEUENODE pFront;          //队头
	PQUEUENODE pRear;          //队尾
}LINKQUEUE, * PLINKQUEUE;

typedef struct CircularQueue          //静态队列(循环队列)
{
	int* pBase;          //队列地址
	int front;          //队头
	int rear;          //队尾
	int len;          //队列长度
}CIRCULARQUEUE, * PCIRCULARQUEUE;

void init_queue(PCIRCULARQUEUE pQueue);          //初始化

bool queue_is_full(PCIRCULARQUEUE pQueue);          //为满
bool queue_is_empty(PCIRCULARQUEUE pQueue);          //为空

bool push_queue(PCIRCULARQUEUE pQueue, int val);          //入队

bool pop_queue(PCIRCULARQUEUE pQueue);          //出队
void show_queue(PCIRCULARQUEUE pQueue);          //显示

#endif //! __STACK_H__
