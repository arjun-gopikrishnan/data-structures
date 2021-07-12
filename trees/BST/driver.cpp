#include "./BST.h"
#include<iostream>
using namespace std;

int main(){
    BST<int> *bst = new BST<int>();
    int arr[] = {9,8,7,10,1,19,2};
    int size = sizeof(arr)/sizeof(int);
    bst->genPreOrder(arr,size);
    // for(int i=0;i<size;i++)
    //     bst->insert(arr[i]);
    bst->displayInOrder();
    bst->remove(bst->getRoot(),9);
    cout<<endl;
    bst->displayInOrder();
}
