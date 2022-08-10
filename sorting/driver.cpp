#include<iostream>
#include"./selSort.h"
#include"./bubbleSort.h"

using namespace std;
int main(){
    int arr[] = {10,9,8,7,6,5,4,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    for(int i=0;i<n;i++)cout<<arr[i]<<" ";

    selSort(arr,n);
    cout<<endl;
    
    for(int i=0;i<n;i++)cout<<arr[i]<<" ";


}