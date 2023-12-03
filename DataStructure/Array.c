#include "Array.h"

void init_arr(PARR pArr,int length)
{
    pArr->pBase = (int*)malloc(sizeof(int) * length);          //��̬�����ڴ�

    if (NULL == pArr->pBase)
    {
        printf_s("��̬�ڴ����ʧ�ܣ�\n");
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
    if (arr_is_full(pArr))          //����Ϊ��
    {
        printf_s("����Ϊ��,׷�����ݡ�%d��ʧ�ܣ�\n",val);
        
        return false;
    }
    else           //����δ��
    {
        pArr->pBase[pArr->cnt] = val;
        (pArr->cnt)++;          //��Ч���Ƚ�һ
        
        printf_s("׷�����ݡ�%d���ɹ���\n", val);

        return true;
    }
}

bool insert_arr(PARR pArr, int pos, int val)
{
    if (pos < 1 || pos > pArr->cnt + 1)
    {
        printf_s("����ʧ�ܣ�����λ�÷Ƿ�������������0~%d��������\n", pArr->cnt + 1);
        return false;
    }
    else if (arr_is_full(pArr))
    {
        printf_s("����ʧ�ܣ�����Ϊ����\n");
        return false;
    }
    else
    {
        for (int i = pArr->cnt - 1; i >= pos - 1; i--)          //�����pos��Ԫ�غ���һλ
        {
            pArr->pBase[i + 1] = pArr->pBase[i];
        }

        pArr->pBase[pos - 1] = val;          //����val�������pos��λ��
        (pArr->cnt)++;          //��Ч���Ƚ�һ

        printf_s("����ɹ������롰%d��Ϊ�����%d��Ԫ�ء�\n", val, pos);

        return true;
    }
}

bool delect_arr(PARR pArr, int pos)
{
    if (pos < 1 || pos > pArr->cnt)
    {
        printf_s("ɾ��ʧ�ܣ�ɾ��λ�÷Ƿ�������������0~%d��������\n", pArr->cnt);
        return false;
    }
    else if (arr_is_empty(pArr)) 
    {
        printf_s("ɾ��ʧ�ܣ�����Ϊ�ա�\n");
        return false;
    }
    else
    {
        printf_s("ɾ���ɹ���ɾ�������%d��Ԫ�ء�%d����\n", pos, pArr->pBase[pos - 1]);

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
    if (arr_is_empty(pArr))          //����Ϊ��
    {
        printf_s("����Ϊ�գ�\n");
    }
    else
    {
        printf_s("���飺{ ");
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
        if(pArr->pBase[i] == val)          //��Ԫ��λ�ü�¼��total������
        {
            if (arr_is_full(&total))
            {
                printf_s("����Ϊ��,׷�����ݡ�%d��ʧ�ܣ�\n", i);

                return false;
            }
            else
            {
                (&total)->pBase[(&total)->cnt] = i;
                ((&total)->cnt)++;          //��Ч���Ƚ�һ

            }
        }
    }

    if (arr_is_empty(&total))
    {
        printf_s("��������δ���ҵ�Ԫ�ء�%d��\n", val);

        return false;
    }
    else
    {
        printf_s("�������в��ҵ�%d��Ԫ�ء�%d����λ�ã�", (&total)->cnt, val);
        for (int j = 0; j < (&total)->cnt - 1; j++)
        {
            printf_s("pBase[%d]��", (&total)->pBase[j]);
            
        }
        printf_s("pBase[%d]\n", (&total)->pBase[(&total)->cnt - 1]);

        return true;
    }

}
