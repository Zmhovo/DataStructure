#pragma warning(disable:6031)
#include "Array.h"
#include "Link.h"
#include "Stack.h"
#include "Queue.h"
#include "Tree.h"
#include "Sort.h"

int main()
{
	int function = 0;

chooseMain:
	printf_s("1.���飻2.����3.ջ��4.�ӣ�5.����6.����\n�������ѡ�����ݽṹ���ܣ�");
	scanf_s("%d", &function);

	switch (function)
	{
		case 1:          //1.����
		{
			ARR arr;
			int len = 0;

		inputArrLen:
			printf_s("�½�����ĳ���:");
			scanf_s("%d", &len);
			if (len < 1)
			{
				printf_s("[�������]�����������0��������\n");
				goto inputArrLen;
			}

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
			
			free(arr.pBase);
			arr.pBase = NULL;
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

			free(pHead);
			pHead = NULL;

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

			free(stack.pTop);
			stack.pTop = NULL;
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

			free(queue.pBase);
			queue.pBase = NULL;
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

			printf_s("���������������");
			inTraverse_btree(BTree);
			printf_s("\n");

			printf_s("���������������");
			postTraverse_btree(BTree);
			printf_s("\n");

			free(BTree);
			BTree = NULL;
			break;
		}

		case 6:
		{
			int len = 0;
			int* array = create_array(&len);
			int choose_sort = 0;
		chooseSort:
			
			printf_s("1.ð������2.ѡ������3.��������4.ϣ������5.�鲢����\n�������ѡ�����ݽṹ���ܣ�");
			scanf_s("%d", &choose_sort);

			switch (choose_sort)
			{
				case 1:
				{
					bubble_sort(array, &len);
					break;
				}
				case 2:
				{
					selection_sort(array, &len);
					break;
				}
				case 3:
				{
					insertion_sort(array, &len);
					break;
				}
				case 4:
				{
					shell_sort(array, &len);
					break;
				}
				case 5:
				{
					merge_sort(array, &len);
					break;
				}

				default:
				{
					printf_s("������Ŵ���\n");
					goto chooseSort;
					break;
				}
				free(array);
				array = NULL;
			}
			break;
		}

		default:
		{
			printf_s("������Ŵ���\n");
			goto chooseMain;
			break; 
		}

		
	}
	

}