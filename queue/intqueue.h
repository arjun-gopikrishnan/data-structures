#ifndef intQueue_H
#define intQueue_H
#include "../Node.h"
#include<iostream>
#include<string>
using namespace std;
class intQueue{
    private:
        Node* head ;
        int data;
    public:
        intQueue(){head=NULL;};
        ~intQueue(){};
        void enqueue(int);
        void dequeue();
        void display();
};

inline void intQueue::enqueue(int data){
    Node *newNode = new Node;
    if(newNode==NULL)
        throw "OVERFLOW!!";
    newNode->data=data;
    newNode->next=NULL;

    if(head==NULL)
        head=newNode;
    else{
        Node *temp = head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
    
}

inline void intQueue::dequeue(){
    if(head==NULL)
        throw "UNDERFLOW";
    Node *temp = new Node();
    temp = head;
    head = head->next;
    delete temp;
}   

inline void intQueue::display(){
    if(head==NULL)
        throw "UNDERFLOW!!";
    Node* temp = head;
    while(temp!=NULL){
        if(temp->next!=NULL)
            cout<<temp->data<<"->";
        else
            cout<<temp->data;

        temp=temp->next;
    }
}


#endif