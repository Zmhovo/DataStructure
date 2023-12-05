#include "Sort.h"

int* create_array(int* len)
{
    int temp = 0;    

    printf_s("�½�����ĳ���:");
    scanf_s("%d", len);

    int* array = (int*)malloc(sizeof(int) * (*len));

    if (NULL == array) 
    {
        printf_s("��̬�ڴ����ʧ�ܣ�\n");
        exit(-1);
    }
    else
    {
        printf_s("�������½����飺");
        for (int i = 0; i < (*len); i++)
        {
            scanf_s("%d", &temp);
            array[i] = temp;
        }
        
        printf_s("���飺{ ");
        for (int i = 0; i < (*len) - 1; i++)
        {
            printf_s("%d,", array[i]);
        }
        printf_s("%d }\n", array[(*len) -1]);
    }
    

	return array;
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int* array, int* len)
{

    for (int i = 0; i < (*len) - 1; i++)
    {
        for (int j = 0; j < (*len) - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(&array[j], &array[j + 1]);
            }
        }
    }

    printf_s("ð����������飺{ ");
    for (int i = 0; i < (*len) - 1; i++)
    {
        printf_s("%d,", array[i]);
    }
    printf_s("%d }\n", array[(*len) - 1]);
    
    return;
}

void selection_sort(int* array, int* len)
{
    for (int i = 0; i < (*len) - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < (*len); j++)
        {
            if (array[j] < array[min])
            {
                min = j;
            }
        }
        swap(&array[min], &array[i]);
    }

    printf_s("ѡ����������飺{ ");
    for (int i = 0; i < (*len) - 1; i++)
    {
        printf_s("%d,", array[i]);
    }
    printf_s("%d }\n", array[(*len) - 1]);

    return;
}

void insertion_sort(int* array, int* len)
{
    int j = 0, key = 0;
    for (int i = 1; i < (*len); i++)
    {
        key = array[i];
        j = i - 1;
        while ((j >= 0) && (array[j] > key))
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }

    printf_s("������������飺{ ");
    for (int i = 0; i < (*len) - 1; i++)
    {
        printf_s("%d,", array[i]);
    }
    printf_s("%d }\n", array[(*len) - 1]);

    return;
}
