#include "../intStack.h"
#include<iostream>
#include<string>
using namespace std;

int solve(int[],int);
int *ngr(int[],int);
int *ngl(int[],int);
int main(){
    int test[]={6,2,5,4,5,1,6};
    int size = sizeof(test)/sizeof(int);
    int area = solve(test,size);
    cout<<area<<endl;
}

int solve(int arr[],int size){
    
    int *rb = ngr(arr,size);  
    int *lb = ngl(arr,size);
    int *areas = new int[size];
    for(int i=0;i<size;i++){
        areas[i] = rb[i]+lb[i];
    }
    int maxarea=areas[0];
    for(int i=0;i<size;i++){
        if(areas[i]>maxarea)
            maxarea=areas[i];
    }

    return maxarea;
}

int *ngr(int arr[],int size){
    int *ngr = new int[size];
    intStack *st = new intStack();
    st->push(arr[size-1]);
    ngr[size-1]=size;

    for(int i=size-2;i>=0;i--){
        while(!st->empty() && arr[i]<arr[st->peek()]){
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

int *ngl(int arr[],int size){
    int *ngl = new int[size];
    intStack *st = new intStack();
    st->push(arr[0]);
    ngl[0]=-1;

    for(int i=1;i<size;i++){
        while(!st->empty() && arr[i]<arr[st->peek()]){
            st->pop();
        }

        if(st->empty()){
            ngl[i]=-1;
        }else{
            ngl[i]=st->peek();
        }
        st->push(i);
    }
    delete st;
    return ngl;
}













// 1. You are given a number n, representing the size of array a.
// 2. You are given n numbers, representing the height of bars in a bar chart.
// 3. You are required to find and print the area of largest rectangle in the histogram.

// e.g.
// for the array [6 2 5 4 5 1 6] -> 12