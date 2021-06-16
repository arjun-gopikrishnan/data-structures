#ifndef intStack_H
#define intStack_H
#include "Node.h"
#include<iostream>
#include<string>
using namespace std;

class intStack{
    private:
        intNode* top;
        int length;
    public:
        intStack(){top=NULL;length=0;}
        ~intStack(){};
        void push(int);
        int pop();
        int peek();
        void display();
        bool empty();
};

inline void intStack::push(int data){
    intNode* newNode = new intNode();
    if(newNode==NULL)
        cout<<"OVERFLOW!!!";
    else{
        newNode->data=data;
        newNode->next=top; 
        top=newNode;
        length++;
    }
}

inline int intStack::pop(){
    intNode *temp; int x=-1;
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

inline int intStack::peek(){
    if(top==NULL)
        throw "UNDERFLOW";
    return top->data;
}

inline void intStack::display(){
    if(top==NULL)
        cout<<"UNDERFLOW";
    else{
        intNode* temp;
        temp=top;
        while(temp!=NULL){
           cout<<temp->data<<endl;
           temp=temp->next;
        }
    }
}

inline bool intStack::empty(){
    if(top==NULL)
        return true;
    else
        return false;
}


#endif