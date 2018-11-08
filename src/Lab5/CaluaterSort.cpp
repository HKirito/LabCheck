#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>

void toNewString(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%4d ", a[i]);
    }
    printf("\n");
}

void Caulate_Sort(int Array[], int len, int max) {
    int *c;
    int *b;
    c = (int *) malloc(sizeof(int) * max);
    b = (int *) malloc(sizeof(int) * len);
    for (int i = 0; i < max; i++)
        c[i] = 0;//初始化
    for (int j = 0; j < len; j++)
        c[Array[j]] += 1;//统计Array内部元素为i的个数
    for (int k = 1; k < max; k++)
        c[k] = c[k - 1] + c[k];
    for (int n = len - 1; n >= 0; n--) {
        b[c[Array[n]] - 1] = Array[n];
        c[Array[n]] -= 1;
    }
    for (int l = 0; l < len; l++) {
        Array[l] = b[l];
    }
    free(c);
    free(b);
}

void test5(){
    clock_t start, finish;
    double time;
    int a[200];

    for (int i = 0; i < 200; ++i) {
        a[i] = rand() % 200;
    }
    //time start!
    start = clock();

    toNewString(a, 200);
    Caulate_Sort(a, 200,200);
    toNewString(a, 200);

    //time up!
    finish = clock();
    time = (double) (finish - start) / CLOCKS_PER_SEC;

    printf("It's cost %lf second!\n", time);
}

//
// Created by Kirito on 2018/11/8.
//

