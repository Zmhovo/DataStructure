#include "Tree.h"

void init_btree(PBTNODE BTree)
{
	if (NULL == BTree)
	{
		printf_s("动态内存分配失败！\n");
		exit(-1);
	}
	else 
	{
		BTree->i_data = NULL;
		BTree->pLchild = NULL;
		BTree->pRchild = NULL;
	}
	
	return;
}

PBTNODE create_btree(PBTNODE BTree)
{
	if (BTree->i_data == NULL)
	{
		printf_s("请输入根结点的数据：");
		scanf_s("%d", &BTree->i_data);
	}

	int temp = 0;

chooseL:
	printf_s("是否创建左孩子结点(1.是；2.否)：");
	scanf_s("%d", &temp);
	switch (temp)
	{
	case 1:
	{
		BTree->pLchild = (PBTNODE)malloc(sizeof(BTNODE));
		if (NULL == BTree->pLchild)
		{
			printf_s("动态内存分配失败！\n");
			exit(-1);
		}
		else
		{
			printf_s("请输入左孩子结点的数据：");
			scanf_s("%d", &(BTree->pLchild->i_data));
		}
		break;
	}
	case 2:
	{
		BTree->pLchild = NULL;

		break;
	}
	default:
	{
		printf_s("输入序号错误！\n");
		goto chooseL;
		break;
	}
	}

chooseR:
	printf_s("是否创建右孩子结点(1.是；2.否)：");
	scanf_s("%d", &temp);
	switch (temp)
	{
	case 1:
	{
		BTree->pRchild = (PBTNODE)malloc(sizeof(BTNODE));
		if (NULL == BTree->pRchild)
		{
			printf_s("动态内存分配失败！\n");
			exit(-1);
		}
		else
		{
			printf_s("请输入右孩子结点的数据：");
			scanf_s("%d", &(BTree->pRchild->i_data));
		}

		break;
	}
	case 2:
	{
		BTree->pRchild = NULL;

		break;
	}
	default:
	{
		printf_s("输入序号错误！\n");
		goto chooseR;
		break;
	}
	}

	if (BTree->pLchild != NULL) 
	{
		printf_s("转到结点“%d”的左孩子结点“%d”：\n",BTree->i_data,BTree->pLchild->i_data);
		create_btree(BTree->pLchild);
	}
	if (BTree->pRchild != NULL)
	{
		printf_s("转到结点“%d”的右孩子结点“%d”：\n", BTree->i_data, BTree->pRchild->i_data);
		create_btree(BTree->pRchild);
	}

    return BTree;
}

void preTraverse_btree(PBTNODE BTree)
{
	if(BTree != NULL)
	{
		printf_s("%d ", BTree->i_data);
		if (BTree->pLchild != NULL)
		{
			preTraverse_btree(BTree->pLchild);
		}
		if (BTree->pRchild != NULL)
		{
			preTraverse_btree(BTree->pRchild);
		}
	}

	return;
}

void inTraverse_btree(PBTNODE BTree)
{
	if (BTree != NULL)
	{
		if (BTree->pLchild != NULL)
		{
			inTraverse_btree(BTree->pLchild);
		}

		printf_s("%d ", BTree->i_data);
		
		if (BTree->pRchild != NULL)
		{
			inTraverse_btree(BTree->pRchild);
		}
	}

	return;
}

void postTraverse_btree(PBTNODE BTree)
{
	if (BTree != NULL)
	{
		if (BTree->pLchild != NULL)
		{
			postTraverse_btree(BTree->pLchild);
		}

		if (BTree->pRchild != NULL)
		{
			postTraverse_btree(BTree->pRchild);
		}
		
		printf_s("%d ", BTree->i_data);
	}
}
