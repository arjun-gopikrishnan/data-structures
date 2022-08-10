#include<iostream>
#include<limits.h>
#include"./selSort.h"
#include"./bubbleSort.h"
#include"./insertionSort.h"
#include"./utils.h"

using namespace std;
int main(){
    int arr[] = {INT_MIN,9,8,7,6,5,4,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printArray(arr,n,1);

    insertionSort(arr,n);
    cout<<endl;
    
    printArray(arr,n,1);


}