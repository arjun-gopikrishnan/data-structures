#include <iostream>
#include <iterator>
#include <ostream>
#include"./MaxHeap.h"
#include"./MinHeap.h"
using namespace std;
void MaxHeapTest();
void MinHeapTest();
int main(){
    MaxHeapTest();
    MinHeapTest();
}

void MaxHeapTest(){
    int arr[] = {30,25,20,10,5,35,36};
    int size=sizeof(arr)/sizeof(int);
    MaxHeap a(arr,size);
    a.display();
    
    for(int i=0;i<size;i++){
        a.extractMax();
        cout<<endl;
        a.display();
    }

}

void MinHeapTest(){
    int arr[] = {30,25,20,10,5,35,36};
    int size=sizeof(arr)/sizeof(int);
    MinHeap a(arr,size);
    a.display();
    
    for(int i=0;i<size;i++){
        a.extractMin();
        cout<<endl;
        a.display();
    }
}