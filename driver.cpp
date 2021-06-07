#include<iostream>
#include"linkedList.h"
using namespace std;
int main(){
    LinkedList* list = new LinkedList();
    int n,temp;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>temp;
        list->addNodeHead(temp);
    }

    cout << "Linked List data" << endl;
    
    list->display();
    list->reverse();
    cout<<endl;
    list->display();
    delete list;
    return 0;

}
