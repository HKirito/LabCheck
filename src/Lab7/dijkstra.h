//
// Created by Kirito on 2018/11/29.
//

#ifndef LABCHECK1_DIJKSTRA_H
#define LABCHECK1_DIJKSTRA_H

#include<iostream>
#include<vector>

using namespace std;

void dijkstra(
        const int &beg,//出发点
        const vector<vector<int> > &adjmap,//邻接矩阵，通过传引用避免拷贝
        vector<int> &dist,//出发点到各点的最短路径长度
        vector<int> &path);

void test6();


#endif //LABCHECK1_DIJKSTRA_H
