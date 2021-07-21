#ifndef CHAINING_H
#define CHAINING_H
#include<iostream>
template<typename DataType>
class LinkedList{
    private:
        class Node{
            public:
            DataType data;
            Node *next;
            Node(){
                next=nullptr;
            }
        };
        Node *root;
    public:
        LinkedList(){
            root=nullptr;
        }
        void SortedInsert(DataType);
        void display();
        bool search(DataType);
};
template<typename DataType>
inline void LinkedList<DataType>::SortedInsert(DataType key){
    Node *newNode = new Node();
    newNode->data=key;
    newNode->next=nullptr;

    if(root==nullptr){
        root = newNode;
        return;
    }

    if(root->data>=key){
        newNode->next=root;
        root=newNode;
        return;
    }

    Node *tracker = root;
    
    while(tracker->next!=nullptr && tracker->next->data< newNode->data){
        tracker=tracker->next;
    }
    newNode->next = tracker->next;
    tracker->next = newNode;
}
template<typename DataType>
inline void LinkedList<DataType>::display(){
    if(root==nullptr)
        return;

    for(Node *temp=root;temp!=nullptr;temp=temp->next)
        std::cout<<temp->data<<" ";

}
template<typename DataType>
inline bool LinkedList<DataType>::search(DataType key){
    if(root==nullptr)
        return false;

    Node *temp = root;
    while(temp!=nullptr && key<=temp->data){
        if(temp->data==key)
            return true;
    }

    return false;
}


#endif