#include "Stack.h"

void init_stack(PSTACK pHead)
{
	pHead->pTop = (PSTACKNODE)malloc(sizeof(STACKNODE));

	if (NULL == pHead->pTop)
	{
		printf_s("¶¯Ì¬ÄÚ´æ·ÖÅäÊ§°Ü£¡\n");
		exit(-1);
	}
	else
	{
		pHead->pBottom = pHead->pTop;
		pHead->pBottom->pNext = NULL;
	}

	return;
}


bool stack_is_empty(PSTACK pHead)
{
	if (pHead->pTop == pHead->pBottom)
	{
		return true;
	}
	else
	{
		return false;
	}
}


void show_stack(PSTACK pHead)
{
	PSTACKNODE pTemp = pHead->pTop;

	while (pTemp != pHead->pBottom)
	{
		if (pTemp == pHead->pTop)
		{
			printf_s("Õ»£º%d(Õ»¶¥)", pTemp->i_data);
		}
		else
		{
			printf_s(",%d", pTemp->i_data);
		}
		pTemp = pTemp->pNext;
	}
	printf_s("\n");
}


bool push_stack(PSTACK pHead, int val)
{
	PSTACKNODE pNew = (PSTACKNODE)malloc(sizeof(STACKNODE));
	if (NULL == pNew)
	{
		printf_s("¶¯Ì¬ÄÚ´æ·ÖÅäÊ§°Ü£¡\n");
		return false;
	}
	else
	{
		pNew->i_data = val;
		pNew->pNext = pHead->pTop;
		pHead->pTop = pNew;
	}
	
	return true;
}

bool pop_stack(PSTACK pHead)
{
	if (stack_is_empty(pHead))
	{
		printf_s("³öÕ»Ê§°Ü£ºÕ»Îª¿Õ£¡\n");
		return false;
	}
	else
	{
		PSTACKNODE pTemp = pHead->pTop;
		pHead->pTop = pHead->pTop->pNext;
		free(pTemp);
		pTemp = NULL;
		
		return true;
	}
	
}

bool clear_stack(PSTACK pHead)
{
	while (true)
	{
		PSTACKNODE pTemp = pHead->pTop;

		pHead->pTop = pHead->pTop->pNext;

		free(pTemp);
		pTemp = NULL;

		if (pHead->pTop == pHead->pBottom)
		{
			return true;
		}
	}
	return false;
}
