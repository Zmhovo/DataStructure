#ifndef __SORT_H__
#define __SORT_H__

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int* create_array(int* len);          //创建数组
void swap(int* a, int* b);          //交换

void bubble_sort(int* array, int* len);          //冒泡排序
void selection_sort(int* array, int* len);          //选择排序
void insertion_sort(int* array, int* len);          //插入排序

#endif //! __SORT_H__
