#include<iostream>
#include"linkedList.h"
#include"doubleLinkList.h"
#include"circularLinkedList.h"
#include"Node.h"
using namespace std;
int main(){
    LinkedList* list = new LinkedList();

    list->addNodeHead(1);
    list->addNodeHead(5);
    list->addNodeHead(2);
    list->addNodeHead(-22);
    list->addNodeHead(7);
    list->addNodeHead(3);
    list->addNodeHead(6);
    list->addNodeHead(8);
    list->addNodeHead(-5);

    list->display();
    cout<<endl;
    list->mergeSort();    
    cout<<endl;    
    list->display();


}
