#include<iostream>
#include<limits.h>
#include"./selSort.h"
#include"./bubbleSort.h"
#include"./insertionSort.h"
#include"./quickSort.h"
#include"./mergeSort.h"

#include"./utils.h"

using namespace std;
int main(){
    int arr[] = {10,9,8,7,6,5,4,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printArray(arr,n);

    quickSort(arr,0,n);
    cout<<endl;
    
    printArray(arr,n);


}