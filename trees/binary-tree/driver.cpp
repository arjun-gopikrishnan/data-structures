#include<iostream>
#include"./Tree.h"

using namespace std;

int main(){
    Tree<int> *t = new Tree<int>();
    
    for(int i=1;i<=4;i++)
        t->insert(i);

    cout<<"In order traversal\n";
    t->displayInOrder();

    cout<<"\n\nPre order traversal\n";
    t->displayPreOrder();

    cout<<"\n\nPost order traversal\n";
    t->displayPostOrder();
    
    cout<<"\n\nLevel order traversal\n";
    t->levelOrder();

    cout<<"\n\nLength is : "<<t->count()<<endl;
    cout<<"\n\nHeight is : "<<t->height()<<endl;
    cout<<"\n\nNumer of leaf nodes is : "<<t->leafNode()<<endl;


}

