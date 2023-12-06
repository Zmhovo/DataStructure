#ifndef __TREE_H__
#define __TREE_H__

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct BTNode
{
	int i_data;
	struct BTNode* pLchild;
	struct BTNode* pRchild;
}BTNODE, * PBTNODE;

void init_btree(PBTNODE BTree);          //初始化

PBTNODE create_btree(PBTNODE BTree);          //创建二叉树

void preTraverse_btree(PBTNODE BTree);          //先序遍历

void inTraverse_btree(PBTNODE BTree);          //中序遍历

void postTraverse_btree(PBTNODE BTree);          //后序遍历
#endif //! __TREE_H__