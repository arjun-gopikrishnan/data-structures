#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include "DoubleNode.h"
#include<iostream>
using namespace std;
class DoubleLinkedList{
    private:
        DoubleNode * head;
        int length;
    public:
        DoubleLinkedList(){ head = NULL;length=0; }
        void insert(int);
        void display();
        int size(){return length;}
};

inline void DoubleLinkedList::insert(int val){
    DoubleNode* newNode = new DoubleNode();
    newNode->data=val;
    newNode->next=NULL;
    newNode->prev=NULL;
    if(head==NULL){
        head=newNode;
        length++;
    }
    else if(head->next==NULL){
        head->next=newNode;
        newNode->next=NULL;
        newNode->prev=head;
        length++;
    }
    else{
        DoubleNode* temp = new DoubleNode(); 
        temp=head;   
        while(temp->next!=NULL){temp=temp->next;}
        temp->next=newNode;
        newNode->prev=temp;
        newNode->next=NULL;
        length++;
    }
}

inline void DoubleLinkedList::display(){
    DoubleNode* temp = new DoubleNode();
    temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }

}
#endif