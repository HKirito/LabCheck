#include "Sort.h"
int BINARY_SEARCH(int a[],int n,int key){//The Binary——Search
    int p = 1;
    int r = n;
    while(p<=r){
        int q = ((p+r)/2);
        if(a[q] == key){
            return q;
        }else if(a[q]> key){
            r = q-1;
        }else{
            p = q+1;
        }
    }
    return -1;
}

void INSERT_SORT(int a[], int n){
    if (n>2){
        for (int i = 1; i <= n-1 ;i++) {
            if (a[i]<a[i-1]){
                int j = i-1;
                int temp = a[i];

                while(temp < a[j]){
                    a[j+1] = a[j];
                    j--;
                }
                a[j+1] = temp;
            }
        }
    }
    else if(n == 2){
        if(a[0]>=a[1])
            a[0] = a[0]+a[1];
        a[1] = a[0]-a[1];
        a[0] = a[0]-a[1];
    } else
        return;

}

void BubbleSort(int a[],int n){
    for (int i = 0; i < n-1; i++) {
        for (int j = i; j < n-1; j++) {
            if (a[j+1] < a[j]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void BETTER_BubbleSort(int a[], int n){
    for (int limit = n-1; limit >0 ; limit--) {
        bool flag = false;
        for (int i = 0; i < limit; i++) {
            if (a[i+1] < a[i]){
                int temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
                flag = true;
            }
        }
        if (!flag) break;
    }
}

void SelectSort(int a[],int n){

}


void toString(int a[],int n){
    for (int i = 0; i < n; i++) {
        printf("%4d ",a[i]);
    }printf("\n");
}

void Swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Caulate_Sort(int Array[], int len,int max){
    int* c;
    int* b;
    c = (int *)malloc(sizeof(int)*max);
    b = (int *)malloc(sizeof(int)*len);
    for (int i = 0; i < max; i++)
        c[i] = 0;//初始化
    for (int j = 0; j < len; j++)
        c[Array[j]] +=1;//统计Array内部元素为i的个数
    for (int k = 1; k < max; k++)
        c[k] = c[k-1] + c[k];
    for (int n = len -1;n >= 0;n--){
        b[c[Array[n]]-1] = Array[n];
        c[Array[n]] -= 1;
    }
    for (int l = 0; l < len; l++) {
        Array[l] = b[l];
    }
    free(c);
    free(b);
}

void Faster_Sort(int Array[],int began,int end){
    int i,j;

    if (began < end){
        i = began + 1;
        j = end;

        while (i<j){//第一步切割,while结束时i==j
            if (Array[i] > Array[began]){
                Swap(&Array[i],&Array[j]);
                j--;
            } else{
                i++;
            }
        }

        if (Array[i] >= Array[began]){
            i--;
        }
        Swap(&Array[began],&Array[i]);

        Faster_Sort(Array,began,i);
        Faster_Sort(Array,j,end);
    }
}

void test4(){
    clock_t start, finish;
    double time;
    int a[200] ;

    for (int i = 0; i < 200; ++i) {
        a[i] = rand()%200;
    }
    //time start!
    start = clock();

    toString(a,200);
    Caulate_Sort(a,200,200);
    toString(a,200);

    //time up!
    finish = clock();
    time = (double)(finish - start)/CLOCKS_PER_SEC;

    printf("It's cost %lf second!\n",time);
}


//
// Created by Kirito on 2018/11/1.
//

