#include "../intStack.h"
#include<iostream>
#include<string>
using namespace std;
int *solve(int[],int);

int main(){
    int array[] = {2,5,9,3,1,12,6,8,7};
    int *solution=solve(array,sizeof(array)/sizeof(int));
    for(int i=0;i<sizeof(array)/sizeof(int);i++){
        cout<<"span for "<<array[i]<<" is "<<solution[i]<<endl;
    }
};

int *solve(int a[],int size){
    int *span = new int[size];
    intStack *st = new intStack();
    st->push(0);
    span[0]=1;
    
    for(int i=1;i<size;i++){
        while((!st->empty() && a[i]>a[st->peek()])){
            st->pop();
        }
        if(st->empty()){
            span[i]=i+1;
        }else{
            span[i]=i-st->peek();
        }
        st->push(i);
    }

    return span;
}