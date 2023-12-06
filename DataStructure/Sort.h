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
void shell_sort(int* array, int* len);          //希尔排序

void merge_sort(int* array, int* len);          //归并排序（递归）
void _merge_sort(int* array, int left, int right, int* temp);
#endif //! __SORT_H__
