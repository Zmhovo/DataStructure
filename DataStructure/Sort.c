#include "Sort.h"

int* create_array(int* len)
{
    int temp = 0;    
inputArrayLen:
    printf_s("新建数组的长度:");
    scanf_s("%d", len);

    if (*len < 1)
    {
        printf_s("[输入错误]：请输入大于0的整数！\n");
        goto inputArrayLen;
    }

    int* array = (int*)malloc(sizeof(int) * (*len));

    if (NULL == array) 
    {
        printf_s("动态内存分配失败！\n");
        exit(-1);
    }
    else
    {
        printf_s("请输入新建数组：");
        for (int i = 0; i < (*len); i++)
        {
            scanf_s("%d", &temp);
            array[i] = temp;
        }
        
        printf_s("数组：{ ");
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

    printf_s("冒泡排序后数组：{ ");
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

    printf_s("选择排序后数组：{ ");
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

    printf_s("插入排序后数组：{ ");
    for (int i = 0; i < (*len) - 1; i++)
    {
        printf_s("%d,", array[i]);
    }
    printf_s("%d }\n", array[(*len) - 1]);

    return;
}

void shell_sort(int* array, int* len)
{
    int gap = *len;
    int end = 0;
    while (gap > 1)
    {
        gap = gap / 3 + 1;
        for (int i = 0; i < (*len) - gap; i++)
        {
            end = i;
            while (end >= 0)
            {
                if (array[end] > array[end + gap])
                {
                    swap(&array[end], &array[end + gap]);
                    end -= gap;
                }
                else
                {
                    break;
                }
            } 
        }
    }

    printf_s("希尔排序后数组：{ ");
    for (int i = 0; i < (*len) - 1; i++)
    {
        printf_s("%d,", array[i]);
    }
    printf_s("%d }\n", array[(*len) - 1]);

    return;
}


void merge_sort(int* array, int* len)
{
    int* temp = (int*)malloc(sizeof(int) * (*len));
    if (NULL == array)
    {
        printf_s("动态内存分配失败！\n");
        exit(-1);
    }
    else
    {
        _merge_sort(array, 0, (*len) - 1, temp);	//归并排序的过程


        printf_s("归并排序后数组：{ ");
        for (int i = 0; i < (*len) - 1; i++)
        {
            printf_s("%d,", array[i]);
        }
        printf_s("%d }\n", array[(*len) - 1]);

        free(temp);
        temp = NULL;

        return;
    }
}

void _merge_sort(int* array, int left, int right, int* temp)
{
    if (left >= right)          //分割数组只有一个元素时停止递归
    {
        return;
    }
    
    int mid = (left + right) / 2;
    
    _merge_sort(array, left, mid, temp);		//分割并排序数组左半边
    _merge_sort(array, mid + 1, right, temp);	//分割并排序数组右半边
    

    int begin1 = left, end1 = mid;			//数组1的左右区间
    int begin2 = mid + 1, end2 = right;		//数组2的左右区间
    int i = begin1;
    
    //排序两个有序数组
    while (begin1 <= end1 && begin2 <= end2)
    {
        if (array[begin1] <= array[begin2])
        {
            temp[i] = array[begin1];
            begin1++;
        }
        else
        {
            temp[i] = array[begin2];
            begin2++;
        }
        i++;
    }
    
    while (begin1 <= end1)
    {
        temp[i] = array[begin1];
        begin1++;
        i++;
    }
    
    while (begin2 <= end2)
    {
        temp[i] = array[begin2];
        begin2++;
        i++;
    }
    
    for (i = left; i <= right; i++)
    {
        array[i] = temp[i];
    }

}

void quick_sort(int* array, int* len)
{
    _quick_sort(array, 0, (*len) - 1);

    printf_s("快速排序后数组：{ ");
    for (int i = 0; i < (*len) - 1; i++)
    {
        printf_s("%d,", array[i]);
    }
    printf_s("%d }\n", array[(*len) - 1]);
}

void _quick_sort(int* array, int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int start = left + 1, end = right;
    while (start != end)
    {
        while(array[end] >= array[left] && start < end)
        {
            end--;
        }
        while(array[start] < array[left] && start < end)
        {
            start++;
        }
        swap(&array[start], &array[end]);
    }
    if (array[start] < array[left])
    {
        swap(&array[start], &array[left]);
    }

    _quick_sort(array, left, start - 1);
    _quick_sort(array, end + 1, right);

}
