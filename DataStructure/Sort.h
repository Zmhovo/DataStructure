#ifndef __SORT_H__
#define __SORT_H__

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int* create_array(int* len);          //��������
void swap(int* a, int* b);          //����

void bubble_sort(int* array, int* len);          //ð������
void selection_sort(int* array, int* len);          //ѡ������
void insertion_sort(int* array, int* len);          //��������
void shell_sort(int* array, int* len);          //ϣ������

void merge_sort(int* array, int* len);          //�鲢���򣨵ݹ飩
void _merge_sort(int* array, int left, int right, int* temp);

void quick_sort(int* array, int* len);          //�������򣨵ݹ飩
void _quick_sort(int* array, int left, int right);

void heap_sort(int* array, int* len);          //������
void _heap_sort(int* array, int start, int end);
#endif //! __SORT_H__
