//
// Created by Kirito on 2018/12/12.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;
#define M 1000
typedef struct {
    int weight; //结点权值
    int parent, lchild, rchild; //结点的父指针，左右孩子指针
} HTNode, *HuffmanTree; //动态分配数组存储哈夫曼树
typedef char **HuffmanCode; //动态分配数组存储哈夫曼编码表
int num[27];//统计字符出现的次数并作为权值


int freqchar(char *st);/*统计字符出现的频率*/
void CreateHuffmanTree(HuffmanTree &, int *, int); //生成哈夫曼树
void HuffmanCoding(HuffmanTree, HuffmanCode &, int); //对哈夫曼树进行编码
void PrintHuffmanCode(HuffmanCode, int *, int, char *); //显示哈夫曼编码
void Selected(HuffmanTree, int, int &, int &); //在数组中寻找权值最小的两个结点

int freqchar(char *st)/*统计字符出现的频率*/
{
    int n = 0;// 统计字符的种类
    memset(num, 0, sizeof(num));
    for (int i = 0; i < strlen(st); i++)
    {
        int t = st[i] - 'a';
        num[t]++;
    }
    for (int j = 0; j < 27; j++) {
        if (num[j] != 0) {
            n++;
        }
    }
    return n;
}

void Selected(HuffmanTree HT, int i, int &s1, int &s2) {
    int j, k = 1;
    while (HT[k].parent != 0)
        k++;
    s1 = k;
    for (j = 1; j <= i; ++j) // Select the first least of HT[].weight
        if (HT[j].parent == 0 && HT[j].weight < HT[s1].weight)
            s1 = j;
    k = 1;
    while ((HT[k].parent != 0 || k == s1))
        k++;
    s2 = k;
    for (j = 1; j <= i; ++j) // Select the second  least of HT[].weight
        if (HT[j].parent == 0 && HT[j].weight < HT[s2].weight && j != s1)
            s2 = j;
}

void CreateHuffmanTree(HuffmanTree &HT, int *w, int n) {//w存放n个结点的权值，将构造一棵哈夫曼树HT
    int i, m;
    int s1, s2;
    HuffmanTree p;
    if (n <= 1) return;
    m = 2 * n - 1; //n个叶子结点的哈夫曼树，有2*n-1个结点
    HT = (HuffmanTree) malloc((m + 1) * sizeof(HTNode)); //开辟2*n各结点空间
    for (p = HT + 1, i = 1; i <= n; ++i, ++p, ++w) //进行初始化
    {
        p->weight = *w;
        p->parent = 0;
        p->lchild = 0;
        p->rchild = 0;
    }
    for (; i <= m; ++i, ++p) {
        p->weight = 0;
        p->parent = 0;
        p->lchild = 0;
        p->rchild = 0;
    }
    for (i = n + 1; i <= m; ++i) //建哈夫曼树
    {
        Selected(HT, i - 1, s1, s2);
                                    //从HT[1...i-1]中选择parent为0且weight最小的两个结点，其序号分别为s1和s2
        HT[s1].parent = i;
        HT[s2].parent = i; //修改s1和s2结点的父指针parent
        HT[i].lchild = s1;
        HT[i].rchild = s2; //修改i结点的左右孩子指针
        HT[i].weight = HT[s1].weight + HT[s2].weight; //修改权值
    }
}

void HuffmanCoding(HuffmanTree HT, HuffmanCode &HC, int n) {//将有n个叶子结点的哈夫曼树HT进行编码， 所编的码存放在HC中
//方法是从叶子到根逆向求每个叶子结点的哈夫曼编码
    int i, c, f, start;
    char *cd;
    HC = (HuffmanCode) malloc((n + 1) * sizeof(char *)); //分配n个编码的头指针向量
    cd = (char *) malloc(n * sizeof(char)); //开辟一个求编码的工作空间
    cd[n - 1] = '\0';           //编码结束符
    for (i = 1; i <= n; ++i) //逐个地求哈夫曼编码
    {
        start = n - 1; //编码结束位置
        for (c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent) //从叶子到根逆向求编码
            if (HT[f].lchild == c)
                cd[--start] = '0'; //若是左孩子编为'0'
            else
                cd[--start] = '1'; //若是右孩子编为'1'   
        HC[i] = (char *) malloc((n - start) * sizeof(char)); //为第i个编码分配空间
        strcpy(HC[i], &cd[start]); //将编码从cd复制到HC中
    }
    free(cd); //释放工作空间
}

void PrintHuffmanCode(HuffmanCode HC, int *w, int n, char *c1) {//显示有n个叶子结点的哈夫曼树的编码表
    int i;
    printf("HuffmanCode is :\n");
    cout << "Code" << "---" << "Weight" << "---" << "HuffmanCode" << endl;
    for (i = 1; i <= n; i++)
        cout << c1[i - 1] << "---" << w[i - 1] << "---" << HC[i] << endl;
}

int test10() {
    HuffmanTree HT; //哈夫曼树HT
    HuffmanCode HC; //哈夫曼编码表HC
    int n; //n是哈夫曼树叶子结点数（字符种类的个数）
    int *w; //w存放叶子结点权值
    char *c1;//c1存放字符串中字符的种类
    char a[M];//用于储存输入的字符串
    cout << "Please input String :";
    while (cin >> a) {

        n = freqchar(a);//得到字符种类的个数
        w = (int *) malloc(n * sizeof(int)); //开辟空间存放权值
        c1 = (char *) malloc(n * sizeof(char)); //开辟空间存放权值
        int j;

        for (int i = 0; i < n; i++) {
            for (j = i; j < 27; j++) {
                if (num[j] != 0) {
                    w[i] = num[j];//得到权值
                    c1[i] = j + 'a';//得到字符种类
                    break;//字符与权值相对应
                }
            }
        }

        CreateHuffmanTree(HT, w, n); //生成哈夫曼树
        HuffmanCoding(HT, HC, n); //进行哈夫曼编码
        PrintHuffmanCode(HC, w, n, c1); //显示哈夫曼编码
        printf("Please input String :");
    }
    return 0;
}


























//#include <cstring>
//#include "hfm.h"
//
//int num;//全局变量记录多少种字符（树的叶子数）
//void select(HuffmanTree HT, int k, int&s1, int&s2)// 两节点选最小2个
//{
//    int i, j;
//    int minl = 32767;
//    for (i = 1; i <= k; i++)
//    {
//        if (HT[i].weight<minl&&HT[i].parent == 0)
//        {
//            j = i;
//            minl = HT[i].weight;
//        }
//    }
//    s1 = j;
//    minl = 32767;
//    for (i = 1; i <= k; i++)
//    {
//        if (HT[i].weight<minl&&HT[i].parent == 0 && i != s1)
//        {
//            j = i;
//            minl = HT[i].weight;
//        }
//    }
//    s2 = j;
//}
//
//int countAsc(char *s, int cnt[], char str[])//计数,返回有多少种字符
//{
//    char *p;
//    int i, j, k = 0;
//    int temp[257];
//    for (i = 0; i<257; i++)
//    {
//        temp[i] = 0;
//    }
//    for (p = s; *p != '\0'; p++)//避免对原字符串修改
//    {
//        temp[*p]++;
//    }
//    for (i = 0, j = 0; i <= 256; i++)
//    {
//        if (temp[i] != 0)
//        {
//            j++;
//            str[j] = i;
//            cnt[j] = temp[i];
//        }
//    }
//    num = j;
//    return j;
//}
//
//void createHuffmanTree(HuffmanTree &HT, HuffmanCode &HC, int cnt[], char str[])
//{
//    int i, s1, s2;
//    for (i = 1; i <= 2 * num - 1; i++)//初始化
//    {
//        HT[i].lchild = 0;
//        HT[i].rchild = 0;
//        HT[i].parent = 0;
//        HT[i].weight = 0;
//    }
//    for (i = 1; i <= num; i++)//权值进行赋值
//    {
//        HT[i].weight = cnt[i];
//    }
//    for (i = num + 1; i <= 2 * num - 1; i++)//循环找出最小的两个然后将其相加后的节点向上赋值
//    {
//        select(HT, i - 1, s1, s2);
//        HT[s1].parent = i;
//        HT[s2].parent = i;
//        HT[i].lchild = s1;
//        HT[i].rchild = s2;
//        HT[i].weight = HT[s1].weight + HT[s2].weight;
//    }
//    for (i = 1; i <= num; i++)
//    {
//        HC[i].ch = str[i];
//    }
//}
//
//void huffmanencoding(HuffmanTree &HT, HuffmanCode &HC)
//{
//    int c, p, i;
//    char cd[n];
//    int start;
//    cd[num] = '\0';
//    for (i = 1; i <= num; i++)
//    {
//        start = num;
//        c = i;
//        while ((p = HT[c].parent)>0)
//        {
//            start--;
//            cd[start] = (HT[p].lchild == c) ? '0' : '1';
//            c = p;
//        }
//        strcpy(HC[i].bits, &cd[start]);
//        HC[i].len = num - start;
//    }
//}
//
//void decode(HuffmanCode &HC, char s[])
//{
//    FILE *fp;
//    fopen_s(&fp, "huffman.txt", "r");
//    if (fp==NULL)
//    {
//        return;
//    }
//    char ch;
//    int num = 0;
//    while (ch = getc(fp) != EOF)
//    {
//        num++;
//    }
//    cout << "Succeed read the file " << num << endl;
//    fclose(fp);
//
//    ifstream in("huffman.txt");
//    string line;
//    char result[200];
//    int z = 0;
//    if (in)
//    {
//        while (!in.eof())
//        {
//            in >> ch;
//            result[z] = ch;
//            z++;
//        }
//    }
//    else
//    {
//        cout << "Error to read file " << endl;
//    }
//    result[num] = '\0';
//
//    cout << result << endl;
//    in.close();
//
//    char str[268];
//    char cd[9];
//    int i, j, k = 0, p = 0, flag;
//    while (result[p] != '\0')
//    {
//        flag = 0;
//        for (i = 0; i<num && flag == 0 && result[p] != '/0'; i++)
//        {
//            cd[i] = ' ';
//            cd[i + 1] = '\0';
//            cd[i] = result[p++];
//            for (j = 1; j <= num; j++)
//            {
//                if (strcmp(HC[j].bits, cd) == 0)
//                {
//                    str[k] = HC[j].ch;
//                    k++;
//                    flag = 1;
//                    break;
//                }
//            }
//        }
//    }
//    str[k] = '\0';
//    strcpy(s, str);
//}
//
//void coding(HuffmanCode &HC, char  str[], char get[])
//{
//    int i, j = 0;
//    while (str[j] != '\0')
//    {
//        for (i = 1; i <= num; i++)
//        {
//            if (HC[i].ch == str[j])
//            {
//                strcat(get, HC[i].bits);
//                break;
//            }
//        }
//        j++;
//    }
//    strcat(get, "\0");
//    int len =sizeof(get)/sizeof(get[0]);
//    FILE *fp;
//    fopen_s(&fp, "huffman.txt", "w");
//    fputs(get, fp);
//    fclose(fp);
//}
//
//void test10()
//{
//    char str[257];
//    char st[10000], sresult[10000];
//    int cn[257];
//    HuffmanTree HT;
//    HuffmanCode HC;
//    printf("please Enter your Strings:");
//    scanf("%s", &st);
//    num = countAsc(st, cn, str);
//    str[num + 1] = '\0';
//
//
//    createHuffmanTree(HT, HC, cn, str);
//
//    huffmanencoding(HT, HC);
//    printf("It have %d kind of number\n", num);
//
//    for (int i = 1; i <= num; i++)
//    {
//        printf("char %c count is %d, the HFM number is %s\n", HC[i].ch, cn[i], HC[i].bits);
//    }
//    char get[10000];
//    get[0] = '\0';
//    coding(HC, st, get);
//    printf("It's HFM number is %s\n", get);
////    printf("Result have been saved in huffman.txt...\n");
////    decode(HC, sresult);
////    printf("Encrypt %s\n", sresult);
//}
