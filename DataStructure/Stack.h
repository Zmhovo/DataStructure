#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>

typedef struct StackNode
{
	int i_data;
	struct StackNode* pNext;
}STACKNODE, * PSTACKNODE;

typedef struct Stack
{
	PSTACKNODE pTop;
	PSTACKNODE pBottom;
}STACK, * PSTACK;

void init_stack(PSTACK pHead);          //��ʼ��

bool stack_is_empty(PSTACK pHead);          //Ϊ��

void show_stack(PSTACK pHead);          //��ʾ
bool push_stack(PSTACK pHead, int val);          //��ջ
bool pop_stack(PSTACK pHead);          //��ջ
bool clear_stack(PSTACK pHead);          //���ջ

#endif //! __STACK_H__
