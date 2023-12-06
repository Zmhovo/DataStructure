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

typedef struct LinkQueue          //��̬����
{
	PQUEUENODE pFront;          //��ͷ
	PQUEUENODE pRear;          //��β
}LINKQUEUE, * PLINKQUEUE;

typedef struct CircularQueue          //��̬����(ѭ������)
{
	int* pBase;          //���е�ַ
	int front;          //��ͷ
	int rear;          //��β
	int len;          //���г���
}CIRCULARQUEUE, * PCIRCULARQUEUE;

void init_queue(PCIRCULARQUEUE pQueue);          //��ʼ��

bool queue_is_full(PCIRCULARQUEUE pQueue);          //Ϊ��
bool queue_is_empty(PCIRCULARQUEUE pQueue);          //Ϊ��

bool push_queue(PCIRCULARQUEUE pQueue, int val);          //���

bool pop_queue(PCIRCULARQUEUE pQueue);          //����
void show_queue(PCIRCULARQUEUE pQueue);          //��ʾ

#endif //! __STACK_H__
