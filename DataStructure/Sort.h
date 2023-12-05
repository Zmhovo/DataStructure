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

#endif //! __SORT_H__
