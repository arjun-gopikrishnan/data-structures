#include "../intStack.h"
#include<iostream>
#include<string>
using namespace std;

void solve(int[],int,int);
int* ngr(int[],int);

int main(){
    
    int arr[] = {2,9,3,8,1,7,12,6,14,4,32,0,7,19,8,12,6};
    int size = sizeof(arr)/sizeof(int);
    int k=4;
    solve(arr,size,k);

}

void solve(int arr[],int size,int k){
    int j;
    int *solution = new int[size];
    int *nge = ngr(arr,size);
    
    for(int i=0;i<=size-k;i++){
        if(j<i){
            j=i;
        }
        while(nge[j]<i+k){
            j = nge[j];   
        }
        cout<<arr[j]<<" ";
    }
}

int *ngr(int arr[],int size){
    int *ngr = new int[size];
    intStack *st = new intStack();
    st->push(arr[size-1]);
    ngr[size-1]=size;

    for(int i=size-2;i>=0;i--){
        while(!st->empty() && arr[i]>=arr[st->peek()]){
            st->pop();
        }

        if(st->empty()){
            ngr[i]=size;
        }else{
            ngr[i]=st->peek();
        }
        st->push(i);
    }
    delete st;
    return ngr;
}


















// 1. You are given a number n, representing the size of array a.
// 2. You are given n numbers, representing the elements of array a.
// 3. You are given a number k, representing the size of window.
// 4. You are required to find and print the maximum element in every window of size k.
