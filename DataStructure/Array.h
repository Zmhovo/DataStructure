#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>

typedef struct Arr
{
	int* pBase;          //��һ��Ԫ�ص�ַ
	int len;          //��󳤶�
	int cnt;          //��Ч����

}ARR, * PARR;

void init_arr(PARR pArr, int length);        //��ʼ��

bool append_arr(PARR pArr, int val);          //׷��val
bool insert_arr(PARR pArr, int pos, int val);          //����val�������pos��λ��
bool delect_arr(PARR pArr, int pos);          //ɾ�������pos��λ��Ԫ��
bool arr_is_empty(PARR pArr);          //Ϊ��
bool arr_is_full(PARR pArr);          //Ϊ��


void sort_arr(PARR pArr);          //��������
void show_arr(PARR pArr);          //��ʾ
void inversion_arr(PARR pArr);          //����

bool find_val(PARR pArr, int val);          //����Ԫ��val

#endif