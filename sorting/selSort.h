#ifndef SELSORT_H
#define SELSORT_H
#include<iostream>
#include"./swap.h"
void selSort(int arr[],int n) { 
    
    int min;
    for(int i=0;i<n;i++){
        min = i;
        for(int j=i;j<n;j++){
            if(arr[min]>arr[j]){
                min = j;
            }

            swap(&arr[i],&arr[min]);
        }
    }
}

#endif