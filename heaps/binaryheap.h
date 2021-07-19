#ifndef binaryHeap_H
#define binaryHeap_H
#include<iostream>
#include <iterator>
#include<vector>
class Heap{
    private:
        std::vector<int> heap;
        int size;
    public:
        Heap();
        ~Heap(){};
        void insert(int);
        void display();
        void remove();
        void heapSort();
};

inline Heap::Heap(){
    size=0;
}

inline void Heap::insert(int key){
    heap.push_back(key);
    int i=size;
    while(i>0 && key>heap[i/2]){
        heap[i]=heap[i/2];
        i/=2;
    }
    heap[i]=key;
    size++;
}

inline void Heap::display(){
    for(int i:heap)
        std::cout<<i<<" ";
    std::cout<<std::endl;
}

inline void Heap::remove(){
    int temp,i,j,x = heap[size];

    heap[0] = heap[size-1];
    i=0;j=2*i;
    while(i<size-1){
        if(heap[j+1]>heap[j]){
            j++;
        }if(heap[i]<heap[j]){
            temp=heap[i];
            heap[i]=heap[j];
            heap[j]=temp;
            i=j;
            j*=2;
        }else {
            break;
        }
        
    }
    heap.pop_back();
    size--;
    heap[size]=x;
}

inline void Heap::heapSort(){
    while(size){
        int temp,i,j,x = heap[size];
        int large = heap[0];
        heap[0] = heap[size-1];
        i=0;j=2*i;
        while(i<size-1){
            if(heap[j+1]>heap[j]){
                j++;
            }if(heap[i]<heap[j]){
                temp=heap[i];
                heap[i]=heap[j];
                heap[j]=temp;
                i=j;
                j*=2;
            }else {
                break;
            }

        }
        //heap.pop_back();
        heap[size]=large;
        size--;
        heap[size]=x;
        display();
    }
    size=heap.size()-1;    
}

#endif