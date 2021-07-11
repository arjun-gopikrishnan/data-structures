#include "./BST.h"
#include<iostream>
using namespace std;

int main(){
    BST<int> *bst = new BST<int>();
    int arr[] = {9,8,7,10};
    for(int i:arr){
        bst->Rinsert(i);
    }
    bst->displayInOrder();
    bst->remove(bst->getRoot(),9);
    cout<<endl;
    bst->displayInOrder();

}
