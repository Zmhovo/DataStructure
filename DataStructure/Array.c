#include "Array.h"

void init_arr(PARR pArr,int length)
{
    pArr->pBase = (int*)malloc(sizeof(int) * length);          //动态分配内存

    if (NULL == pArr->pBase)
    {
        printf_s("动态内存分配失败！\n");
        exit(-1);
    }
    else 
    {
        pArr->len = length;
        pArr->cnt = 0;
    }

    return;
}

bool append_arr(PARR pArr, int val)
{
    if (arr_is_full(pArr))          //数组为满
    {
        printf_s("数组为满,追加数据“%d”失败！\n",val);
        
        return false;
    }
    else           //数组未满
    {
        pArr->pBase[pArr->cnt] = val;
        (pArr->cnt)++;          //有效长度进一
        
        printf_s("追加数据“%d”成功！\n", val);

        return true;
    }
}

bool insert_arr(PARR pArr, int pos, int val)
{
    if (pos < 1 || pos > pArr->cnt + 1)
    {
        printf_s("插入失败：插入位置非法，请重新输入0~%d内整数。\n", pArr->cnt + 1);
        return false;
    }
    else if (arr_is_full(pArr))
    {
        printf_s("插入失败：数组为满。\n");
        return false;
    }
    else
    {
        for (int i = pArr->cnt - 1; i >= pos - 1; i--)          //数组第pos个元素后移一位
        {
            pArr->pBase[i + 1] = pArr->pBase[i];
        }

        pArr->pBase[pos - 1] = val;          //插入val到数组第pos个位置
        (pArr->cnt)++;          //有效长度进一

        printf_s("插入成功：插入“%d”为数组第%d个元素。\n", val, pos);

        return true;
    }
}

bool delect_arr(PARR pArr, int pos)
{
    if (pos < 1 || pos > pArr->cnt)
    {
        printf_s("删除失败：删除位置非法，请重新输入0~%d内整数。\n", pArr->cnt);
        return false;
    }
    else if (arr_is_empty(pArr)) 
    {
        printf_s("删除失败：数组为空。\n");
        return false;
    }
    else
    {
        printf_s("删除成功：删除数组第%d个元素“%d”。\n", pos, pArr->pBase[pos - 1]);

        for (int i = pos; i < pArr->cnt; i++)
        {
            pArr->pBase[i - 1] = pArr->pBase[i];
        }
        pArr->cnt--;

        return true;
    }
}

bool arr_is_empty(PARR pArr)
{
    if (0 == pArr->cnt)
    {
        return true;
    }
    else 
    {
        return false;
    }
    
}

bool arr_is_full(PARR pArr)
{
    if (pArr->cnt == pArr->len)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void sort_arr(PARR pArr)
{
    for (int i = 0; i < pArr->cnt; i++)
    {
        for (int j = i + 1; j < pArr->cnt; j++)
        {
            if (pArr->pBase[i] > pArr->pBase[j])
            {
                int t = pArr->pBase[i];
                pArr->pBase[i] = pArr->pBase[j];
                pArr->pBase[j] = t;
            }
        }
    }

    return;
}

void show_arr(PARR pArr)
{
    if (arr_is_empty(pArr))          //数组为空
    {
        printf_s("数组为空！\n");
    }
    else
    {
        printf_s("数组：{ ");
        for (int i = 0; i < pArr->cnt - 1; i++)
        {
            printf_s("%d,", pArr->pBase[i]);
        }
        printf_s("%d }\n",pArr->pBase[pArr->cnt - 1]);
    }

    return;
}

void inversion_arr(PARR pArr)
{
    int i = 0, j = pArr->cnt - 1, t = 0;

    while (i < j)
    {
        t = pArr->pBase[i];
        pArr->pBase[i] = pArr->pBase[j];
        pArr->pBase[j] = t;
        i++;
        j--;
    }

    return;
}

bool find_val(PARR pArr, int val)
{
    ARR total;
    init_arr(&total,pArr->len);

    for (int i = 0; i < pArr->cnt; i++)
    {
        if(pArr->pBase[i] == val)          //将元素位置记录在total数组中
        {
            if (arr_is_full(&total))
            {
                printf_s("数组为满,追加数据“%d”失败！\n", i);

                return false;
            }
            else
            {
                (&total)->pBase[(&total)->cnt] = i;
                ((&total)->cnt)++;          //有效长度进一

            }
        }
    }

    if (arr_is_empty(&total))
    {
        printf_s("在数组中未查找到元素“%d”\n", val);

        return false;
    }
    else
    {
        printf_s("在数组中查找到%d个元素“%d”，位置：", (&total)->cnt, val);
        for (int j = 0; j < (&total)->cnt - 1; j++)
        {
            printf_s("pBase[%d]，", (&total)->pBase[j]);
            
        }
        printf_s("pBase[%d]\n", (&total)->pBase[(&total)->cnt - 1]);

        return true;
    }

}
