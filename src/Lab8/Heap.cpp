#include "Heap.h"

template <class T>
class MinHeap{
private:
    T *_minHeap;
    int _length,_maxSize;
public:
    MinHeap(int maxSize){
        _maxSize = maxSize;
        _minHeap = new T[_maxSize];
        _length = 0;
    }

    ~MinHeap() = default;

    bool isEmpty(){ return _length ==0; }

    void updateHeapDown(T Heap[],int tmp_index){
        while (tmp_index < this->_length){
            int left_index = 2 * tmp_index + 1;
            int right_index = 2 * tmp_index + 2;
            if (right_index < this->_length){
                if(this->_minHeap[tmp_index] > this->_minHeap[left_index] and this->_minHeap[tmp_index] > this->_minHeap[right_index]){
                    if(this->_minHeap[left_index] > this->_minHeap[right_index]){
                        this->swap(this->_minHeap, tmp_index, right_index);
                        tmp_index = right_index;
                    }else{
                        this->swap(this->_minHeap, tmp_index, left_index);
                        tmp_index =left_index;
                    }
                }else if(this->_minHeap[tmp_index] > this->_minHeap[left_index]){
                    this->swap(this->_minHeap, tmp_index, left_index);
                    tmp_index = left_index;
                }else if(this->_minHeap[tmp_index] > this->_minHeap[right_index]){
                    this->swap(this->_minHeap, tmp_index, right_index);
                    tmp_index = right_index;
                } else{
                    break;
                }
            }else if(left_index < this->_length){
                if(this->_minHeap[tmp_index] > this->_minHeap[left_index]){
                    this->swap(this->_minHeap, tmp_index, left_index);
                    tmp_index = left_index;
                } else{
                    break;
                }
            } else{
                break;
            }
        }
    }

    void updateHeapUp(T Heap[], int tmp_index){
        if(tmp_index<0){ return; }
        int tmp_father = (tmp_index - 1) / 2;
        if(this->_minHeap[tmp_index]<this->_minHeap[tmp_father]){
            swap(this->_minHeap,tmp_father,tmp_index);
            tmp_index = tmp_father;
            updateHeapUp(this->_minHeap,tmp_index);
        }else{
            updateHeapDown(this->_minHeap,tmp_index);
        }
    }

    void swap(T heap[],int a,int b){
        heap[a] = heap[a] + heap[b];
        heap[b] = heap[a] - heap[b];
        heap[a] = heap[a] - heap[b];
    }

    void Insert(T data){
        this->_minHeap[this->_length] = data;
        this->_length++;

        if (this->_length >= this->_maxSize){
            this->_maxSize = this->_maxSize * 2;
            T* temp_Heap = new T[this->_maxSize];

            for (int i = 0; i < this->_maxSize / 2; i++) {
                temp_Heap[i] = this->_minHeap[i];
            }
            this->_minHeap = temp_Heap;
        }

        int tmp_node_index = (this->_length - 1);
        while (tmp_node_index >0) {
            if (this->_minHeap[tmp_node_index] < this->_minHeap[(tmp_node_index - 1) / 2]) {
                T tmp = this->_minHeap[tmp_node_index];
                this->_minHeap[tmp_node_index] = this->_minHeap[(tmp_node_index - 1) / 2];
                this->_minHeap[(tmp_node_index - 1) / 2] = tmp;
                tmp_node_index = (tmp_node_index - 1) / 2;
            } else {
                break;
            }
        }

    }

    T del(){
        if (isEmpty()){
            cerr<<"Empty heap !"<<endl;
            throw "Empty heap exception !";
        }else{
            T top_data = this->_minHeap[0];
            this->_minHeap[0] = this->_minHeap[this->_length - 1 ];
            this->_length --;
            int tmp_node_index = 0;
            updateHeapDown(this->_minHeap,tmp_node_index);
            return top_data;
        }
    }

    void update(T data,int pos){
        this->_minHeap[pos] = data;
        int tmp_father_index = pos/2;
        if (this->_minHeap[pos]<this->_minHeap[tmp_father_index]){
            updateHeapUp(this->_minHeap,pos);
        }else
            updateHeapDown(this->_minHeap,pos);
    }

    void print_Heap(){
        for (int i = 0;i< this->_length;i++) {
            cout<<this->_minHeap[i]<<"\t";
        }cout<<endl;
    }

};


void test8(){
    MinHeap<int>* heap = new MinHeap<int>(10);
    int a[15];
    for (int i = 0; i < 15; ++i) {
        a[i] = rand() % 20;
    }

    //插入
    for (int i = 0; i < 15; i++) {
        heap->Insert(a[i]);
    }
    heap->print_Heap();

    //删除
    int b = heap->del();
    cout<<b<<endl;
    heap->print_Heap();

    //更新
    heap->update(0,6);
    heap->print_Heap();
}

//
// Created by Kirito on 2018/12/13.
//

