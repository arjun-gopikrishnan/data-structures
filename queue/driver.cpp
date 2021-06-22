#include<iostream>
#include"intqueue.h"

int main(){
    intQueue *q = new intQueue();
    for(int i=0;i<5;i++){
        q->enqueue(i+1);
    }
    q->dequeue();
    delete q;
}