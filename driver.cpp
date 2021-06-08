#include<iostream>
#include"linkedList.h"
#include"circularLinkedList.h"
using namespace std;
int main(){
    CircularList* list = new CircularList();

    for(int i=0;i<5;i++){
        list->insert((5-i));
    }

    list->display();
}
