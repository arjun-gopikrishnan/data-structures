#ifndef UTILS_H
#define UTILS_H
#include<iostream>

void swap(int *x,int *y) { 
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;

}

void printArray(int arr[], int size,int start=0){
    for(int i = start; i < size; i++)
        std::cout << arr[i] << " ";
}
  
int maxOfArray(int arr[],int size){
    
    int maxOf = arr[0]; 
    for(int i=0;i<size;i++)maxOf = maxOf>arr[i]?maxOf:arr[i];

    return maxOf;
}

#endif