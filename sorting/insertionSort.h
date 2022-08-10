#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H
#include<iostream>
#include"./utils.h"
void insertionSort(int arr[],int n) { 
    for(int i=1;i<n;i++){
        int k=i-1;
        int temp=arr[i];
        while(k>=0 && arr[k]>temp){
            arr[k+1]=arr[k];
            k--;
        }

        arr[k+1]=temp;
        
    }
}

#endif