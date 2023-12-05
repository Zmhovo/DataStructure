#include "Link.h"

PLINKNODE create_link()
{
	int len = 0;          //������
	int val = 0;          //��Ž����ʱ����

	PLINKNODE pHead = (PLINKNODE)malloc(sizeof(LINKNODE));          //ͷ���
	PLINKNODE pTail = pHead;          //β���

	if (NULL == pHead)
	{
		printf_s("��̬�ڴ����ʧ�ܣ�\n");
		return 0;
	}
	else
	{ 
		pTail->pNext = NULL;

		printf_s("�½�����ĳ��ȣ�");
		scanf_s("%d", &len);

		for (int i = 0; i < len; i++)
		{
			printf_s("�������%d������ֵ��", i + 1);
			scanf_s("%d", &val);

			PLINKNODE pNew = (PLINKNODE)malloc(sizeof(LINKNODE));          //��ʱ���

			if (NULL == pNew)
			{
				printf_s("��̬�ڴ����ʧ�ܣ�\n");
				exit(-1);
			}

			pNew->i_data = val;
			pTail->pNext = pNew;
			pNew->pNext = NULL;
			pTail = pNew;

		}
		return pHead;
	}
	
}


bool link_is_empty(PLINKNODE pHead)
{
	if (NULL == pHead->pNext)
	{
		printf_s("����Ϊ�գ�");
		return true;
	}
	else
	{
		return false;
	}
}


int length_link(PLINKNODE pHead)
{
	int len = 0;
	PLINKNODE pTemp = pHead->pNext;
	
	while (NULL != pTemp)
	{
		len++;
		pTemp = pTemp->pNext;
	}

	return len;
}


void show_link(PLINKNODE pHead)
{
	PLINKNODE pTemp = pHead->pNext;

	if (pTemp == NULL)
	{
		printf_s("����Ϊ�գ�\n");

		return;
	}

	while (NULL != pTemp)
	{
		if (pTemp == pHead->pNext)
		{
			printf_s("����%d", pTemp->i_data);
			pTemp = pTemp->pNext;
		}
		else
		{
			printf_s(",%d", pTemp->i_data);
			pTemp = pTemp->pNext;
		}
	}
	printf_s("\n");

	return;
}


bool insert_link(PLINKNODE pHead, int pos, int val)
{
	int len = length_link(pHead);
	if (pos > len + 1 || pos < 1)
	{
		printf_s("����ʧ�ܣ�����λ�÷Ƿ�������������1~%d��������\n", len + 1);
		return false;
	}
	else
	{
		PLINKNODE pTemp = (PLINKNODE)malloc(sizeof(PLINKNODE));
		if (NULL == pTemp) 
		{
			printf_s("��̬�ڴ����ʧ�ܣ�\n");
			return false;
		}
		else
		{
			pTemp->i_data = val;

			PLINKNODE pI = pHead;
			for (int i = 1; i < pos; i++)
			{
				pI = pI->pNext;
			}

			PLINKNODE pJ = pI->pNext;

			pI->pNext = pTemp;
			pTemp->pNext = pJ;

			return true;
		}
	}
}

bool delect_link(PLINKNODE pHead, int pos)
{
	if (link_is_empty(pHead))
	{
		printf_s("ɾ��ʧ�ܣ�����Ϊ��\n");
		return false;
	}

	int len = length_link(pHead);
	if (pos > len || pos < 1)
	{
		printf_s("ɾ��ʧ�ܣ�ɾ��λ�÷Ƿ�������������1~%d��������\n", len);
		return false;
	}
	else
	{
		PLINKNODE pI = pHead;
		for (int i = 1; i < pos; i++)
		{
			pI = pI->pNext;
		}

		PLINKNODE pJ = pI->pNext;

		pI->pNext = pI->pNext->pNext;
		//free(pJ);
		//pJ = NULL;

		return true;
	}
}

void sort_link(PLINKNODE pHead)
{
	if (link_is_empty(pHead))
	{
		printf_s("�޷�������������\n");
	}
	else
	{
		int i = 0, j = 0, temp = 0, len = length_link(pHead);
		PLINKNODE pI = pHead->pNext, pJ = pI->pNext;

		for (i = 0; i < len - 1; i++, pI = pI->pNext)
		{
			for (j = i + 1, pJ = pI->pNext; j < len; j++, pJ = pJ->pNext)
			{
				if (pI->i_data > pJ->i_data)
				{
					temp = pI->i_data;
					pI->i_data = pJ->i_data;
					pJ->i_data = temp;
				}
			}
		}
	}

	return;
	
}
