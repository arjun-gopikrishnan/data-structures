#include<iostream>
#include<limits.h>
#include"./selSort.h"
#include"./bubbleSort.h"
#include"./insertionSort.h"
#include"./quickSort.h"
#include"./mergeSort.h"
#include"./countSort.h"

#include"./utils.h"

using namespace std;
int main(){
    int arr[] = {1,4,2,18,6,14,4,4,23,17,91,112,34,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printArray(arr,n);
    cout<<endl;
    cout<<endl;
    countSort(arr,n);
}


