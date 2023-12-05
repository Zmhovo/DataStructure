#pragma warning(disable:6031)
#include "Array.h"
#include "Link.h"
#include "Stack.h"
#include "Queue.h"
#include "Tree.h"

int main()
{
	int function = 0;
	printf_s("1.���飻2.����3.ջ��4.�ӣ�5.��\n�������ѡ�����ݽṹ���ܣ�");
	scanf_s("%d", &function);

	switch (function)
	{
		case 1:          //1.����
		{
			ARR arr;
			int len = 0;

			printf_s("�½�����ĳ���:");
			scanf_s("%d", &len);

			init_arr(&arr, len);
			show_arr(&arr);

			append_arr(&arr, 1);
			append_arr(&arr, 5);
			append_arr(&arr, 8);
			append_arr(&arr, 1);
			append_arr(&arr, 6);
			append_arr(&arr, 7);
			append_arr(&arr, 9);
			append_arr(&arr, 0);
			append_arr(&arr, 7);
			append_arr(&arr, 5);
			append_arr(&arr, 2);

			show_arr(&arr);

			insert_arr(&arr, 12, 88);

			show_arr(&arr);

			delect_arr(&arr, 12);

			show_arr(&arr);

			inversion_arr(&arr);

			show_arr(&arr);

			sort_arr(&arr);

			show_arr(&arr);

			find_val(&arr, 1);
			
			break;
		}

		case 2:          //2.����
		{
			PLINKNODE pHead = create_link();
			int len = 0;

			show_link(pHead);

			len = length_link(pHead);
			printf_s("�����ȣ�%d\n", len);

			sort_link(pHead);
			
			show_link(pHead);

			insert_link(pHead, 1, 666);

			show_link(pHead);

			delect_link(pHead, 1);

			show_link(pHead);

			break;
		}

		case 3:          //3.ջ
		{
			STACK stack;
			init_stack(&stack);

			push_stack(&stack, 1);
			push_stack(&stack, 2);
			push_stack(&stack, 3);
			push_stack(&stack, 4);
			push_stack(&stack, 5);

			show_stack(&stack);

			pop_stack(&stack);

			show_stack(&stack);

			clear_stack(&stack);

			show_stack(&stack);

			pop_stack(&stack);

			break;
		}

		case 4:          //4.��
		{
			CIRCULARQUEUE queue;
			init_queue(&queue);

			push_queue(&queue, 1);
			push_queue(&queue, 2);
			push_queue(&queue, 3);
			push_queue(&queue, 4);
			push_queue(&queue, 5);
			push_queue(&queue, 6);

			show_queue(&queue);

			pop_queue(&queue);

			show_queue(&queue);

			break;
		}

		case 5:
		{
			PBTNODE BTree = (PBTNODE)malloc(sizeof(BTNODE));
			init_btree(BTree);
			BTree = create_btree(BTree);

			printf_s("���������������");
			preTraverse_btree(BTree);
			printf_s("\n");

			break;
		}
		default:
		{
			printf_s("������Ŵ���");
			break; 
		}

		
	}
	

}