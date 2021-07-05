#include<iostream>
#include"./Queue.h"

int main(){
    try{
        Queue<char> *q = new Queue<char>();
        for(char i='a';i<'i';i++){
            q->enqueue(i);
        }
        
        q->display();
        delete q;
    }catch(const char *message){
        cout<<message<<endl;
    }
}