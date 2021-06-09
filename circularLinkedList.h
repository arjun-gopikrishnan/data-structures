#include<iostream>
using namespace std;

struct circNode{
    int data;
    circNode *next;
};

class CircularList{
    private:
        circNode *head;
        int length;
    public:
        CircularList(){
            head=NULL;
            length=0;
        }
        void display();
        int index(int);
        void insert(int);
        void insert(int,int);
        void remove();
        void remove(int);
        void reverse();
        int size(){return length;}

};

inline void CircularList::display(){
    if(head==NULL)
        cout<<"Underflow";
    else{
        circNode *tracker = new circNode();
        tracker = head;
        do{
            cout<<tracker->data<<"->";
            tracker=tracker->next;
        }while(tracker!=head);
    }
}

inline int CircularList::index(int index){
    if(head==NULL){
        throw "UNDERFLOW";
    }
    if(index>length-1)
        throw "EXCEEDS LENGTH";
    circNode* newNode = new circNode();
    newNode=head;
    for(int i=0;i<index;i++)newNode=newNode->next;
    return newNode->data;

}

inline void CircularList::insert(int value){
    circNode* newNode = new circNode();
    newNode->data = value;
    
    if(head==NULL){
        head=newNode;
        head->next=head;
    }
    else{
        circNode *tracker = new circNode();
        tracker = head;
        while(tracker->next!=head)
            tracker=tracker->next;
        tracker->next=newNode;
        newNode->next=head;
        
    }
    length++;
}

inline void CircularList::insert(int index,int value){
    if(index>length-1)
        return ;
    if(head==NULL)
        return;
    else{
        circNode *tracker = new circNode();
        circNode *newNode = new circNode();
        newNode->data=value;
        tracker=head;
        for(int i=0;i<index;i++)tracker=tracker->next;
        newNode->next=tracker->next;
        tracker->next=newNode;
        length++;
    }
}

inline void CircularList::remove(){
    if(head==NULL)
        return;
    else{
        circNode *tracker = new circNode();
        circNode *temp = new circNode();
        temp=head;
        tracker = head;
        while(tracker->next!=head)
            tracker=tracker->next;
        head=head->next;
        tracker->next=head;
        delete temp;
    }
}

inline void CircularList::remove(int index){
    if(head==NULL)
        return;
    if(index==0)
        remove();
    else if(index>length-1)
        return;
    else{
        circNode *temp = new circNode();
        circNode *prev = new circNode();
        temp=head;
        prev=NULL;
        for(int i=0;i<index;i++){
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        delete temp;
    }
}

inline void CircularList::reverse(){
    if(head==NULL)
        return;
    circNode* prev = new circNode();
    circNode* current = new circNode();
    circNode* next = new circNode(); 
    current=head,next=prev=NULL;

    do{
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }while(current!=head);

    head->next=prev;
    head=prev;
}