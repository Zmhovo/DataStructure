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

void init_btree(PBTNODE BTree);          //³õÊ¼»¯

PBTNODE create_btree(PBTNODE BTree);          //´´½¨¶þ²æÊ÷

void preTraverse_btree(PBTNODE BTree);          //ÏÈÐò±éÀú

void inTraverse_btree(PBTNODE BTree);          //ÖÐÐò±éÀú

void postTraverse_btree(PBTNODE BTree);          //ºóÐò±éÀú

#endif //! __TREE_H__