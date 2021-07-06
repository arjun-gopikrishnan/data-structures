#include<iostream>
#include"./Tree.h"

using namespace std;

int main(){
    Tree<char> *t = new Tree<char>();
    
    for(char i='a';i<'e';i++)
        t->insert(i);

    cout<<"In order traversal\n";
    t->displayInOrder();

    cout<<"\n\nPre order traversal\n";
    t->displayPreOrder();

    cout<<"\n\nPost order traversal\n";
    t->displayPostOrder();
}

/*OUTPUT 

In order traversal
d b a c 

Pre order traversal
a b d c
 
Post order traversal
b d c a

*/