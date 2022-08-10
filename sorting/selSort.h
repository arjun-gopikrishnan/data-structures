#ifndef SELSORT_H
#define SELSORT_H
#include<iostream>
void selSort(int arr[],int n) { 
    
    int min,temp;
    for(int i=0;i<n;i++){
        min = i;
        for(int j=i;j<n;j++){
            if(arr[min]>arr[j]){
                min = j;
            }

            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

#endif