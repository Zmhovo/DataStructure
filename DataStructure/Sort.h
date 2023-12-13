#ifndef __SORT_H__
#define __SORT_H__

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int* create_array(int* len);          //´´½¨Êı×é
void swap(int* a, int* b);          //½»»»

void bubble_sort(int* array, int* len);          //Ã°ÅİÅÅĞò
void selection_sort(int* array, int* len);          //Ñ¡ÔñÅÅĞò
void insertion_sort(int* array, int* len);          //²åÈëÅÅĞò
void shell_sort(int* array, int* len);          //Ï£¶ûÅÅĞò

void merge_sort(int* array, int* len);          //¹é²¢ÅÅĞò£¨µİ¹é£©
void _merge_sort(int* array, int left, int right, int* temp);

void quick_sort(int* array, int* len);          //¿ìËÙÅÅĞò£¨µİ¹é£©
void _quick_sort(int* array, int left, int right);

void heap_sort(int* array, int* len);          //¶ÑÅÅĞò
void _heap_sort(int* array, int start, int end);
#endif //! __SORT_H__
