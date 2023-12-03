#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>

typedef struct Arr
{
	int* pBase;          //第一个元素地址
	int len;          //最大长度
	int cnt;          //有效长度

}ARR, * PARR;

void init_arr(PARR pArr, int length);        //初始化

bool append_arr(PARR pArr, int val);          //追加val
bool insert_arr(PARR pArr, int pos, int val);          //插入val到数组第pos个位置
bool delect_arr(PARR pArr, int pos);          //删除数组第pos个位置元素
bool arr_is_empty(PARR pArr);          //为空
bool arr_is_full(PARR pArr);          //为满


void sort_arr(PARR pArr);          //升序排序
void show_arr(PARR pArr);          //显示
void inversion_arr(PARR pArr);          //倒置

bool find_val(PARR pArr, int val);          //查找元素val

#endif