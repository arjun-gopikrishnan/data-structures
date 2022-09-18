#ifndef COUNTORT_H
#define COUNTORT_H
#include<iostream>
#include"./utils.h"

void countSort(int arr[],int size,bool logs = false){

    int range = maxOfArray(arr,size);
    int freq[range+1]{0};

    for(int i=0;i<size;i++)freq[arr[i]]++;

    for(int i=1;i<=range;i++)freq[i]+=freq[i-1];

    int result[size]{0};

    for(int i=0;i<size;i++){

        if(logs){
            printArray(result,size);
            std::cout<<std::endl;
        }
        result[freq[arr[i]]-1] = arr[i];
        freq[arr[i]]--;
    }
    
    printArray(result,size);

}

#endif