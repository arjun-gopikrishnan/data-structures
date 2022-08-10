#ifndef UTILS_H
#define UTILS_H
#include<iostream>

void swap(int *x,int *y) { 
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;

}

void printArray(int arr[], int size){
    for(int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
}
  

#endif