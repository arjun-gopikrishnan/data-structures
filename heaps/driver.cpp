#include <iostream>
#include <iterator>
#include <ostream>
#include"./binaryheap.h"
using namespace std;

int main(){
    int arr[] = {30,25,20,10,5,40,35,36,89,91,54,32,34,43};
    int size=sizeof(arr)/sizeof(int);
    MaxHeap a(size);
    a.heapify(arr,size);
    a.display();

}