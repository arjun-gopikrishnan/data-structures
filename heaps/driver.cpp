#include <iostream>
#include <iterator>
#include <ostream>
#include"./binaryheap.h"
using namespace std;

int main(){
    Heap a;
    int arr[] = {10,20,30,25,5,40,35};
    for(int i:arr)
        a.insert(i);
    
    a.heapSort();
    a.display();
    // for(int i=0;i<3;i++){
    //     a.remove();
    //     cout<<endl;
    //     a.display();
    // }
}