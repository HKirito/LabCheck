//
// Created by Kirito on 2018/12/12.
//

#ifndef LABCHECK1_HFM_H
#define LABCHECK1_HFM_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

#define  n 100
#define m 2*n-1

typedef struct
{
    char ch;
    char bits[9];
    int len;
}CodeNode;

typedef CodeNode HuffmanCode[n + 1];
typedef struct
{
    int weight;
    int lchild, rchild, parent;
}HTNode;
typedef HTNode HuffmanTree[m + 1];

void test10();
#endif //LABCHECK1_HFM_H
