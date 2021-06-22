#include "../intStack.h"
#include<iostream>
#include<string>
using namespace std;

int* solve(int[],int);
int main(){
    
    int test[]={2,5,9,3,1,12,6,8,7};
    int size=sizeof(test)/sizeof(test[0]);
   
    int *p=solve(test,size);
    for(int i=0;i<size;i++)
        cout<<"Next greater for "<<test[i]<<" is "<<p[i]<<endl;
}

int* solve(int input[],int size){
    int *nge = new int[size];
    intStack *st = new intStack();
    st->push(input[size-1]);
    nge[size-1]=-1;

    for(int i=size-2;i>=0;i--){
        while(!st->empty() && input[i]>st->peek()){
            st->pop();
        }

        if(st->empty()){
            nge[i]=-1;
        }else{
            nge[i]=st->peek();
        }
        st->push(input[i]);
    }
    
    return nge;
}



















// 1. You are given a number n, representing the size of array a.
// 2. You are given n numbers, representing elements of array a.
// 3. You are required to "next greater element on the right" for all elements of array
// 4. Input and output is handled for you.

// "Next greater element on the right" of an element x is defined as the first element to right of x having value greater than x.
// Note -> If an element does not have any element on it's right side greater than it, consider -1 as it's "next greater element on right"
// e.g.