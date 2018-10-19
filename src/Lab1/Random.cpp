#include <iostream>
#include "Random.h"

using namespace std;

int get_rand(int upbound){
    return rand() % upbound;
}

void test1(){
    int num = 0;
    cout<<"Enter your num:"<<endl;
    cin>>num;
    srand((unsigned)time(NULL));
    int r = rand() % num;
    cout<< r<<" "<<endl;
}
//
// Created by Kirito on 2018/10/18.
//

