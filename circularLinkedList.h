#include<iostream>
using namespace std;

struct circNode{
    int data;
    circNode *next;
};

class CircularList{
    private:
        circNode *head;
    public:
        CircularList(){
            head=NULL;
        }
        void display();
        void insert(int);
        void insert(int,int);
        //void insertAt(int,int);

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

inline void CircularList::insert(int value){
    circNode* newNode = new circNode();
    newNode->data = value;
    newNode->next=NULL;
    
    if(head==NULL)
        head=newNode;
    else{
        circNode *tracker = new circNode();
        tracker = head;
        while(tracker->next!=head)
            tracker=tracker->next;
        newNode->next=head;
        tracker->next=newNode;
    }
}

inline void CircularList::insert(int index,int value){

}
