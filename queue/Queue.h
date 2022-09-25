#ifndef Queue_H
#define Queue_H
#include "./QNode.h"
#include<iostream>
#include<string>
using namespace std;

template<typename DataType>
class Queue{
    private:
        QNode<DataType> *head ;
    public:
        Queue(){head=nullptr;};
        ~Queue(){};
        void enqueue(DataType);
        void dequeue();
        void display();
};

template <typename DataType> void Queue<DataType>::enqueue(DataType data){
    QNode<DataType> *newNode = new QNode<DataType>;
    if(newNode==nullptr)
        throw "OVERFLOW!!";

    newNode->data=data;
    newNode->next=nullptr;

    if(head==nullptr)
        head=newNode;
    else{
        QNode<DataType> *temp = head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=newNode;
    }
    
}

template <typename DataType> void Queue<DataType>::dequeue(){
    if(head==nullptr)
        throw "UNDERFLOW";
    QNode<DataType> *temp = new QNode<DataType>;
    temp = head;
    head = head->next;
    delete temp;
}   

template <typename DataType> void Queue<DataType>::display(){
    if(head==nullptr)
        throw "UNDERFLOW!!";
    QNode<DataType> *temp = head;
    while(temp!=nullptr){
        if(temp->next!=nullptr)
            cout<<temp->data<<"->";
        else
            cout<<temp->data;

        temp=temp->next;
    }
}


#endif