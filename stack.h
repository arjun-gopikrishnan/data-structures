#ifndef STACK_H
#define STACK_H
#include "charNode.h"
#include<iostream>
#include<string>
using namespace std;

class Stack{
    private:
        Node* head;
    public:
        Stack(){head=NULL;}
        ~Stack(){};
        void push(char);
        char pop();
        char Top();
        void display();
};

inline void Stack::push(char data){
    Node* newNode = new Node();
    newNode->next=NULL;
    newNode->data=data;
    if(head==NULL)
        head=newNode;
    else{
        Node* temp = new Node();
        for(temp=head;temp->next!=NULL;temp=temp->next);
        temp->next=newNode;
    }
}

inline char Stack::pop(){
    if(head==NULL)
        throw NULL;
    else if(head->next==NULL){
        Node* temp = new Node();
        char popped = head->data;
        temp=head;
        head=NULL;
        delete temp;
        return popped;
    }
    else{

        char popped;
        Node* temp = new Node();
        Node* prev = new Node();
        temp=head;
        prev=NULL;
        while(temp->next!=NULL){
            prev=temp;
            temp=temp->next;
        }
        popped=prev->data;
        prev->next=NULL;
        delete temp;
        return popped;
    }
}

inline char Stack::Top(){
    if(head==NULL)
        throw NULL;
    else if(head->next==NULL){
        return head->data;
    }
    else{
        char popped;
        Node* temp = new Node();
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        delete temp;
        return popped;
    }
}


inline void Stack::display(){
    if(head==NULL)
        cout<<"UNDERFLOW";
    else{
        Node* temp = new Node();
        for(temp=head;temp!=NULL;temp=temp->next){
            if(temp->next!=NULL)
                cout<<temp->data;
            else
                cout<<temp->data;
        }
    }
}


#endif