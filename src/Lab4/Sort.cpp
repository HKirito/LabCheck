#include "Sort.h"

int BINARY_SEARCH(int a[], int n, int key) {//The Binary——Search
    int p = 1;
    int r = n;
    while (p <= r) {
        int q = ((p + r) / 2);
        if (a[q] == key) {
            return q;
        } else if (a[q] > key) {
            r = q - 1;
        } else {
            p = q + 1;
        }
    }
    return -1;
}

void INSERT_SORT(int a[], int n) {
    if (n > 2) {
        for (int i = 1; i <= n - 1; i++) {
            if (a[i] < a[i - 1]) {
                int j = i - 1;
                int temp = a[i];

                while (temp < a[j]) {
                    a[j + 1] = a[j];
                    j--;
                }
                a[j + 1] = temp;
            }
        }
    } else if (n == 2) {
        if (a[0] >= a[1]) {
            a[0] = a[0] + a[1];
            a[1] = a[0] - a[1];
            a[0] = a[0] - a[1];
        }
    } else
        return;

}

void BubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i; j < n - 1; j++) {
            if (a[j + 1] < a[j]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void BETTER_BubbleSort(int a[], int n) {
    for (int limit = n - 1; limit > 0; limit--) {
        bool flag = false;
        for (int i = 0; i < limit; i++) {
            if (a[i + 1] < a[i]) {
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                flag = true;
            }
        }
        if (!flag) break;
    }
}

void SelectSort(int a[], int n) {
    int i,j,min,t;
    for(i=0;i<n-1;i++) {
        min=i;//查找最小值
        for(j=i+1;j<n;j++){
            if(a[min]>a[j])
                min=j;//交换
        }
        if(min!=i)
        {
            t=a[min];
            a[min]=a[i];
            a[i]=t;
        }
    }
}

int getMax(int *p,int n){
    int i;
    int max = 0;
    for (i = 0; i < n; i++) {
        if (*(p+1)>max){
            max = *( p + 1);
        }
    }
    return max;
}

int getLoopTimes(int num){
    int count = 1;
    int temp = num / 10;
    while (temp != 0){
        count++;
        temp = temp / 10;
    }
    return count;
}

void toString(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%4d ", a[i]);
    }
    printf("\n");
}

void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quick_sort_1(int a[], int low, int high) {
    if (low >= high) {
        return;
    } else {
        int m = low + 1;
        int n = high;
        while (m <= n) {
            while (a[m] <= a[high]) {
                m++;
            }
            while (a[n] > a[high]) {
                n--;
            }
            if (m <= n) {
                int temp = a[m];
                a[m] = a[n];
                a[n] = temp;
                m++;
                n--;
            }
        }
        if (n != high) {
            int temp = a[n];
            a[n] = a[high];
            a[low] = temp;
        }
        quick_sort_1(a, low, n - 1);
        quick_sort_1(a, n + 1, high);
    }
}

void Faster_Sort(int Array[], int began, int end) {
    int i, j;

    if (began < end) {
        i = began + 1;
        j = end;

        while (i < j) {//第一步切割,while结束时i==j
            if (Array[i] > Array[began]) {
                Swap(&Array[i], &Array[j]);
                j--;
            } else {
                i++;
            }
        }

        if (Array[i] >= Array[began]) {
            i--;
        }
        Swap(&Array[began], &Array[i]);

        Faster_Sort(Array, began, i);
        Faster_Sort(Array, j, end);
    }
}

void test4() {
    clock_t start, finish;
    double time;
    int a[200];

    for (int i = 0; i < 200; ++i) {
        a[i] = rand() % 200;
    }
    //time start!
    start = clock();

    toString(a, 200);
    Faster_Sort(a,0, 199);
    toString(a, 200);

    //time up!
    finish = clock();
    time = (double) (finish - start) / CLOCKS_PER_SEC;

    printf("It's cost %lf second!\n", time);
}


//
// Created by Kirito on 2018/11/1.
//

