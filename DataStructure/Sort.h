#ifndef __SORT_H__
#define __SORT_H__

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int* create_array(int* len);          //¥¥Ω® ˝◊È
void swap(int* a, int* b);          //Ωªªª

void bubble_sort(int* array, int* len);          //√∞≈›≈≈–Ú
void selection_sort(int* array, int* len);          //—°‘Ò≈≈–Ú
void insertion_sort(int* array, int* len);          //≤Â»Î≈≈–Ú
void shell_sort(int* array, int* len);          //œ£∂˚≈≈–Ú

void merge_sort(int* array, int* len);          //πÈ≤¢≈≈–Ú£®µ›πÈ£©
void _merge_sort(int* array, int left, int right, int* temp);
#endif //! __SORT_H__
