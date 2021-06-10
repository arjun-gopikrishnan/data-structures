#include<iostream>
#include"linkedList.h"
#include"doubleLinkList.h"
#include"circularLinkedList.h"
#include"Node.h"
using namespace std;
int main(){
    LinkedList* list = new LinkedList();

    for(int i=0;i<10;i++){
        list->addNodeHead((i));
    }
    list->oddeven();
    list->display();

}
