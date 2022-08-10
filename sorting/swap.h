#ifndef SWAP_H
#define SWAP_H
#include<iostream>
void swap(int *x,int *y) { 
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;

}

#endif