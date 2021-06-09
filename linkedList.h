#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
#include<iostream>
using namespace std;


class LinkedList{
    private: Node* head;
    public:
        LinkedList() {
        head = NULL;
        }
        ~LinkedList() {}
        void addNodeHead(int);
        bool insertAt(int,int);
        void addNodeBack(int);
        void reverse();
        void display();
        bool pop();
        bool removeHead();
        int removeAt(int);
        int size();
        int listSum();
        int retMax();
        int retMin();
        int nodeAtIndex(int);
        int search(int);

};

inline void LinkedList::addNodeBack (int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    if(head==NULL)
        head=newNode;
    else{
        newNode->next = head;
        head=newNode;
    }
        
        
}

inline void LinkedList::addNodeHead (int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next=NULL;
    if(head==NULL)
        head=newNode;
    else{
        Node* temp = head;
        while (temp->next != NULL) { 
            temp = temp->next;
        }
        temp->next = newNode;
    }
        
}

inline bool LinkedList::insertAt(int index, int value){
    if(index>=size())
        return 0;
    else{
        Node* newNode = new Node();
        newNode->data=value;
        Node* temp = head;
        int count = 0;
        while(temp!=NULL){
            if(count==index){
                cout<<temp->data<<endl;
                newNode->next = temp->next;
                temp->next=newNode;
                return 1;
            }else{
                temp=temp->next;
                count++;
            }
        }
        return 1;
    }
}
inline bool LinkedList::removeHead(){
    if(head==NULL)
        return 0;
    else if(head->next==NULL){
        head=NULL;
        return 1;
    }else{
        Node*temp = new Node();
        temp=head;
        head=head->next;
        delete temp;
        return 1;
    }
}
inline bool LinkedList::pop(){
    if(head==NULL)
        return 0;
    else if(head->next==NULL){
        head=NULL;
        return 1;
    }
    else{
        Node*prev=NULL;
        Node*temp=head;
        while(temp->next!=NULL){
            prev=temp;
            temp=temp->next;
        }
        prev->next=NULL;
        delete temp;

        return 1;
    }
}

inline void LinkedList::reverse(){
    if(head==NULL)
        return;
    Node* current = new Node();
    Node* next = new Node();
    Node* prev = new Node();
    current=head;
    next=NULL,prev=NULL;

    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
}
inline int LinkedList::removeAt(int index){
    if(head==NULL)
        return 0;
    else if(index>size()-1)
        return 1;
    else if(index == 0){
        int val=removeHead();
        return 2;
    }
    else{
        Node* temp = new Node();
        Node* prev = new Node();
        temp=head;
        prev=NULL;
        for(int i=0;i<index;i++){
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        delete temp;

        return 2;
    }
    
}
inline void LinkedList::display (){
    if(head==NULL)
        cout<<"Empty Stack";
    else{
        Node*temp = head;
        while(temp!=NULL){
            if(temp->next!=NULL)
                cout<<temp->data<<"->";
            else
                cout<<temp->data;
            temp=temp->next;
        }
    }
}

inline int LinkedList::size(){
    int count=0;
    Node* temp = head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}

inline int LinkedList::retMax(){
    Node* temp = head;
    int max=temp->data;
    while(temp!=NULL){
        if(max<temp->data)
            max=temp->data;
        temp=temp->next;
    }
    return max;
}

inline int LinkedList::retMin(){
    Node* temp = head;
    int min=temp->data;
    while(temp!=NULL){
        if(min<temp->data)
            min=temp->data;
        temp=temp->next;
    }
    return min;
}

inline int LinkedList::nodeAtIndex(int index){
    if((index>size()-1) ||(index<0))
        return -1;
    else{
        int count=0;
        Node* temp = head;
        while(temp!=NULL){
        if(count==index)
            break;
        else{
            temp=temp->next;
            count++;
        }
        }
        return temp->data;
    }

}

inline int LinkedList::listSum(){
    int sum=0;
    Node* temp = head;
    while(temp!=NULL){
        sum+=temp->data;
        temp=temp->next;
    }
    return sum;
}

inline int LinkedList::search(int key){
    int flag=0,count=0;
    Node* temp = head;
    while(temp!=NULL){
        if(temp->data == key){
            flag = 1;
            break;
        }else{
            temp=temp->next;
            count++;
        }
    }
    if(flag==0)
        return -1;
    else
     return count;
}

#endif