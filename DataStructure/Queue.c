#include "Queue.h"

void init_queue(PCIRCULARQUEUE pQueue)
{
	printf_s("�½����еĳ��ȣ�");
	scanf_s("%d", &pQueue->len);

	pQueue->pBase = (int*)malloc(sizeof(int) * pQueue->len);
	if (NULL == pQueue->pBase)
	{
		printf_s("��̬�ڴ����ʧ�ܣ�\n");
		return;
	}
	else
	{
		pQueue->front = 0;
		pQueue->rear = 0;
	}

}

bool queue_is_full(PCIRCULARQUEUE pQueue)
{
	if ((pQueue->rear + 1) % pQueue->len == pQueue->front)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool queue_is_empty(PCIRCULARQUEUE pQueue)
{
	if (pQueue->rear == pQueue->front)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool push_queue(PCIRCULARQUEUE pQueue, int val)
{
	if (queue_is_full(pQueue))
	{
		printf_s("���ʧ�ܣ���Ϊ����\n");
		return false;
	}
	else
	{
		pQueue->pBase[pQueue->rear] = val;
		pQueue->rear = (pQueue->rear + 1) % pQueue->len;

	}
	return false;
}

bool pop_queue(PCIRCULARQUEUE pQueue)
{
	if (queue_is_empty(pQueue))
	{
		printf_s("����ʧ�ܣ���Ϊ�գ�\n");
		return false;
	}
	else
	{
		pQueue->front = (pQueue->front + 1) % pQueue->len;
	}
	return false;
}

void show_queue(PCIRCULARQUEUE pQueue)
{
	int temp = pQueue->front;
	while (temp != pQueue->rear)
	{
		if(temp == pQueue->front)
		{
			printf_s("�ӣ�%d(��ͷ)", pQueue->pBase[temp]);
		}
		else
		{
			printf_s(",%d", pQueue->pBase[temp]);
		}

		temp = (temp + 1) % pQueue->len;
	}
	printf_s("\n");
	return;
}
