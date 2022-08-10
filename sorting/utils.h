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
  

#endif