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

void init_stack(PSTACK pHead);          //初始化

bool stack_is_empty(PSTACK pHead);          //为空

void show_stack(PSTACK pHead);          //显示
bool push_stack(PSTACK pHead, int val);          //入栈
bool pop_stack(PSTACK pHead);          //出栈
bool clear_stack(PSTACK pHead);          //清空栈

#endif //! __STACK_H__
