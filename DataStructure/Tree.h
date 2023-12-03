#ifndef __TREE_H__
#define __TREE_H__

#include <stdio.h>

typedef struct BTNode
{
	int i_data;
	BTNode* pLchild;
	BTNode* pRchild;
}BTNODE, * PBTNODE;

#endif //! __TREE_H__