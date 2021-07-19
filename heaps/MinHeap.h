#ifndef MinHeap_H
#define Minheap_H
#include <climits>
#include<iostream>
#include <iterator>
#include <ostream>
#include<vector>
void Swap(int*,int*);
class MinHeap{
    private:
        int *heap;
        int size;
        int capacity;
        int parent(int i) { return (i-1)/2; }
        int left(int i) { return (2*i + 1); }
        int right(int i) { return (2*i + 2); }
        
    public:
        MinHeap(int);
        MinHeap(int[],int);
        ~MinHeap(){};
        void insert(int);
        void display();
        int extractMin();
        int getMin(){ return size==0?INT_MAX:heap[0]; }
        void MinHeapify(int);
};

inline MinHeap::MinHeap(int cap){
    size=0;
    capacity=cap;
    heap = new int[cap];
}

inline MinHeap::MinHeap(int arr[],int lim){
    size=lim;
    capacity=lim;
    heap = new int[capacity];
    heap=arr;
    int i=size;
    while(i>=0){
        MinHeapify(i--);
    }
    
}

inline void MinHeap::insert(int key){
    if(size==capacity)
        throw "Overflow!!!";

    heap[size++]=key;
    int i = size-1;
    while (i!=0 && heap[parent(i)] > heap[i])
    {
       Swap(&heap[i], &heap[parent(i)]);
       i = parent(i);
    }
  
}

inline void MinHeap::display(){
    if(size==0)
        return;
    for(int i=0;i<size;i++)
        std::cout<<heap[i]<<" ";
}

inline int MinHeap::extractMin(){
    if(size==0)
        return INT_MAX;
    if(size==1)
        return heap[--size];
    int root=heap[0];
    heap[0]=heap[(size--)-1];
    MinHeapify(0);
    return root;
}

inline void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;

    
    if (l<size&&heap[l]<heap[i])
        smallest=l;
    if (r<size&&heap[r]<heap[smallest])
        smallest=r;
    if (smallest!=i)
    {
        Swap(&heap[i], &heap[smallest]);
        MinHeapify(smallest);
    }
}

#endif

inline void Swap(int *x, int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

