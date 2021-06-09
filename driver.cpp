#include<iostream>
#include"linkedList.h"
#include"doubleLinkList.h"
#include"circularLinkedList.h"
using namespace std;
int main(){
    DoubleLinkedList* list = new DoubleLinkedList();

    for(int i=0;i<5;i++){
        list->insert((5-i));
    }
    
    list->display();
}
