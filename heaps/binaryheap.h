#ifndef binaryHeap_H
#define binaryHeap_H
#include<iostream>
#include <iterator>
#include <ostream>
#include<vector>
void swap(int*,int*);
class MaxHeap{
    private:
        int *heap;
        int size;
        int capacity;
        int parent(int i) { return (i-1)/2; }
        int left(int i) { return (2*i + 1); }
        int right(int i) { return (2*i + 2); }
        int largerChild(int i){
            return heap[left(i)]>heap[right(i)]?left(i):right(i);
        }
    public:
        MaxHeap(int);
        ~MaxHeap(){};
        void insert(int);
        void display();
        int remove();
        void heapSort();
        void heapify(int[],int);
};

inline MaxHeap::MaxHeap(int cap){
    capacity=cap;
    size=0;
    heap = new int[cap];
}

inline void MaxHeap::insert(int key){
    if(size==capacity){
        std::cout<<"Overflow\n";
        return;
    }

    size++;
    int i = size-1;
    heap[i]=key;
    while (i!=0&&heap[parent(i)]<heap[i])
    {
       swap(&heap[i], &heap[parent(i)]);
       i=parent(i);
    }
}

inline void MaxHeap::display(){
    for(int i=0;i<size;i++)
        std::cout<<heap[i]<<" ";
}

inline int MaxHeap::remove(){
    if(size==0){
        std::cout<<"UNDERFLOW!!!\n";
        return 0;
    }
    int tracker;
    int last = heap[size-1];
    int first = heap[0];
    
    for(int i=0;i<size;){
        swap(&heap[i], &heap[largerChild(i)]);
        tracker=i;
        i=largerChild(i);
    }
    swap(&heap[tracker],&last);
    size--;
    return first;
}

inline void MaxHeap::heapSort(){
    int limit = size;
    int resArr[limit];
    for(int i=0;i<limit;i++){
        resArr[limit-i-1]=remove();
    }
    size = limit;
    heap=resArr;
    display();
}

inline void MaxHeap::heapify(int arr[],int length){
    size = length;
    capacity=length;
    delete heap;
    heap = arr;

    for(int i=(size/2)-1;i>=0;i--){
        while(largerChild(i) < size-1){
           if (heap[i] < heap[largerChild(i)]){
               swap(&heap[i],&heap[largerChild(i)]);
               i = largerChild(i);
           } else {
               break;
           }
       }
    }
}

#endif

inline void swap(int *x, int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

