#include<iostream>
#include"./selSort.h"
#include"./bubbleSort.h"
#include"./utils.h"

using namespace std;
int main(){
    int arr[] = {10,9,8,7,6,5,4,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printArray(arr,n);

    bubbleSort(arr,n);
    cout<<endl;
    
    printArray(arr,n);


}