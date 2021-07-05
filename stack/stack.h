#ifndef STACK_H
#define STACK_H
#include "../charNode.h"
#include<iostream>
#include<string>
using namespace std;

class Stack{
    private:
        Node* top;
        int length;
    public:
        Stack(){top=NULL;length=0;}
        ~Stack(){};
        void push(char);
        char pop();
        char peek();
        void display();
        bool empty();
};

inline void Stack::push(char data){
    Node* newNode = new Node();
    if(newNode==NULL)
        cout<<"OVERFLOW!!!";
    else{
        newNode->data=data;
        newNode->next=top; 
        top=newNode;
        length++;
    }
}

inline char Stack::pop(){
    Node *temp; char x=-1;
    if(top==NULL){}
    else{
        x=top->data;
        temp=top;
        top=top->next;
        delete temp;
        length--;
    }
    return x;
}

inline char Stack::peek(){
    if(top==NULL)
        throw "UNDERFLOW";
    return top->data;
}

inline void Stack::display(){
    if(top==NULL)
        cout<<"UNDERFLOW";
    else{
        Node* temp;
        temp=top;
        while(temp!=NULL){
           cout<<temp->data<<endl;
           temp=temp->next;
        }
    }
}

inline bool Stack::empty(){
    if(top==NULL)
        return true;
    else
        return false;
}


#endif