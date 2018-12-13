#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>

using namespace std;

template <class T>
void toNewString(T a[], int n) {
    for (int i = 0; i < n; i++) {
        cout<<a[i]<<"\t";
    }
    cout<<endl;
}

void Card_Sort(char **a, int d, int length) {

    for (int i = d - 1; i >= 0; i--) {
        char *temp;
        for (int j = 0; j < length; j++) {
            for (int k = j; k < length; k++) {
                if (a[j][i] > a[k][i]) {
                    temp = a[j];
                    a[j] = a[k];
                    a[k] = temp;
                }
            }
        }
    }
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

void testCalate() {
    clock_t start, finish;
    double time;
    int a[200];

    for (int i = 0; i < 200; ++i) {
        a[i] = rand() % 200;
    }
    //time start!
    start = clock();

    toNewString(a, 200);
    printf("\n");
    Caulate_Sort(a, 200, 200);
    printf("\n");
    toNewString(a, 200);

    //time up!
    finish = clock();
    time = (double) (finish - start) / CLOCKS_PER_SEC;

    printf("It's cost %lf second!\n", time);
}

void test5(){
    int len = 10;

    int char_len = 5;

    char **str = new char*[len];
    for (int k = 0; k < len; ++k) {
        str[k] = new char[char_len];
    }
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < char_len; ++j) {
            str[i][j] = (rand() % 26)+97;
        }
    }
    toNewString(str,len);
    Card_Sort(str,char_len,len);
    toNewString(str,len);
}

//
// Created by Kirito on 2018/11/8.
//

