#ifndef MaxHeap_H
#define MaxHeap_H
#include <climits>
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
        
    public:
        MaxHeap(int);
        MaxHeap(int[],int);
        ~MaxHeap(){};
        void insert(int);
        void display();
        int extractMax();
        int getMax(){ return size==0?INT_MAX:heap[0]; }
        void MaxHeapify(int);
};

inline MaxHeap::MaxHeap(int cap){
    size=0;
    capacity=cap;
    heap = new int[cap];
}

inline MaxHeap::MaxHeap(int arr[],int lim){
    size=lim;
    capacity=lim;
    heap = new int[capacity];
    heap=arr;
    int i=size;
    while(i>=0){
        MaxHeapify(i--);
    }
    
}

inline void MaxHeap::insert(int key){
    if(size==capacity)
        throw "Overflow!!!";

    heap[size++]=key;
    int i = size-1;
    while (i!=0 && heap[parent(i)] < heap[i])
    {
       swap(&heap[i], &heap[parent(i)]);
       i = parent(i);
    }
  
}

inline void MaxHeap::display(){
    if(size==0)
        return;
    for(int i=0;i<size;i++)
        std::cout<<heap[i]<<" ";
}

inline int MaxHeap::extractMax(){
    if(size==0)
        return INT_MAX;
    if(size==1)
        return heap[--size];
    int root=heap[0];
    heap[0]=heap[(size--)-1];
    MaxHeapify(0);
    return root;
}

inline void MaxHeap::MaxHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int largest = i;

    
    if (l<size&&heap[l]>heap[i])
        largest=l;
    if (r<size&&heap[r]>heap[largest])
        largest=r;
    if (largest!=i)
    {
        swap(&heap[i], &heap[largest]);
        MaxHeapify(largest);
    }
}

#endif

inline void swap(int *x, int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

