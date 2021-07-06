#include<iostream>
#include"./Tree.h"

using namespace std;

int main(){
    Tree<char> *t = new Tree<char>();
    
    for(char i='a';i<'z';i++)
        t->insert(i);

    cout<<"In order traversal\n";
    t->displayInOrder();

    cout<<"\n\nPre order traversal\n";
    t->displayPreOrder();

    cout<<"\n\nPost order traversal\n";
    t->displayPostOrder();
    
    cout<<"\n\nLevel order traversal\n";
    t->levelOrder();

}

