#ifndef __LINK_H__
#define __LINK_H__


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>

typedef struct LinkNode          //���
{
	int i_data;          //������
	struct LinkNode* pNext;          //ָ����

}LINKNODE, * PLINKNODE;

PLINKNODE create_link();          //��������

bool link_is_empty(PLINKNODE pHead);          //Ϊ��
int length_link(PLINKNODE pHead);          //����

void show_link(PLINKNODE pHead);          //��ʾ
bool insert_link(PLINKNODE pHead, int pos, int val);          //����val�������pos�����
bool delect_link(PLINKNODE pHead, int pos);          //ɾ�������pos�����
void sort_link(PLINKNODE pHead);          //��������



#endif 

