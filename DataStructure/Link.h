#ifndef __LINK_H__
#define __LINK_H__


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>

typedef struct LinkNode          //结点
{
	int i_data;          //数据域
	struct LinkNode* pNext;          //指针域

}LINKNODE, * PLINKNODE;

PLINKNODE create_link();          //创建链表

bool link_is_empty(PLINKNODE pHead);          //为空
int length_link(PLINKNODE pHead);          //长度

void show_link(PLINKNODE pHead);          //显示
bool insert_link(PLINKNODE pHead, int pos, int val);          //插入val到链表第pos个结点
bool delect_link(PLINKNODE pHead, int pos);          //删除链表第pos个结点
void sort_link(PLINKNODE pHead);          //升序排序



#endif 

