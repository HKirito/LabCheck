#include <stdio.h>

int Search(int a[],int len,int key){//普通线性
    int ans = -1;
    for(int i=0;i<len;i++){
        if(a[i]==key){
            ans=i;
        }
    }
    return ans;
}

int BetterSearch(int a[],int len,int key){//单出口线性
    int i;
    for(i=len-1;i>=0;i--){
        if(a[i]==key){
            break;
        }
    }
    return i;
}

int Sentienl_Search(int a[],int len,int key){//保证有输出的线性查找
    int last=a[len-1];
    int i = 0;
    while(a[i]!=key){//防止越界
        i++;
    }
    a[len-1]=last;
    if(i<len-1||a[len-1]==key) {
        return i;
    }
    else
        return -1;
}

int RECURSIVE_LINEAR_SEARCH(int a[],int n,int i,int key){
    if(i>n){
        return -1;
    }else if(a[i] == key){
        return i;
    }else{
        return RECURSIVE_LINEAR_SEARCH(a,n,i+1,key);
    }
}

void test2(){
    int a[10]={5,6,1,5,2,7,9,4,8,3};
    int answer = 0;
    int key;
    printf("[");
    for(int i = 0;i < 10 ; i++){
        printf(" %d ",a[i]);
    }printf("]");
    printf("Enter your key :");
    scanf("%d",&key);
    answer = RECURSIVE_LINEAR_SEARCH(a,10,0,key)+1;
    if(answer>0)
        printf("Answer is %d \n",answer);
    else
        printf("key was not found!\n");
}

//
// Created by Kirito on 2018/10/18.
//

