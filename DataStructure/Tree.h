 #ifndef __TREE_H__
#define __TREE_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct BTNode
{
	int i_data;
	struct BTNode* pLchild;
	struct BTNode* pRchild;
}BTNODE, * PBTNODE;

void init_btree(PBTNODE BTree);          //��ʼ��

PBTNODE create_btree(PBTNODE BTree);          //����������
#endif //! __TREE_H__