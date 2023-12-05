#include "Tree.h"

void init_btree(PBTNODE BTree)
{
	if (NULL == BTree)
	{
		printf_s("��̬�ڴ����ʧ�ܣ�\n");
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
		printf_s("������ý������ݣ�");
		scanf_s("%d", &BTree->i_data);
	}

	int temp = 0;
	printf_s("�Ƿ񴴽����ӽ��(1.�ǣ�2.��)��");
	scanf_s("%d", &temp);
	switch (temp)
	{
	case 1:
	{
		BTree->pLchild = (PBTNODE)malloc(sizeof(BTNODE));
		if (NULL == BTree->pLchild)
		{
			printf_s("��̬�ڴ����ʧ�ܣ�\n");
			exit(-1);
		}
		else
		{
			printf_s("���������ӽ������ݣ�");
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
		printf_s("������Ŵ���");
		break;
	}
	}


	printf_s("�Ƿ񴴽��Һ��ӽ��(1.�ǣ�2.��)��");
	scanf_s("%d", &temp);
	switch (temp)
	{
	case 1:
	{
		BTree->pRchild = (PBTNODE)malloc(sizeof(BTNODE));
		if (NULL == BTree->pRchild)
		{
			printf_s("��̬�ڴ����ʧ�ܣ�\n");
			exit(-1);
		}
		else
		{
			printf_s("�������Һ��ӽ������ݣ�");
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
		printf_s("������Ŵ���");
		break;
	}
	}

	if (BTree->pLchild != NULL) 
	{
		printf_s("ת����㡰%d�������ӽ�㡰%d����\n",BTree->i_data,BTree->pLchild->i_data);
		create_btree(BTree->pLchild);
	}
	if (BTree->pRchild != NULL)
	{
		printf_s("ת����㡰%d�����Һ��ӽ�㡰%d����\n", BTree->i_data, BTree->pRchild->i_data);
		create_btree(BTree->pRchild);
	}

    return BTree;
}