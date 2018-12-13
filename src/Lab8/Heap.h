//
// Created by Kirito on 2018/12/13.
//

#ifndef LABCHECK1_HEAP_H
#define LABCHECK1_HEAP_H
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

bool isEmpty();

template <class T>
void updateHeap(T Heap[],int tmp_index);

template <class T>
void swap(T heap[],int a,int b);

template <class T>
void Insert(T data);

template <class T>
T del();

void print_Heap();

void test8();
#endif //LABCHECK1_HEAP_H
