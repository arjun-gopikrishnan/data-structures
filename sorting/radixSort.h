#ifndef RADIXSORT_H
#define RADIXSORT_H
#include<iostream>
#include"./utils.h"

void countingSort(int arr[],int size,int exp){
    
    int output[size];
    int i=0,count[10]={0};
    
    for(i=0;i<size;i++)\
        count[(arr[i]/exp)%10]++;

    for(i=1;i<10;i++){
        count[i] +=count[i-1];
    }

    for(i=size-1;i>=0;i--){
        output[count[(arr[i]/exp)%10]-1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    
    for(i=0;i<size;i++)
        arr[i]=output[i];

}

void radixSort(int arr[],int size,bool logs = false){

    int max = maxOfArray(arr,size);

    for(int i=1;(max/i)>0;i*=10){
        countingSort(arr,size,i);
        if(logs){
            printArray(arr,size);
            std::cout<<std::endl;
        }
    }

}


#endif