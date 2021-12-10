#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct heap {
    int *a;
    int rear, size;
}heap;
void init_heap(heap* h, int s);
void insert_heap(heap *h, int d);
int delete_heap(heap *h);
void traverse_heap(heap h);
void swap(heap *h, int i, int j);
void heapify(heap *h);

int* heap_sort(int *arr, int count);
int search_heap(heap h, int n, int d);
void build_heap(int arr[], int n);
int isHeap(int a[], int i, int n);

#endif // HEAP_H_INCLUDED
