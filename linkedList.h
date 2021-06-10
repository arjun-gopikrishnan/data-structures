#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
#include<iostream>
using namespace std;


class LinkedList{
    private: 
        Node* head;
        LinkedList* mergeSort(Node*,Node*);
        Node * Head();
        Node*  Tail();

    public:
        LinkedList() {
        head = NULL;
        }
        ~LinkedList() {}
        LinkedList* merge(LinkedList*,LinkedList*);
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
        void concatenate(LinkedList*);
        void mergeSort();
        Node* midNode();
        Node* midNode(Node*, Node *);

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

inline void LinkedList::concatenate(LinkedList *list_2){
    if(head==NULL)
        head=list_2->head;
    else{
        Node* tracker = new Node();
        for(tracker=head;tracker->next!=NULL;tracker=tracker->next);
        tracker->next=list_2->head;
    }
 
}

inline Node* LinkedList::midNode(){
    if(head==NULL)
        return NULL;
    Node *tracker = new Node();
    Node *trackerFast = new Node();
    tracker=trackerFast=head;
    while(trackerFast->next!=NULL&&trackerFast->next->next!=NULL){
        tracker=tracker->next;
        trackerFast=trackerFast->next->next;
    }

    return tracker;
}
inline Node* LinkedList::midNode(Node* start, Node* end){
    if(head==NULL)
        throw "Empty List";
    Node *tracker = new Node();
    Node *trackerFast = new Node();
    tracker=trackerFast=start;
    while(trackerFast->next!=end &&trackerFast!=end){
        tracker=tracker->next;
        trackerFast=trackerFast->next->next;
    }
    // cout<<"head : "<<start->data<<endl;
    // cout<<"end : "<<end->data<<endl;
    // cout<<"mid : "<<tracker->data<<endl;
    
    return tracker;
}


inline Node* LinkedList::Head(){
    if(head==NULL)
        throw "EMPTY LIST";
    return head;
}

inline Node* LinkedList::Tail(){
    if(head==NULL)
        throw "EMPTY LIST";
    Node *tracker = new Node();
    tracker=head;
    while(tracker->next!=NULL)tracker=tracker->next;
    return tracker;
}

inline void LinkedList::mergeSort(){
    if(head==NULL)
        return;
    if(Head()==Tail()){
        return;
    }
    addNodeHead(10);
    LinkedList *nl = new LinkedList();
    nl = mergeSort(Head(),Tail());
    head=NULL;
    concatenate(nl);
    delete nl;

}

inline LinkedList* LinkedList::mergeSort(Node* headNode, Node* tailNode){
    if(headNode == tailNode||headNode->next == tailNode){
        LinkedList* newList = new LinkedList();
        newList->addNodeHead(headNode->data);
       
        return newList;
    }
    else{
        
        LinkedList *fsh = new LinkedList();
        LinkedList *ssh = new LinkedList();
        LinkedList *nl = new LinkedList();
        Node* middle = new Node();
        middle = midNode(headNode,tailNode);
        fsh = mergeSort(headNode,middle);
        
        //cout<<"HEAD : "<<headNode->data<<endl;
        //cout<<"MID : "<<middle->data<<endl;
        //cout<<"TAIL : "<<tailNode->data<<endl;

        fsh = mergeSort(headNode,middle);
        ssh = mergeSort(middle,tailNode);
        nl=merge(fsh,ssh);
        delete fsh;
        delete ssh;
        return nl;

    }
    return NULL;
}
inline LinkedList* LinkedList::merge(LinkedList* fsh, LinkedList* ssh){
    Node *one = fsh->Head();
    Node *two = ssh->Head();
    LinkedList *ml = new LinkedList();
    while (one != NULL && two != NULL) {
        if (one->data < two->data) {
            ml->addNodeHead(one->data);
            one = one->next;
        }else {
            ml->addNodeHead(two->data);
            two = two->next;
        }
    }

      while (one != NULL) {
        ml->addNodeHead(one->data);
        one = one->next;
      }

      while (two != NULL) {
        ml->addNodeHead(two->data);
        two = two->next;
      }

    return ml;
}

#endif