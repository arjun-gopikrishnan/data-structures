#include<iostream>
#include"linkedList.h"
#include"circularLinkedList.h"
using namespace std;
int main(){
    CircularList* list = new CircularList();
    int n,temp;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>temp;
        list->insert(temp);
    }
    list->display();

}
