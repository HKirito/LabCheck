#include "Fiblaq.h"

int BETTER_LOOP_FEI(int n){
    int a,b;
    int result[1000];
    for(int i=0;i<1000;i++) {
        result[i] = -1;
    }
    result[0] = 0;
    result[1] = 1;
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(result[n-1]!=-1){
        a = result[n-1];
    }else{
        a = BETTER_LOOP_FEI(n-1);
        result[n-1] = a;
    }
    if(result[n-2]!=-1){
        b = result[n-2];
    }else{
        b = BETTER_LOOP_FEI(n-2);
        result[n-2] = b;
    }
    return BETTER_LOOP_FEI(n);
}

long Fib(int month){

    if (month == 1 || month == 2)
        return 1;
    else
        return Fib(month - 1) + Fib(month - 2);
}

long long Final_Fib(int n){
    if ( n < 0){
        return 0;
    }
    if (n <= 1){
        return 1;
    }
    long long one = 1;
    long long two = 0;
    long long f[n];
    f[0]=f[1]=1;

    for (int i = 2; i <=n; i++) {
        f[i] = one + two;
        two = one;
        one = f[i];
    }
    return f[n];
}

int FACTORIAL(int n) {
    if(n==0){
        return 1;
    }else{
        int result = FACTORIAL(n-1)*n;
        return result;
    }
}
void test3(){
    int month;
    printf("Enter a month in Fib: ");
    scanf("%d",&month);
    long long result = Final_Fib(month);
    printf("Fib in %d month later,having %lld rabbit",month,result);}

//
// Created by Kirito on 2018/10/18.
//

