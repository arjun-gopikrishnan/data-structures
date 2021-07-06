#ifndef TREE_H
#define TREE_H
#include<iostream>
#include<queue>
#include<string.h>
#include<string>
using namespace std;

template <typename DataType>
class node {
    public:
        DataType data;
        node *left, *right;
        node(){
            left=nullptr;
            right=nullptr;
        }
        node(DataType val){
            data=val;
            left=nullptr;
            right=nullptr;
        }
};

template <typename DataType>
class Tree{
    private: 
        node<DataType>* root;
        void inOrder(node<DataType> *rootNode);
        void preOrder(node<DataType> *rootNode);
        void postOrder(node<DataType> *rootNode);
    public:
        void insert(DataType data);
        void displayInOrder(){
            inOrder(root);
        }
        void displayPreOrder(){
            preOrder(root);
        }
        void displayPostOrder(){
            postOrder(root);
        }

};

template <typename DataType>
void Tree<DataType>::insert(DataType data) {
    if(!root){
        root = new node<DataType>(data);
        return;
    }
    node<DataType> *temp;
    queue<node<DataType>*>q;
    q.push(root);
    while(!q.empty()) 
    {
        temp = q.front();
        q.pop();

        if(temp->left == NULL) {
            temp->left = new node<DataType>(data);
            break;
        }

        else
            q.push(temp->left);
        
        if(temp->right == NULL) {
            temp->right = new node<DataType>(data);
            break;
        }

        else
            q.push(temp->right);
    }
}

template <typename DataType>
void Tree<DataType>::inOrder(node<DataType> *rootNode) {
    if(rootNode == NULL)
        return;
    inOrder(rootNode->left);
    cout << rootNode->data << " ";
    inOrder(rootNode->right);
}

template <typename DataType>
void Tree<DataType>::preOrder(node<DataType> *rootNode) {
    if(rootNode == NULL)
        return;
    cout << rootNode->data << " ";
    preOrder(rootNode->left);
    preOrder(rootNode->right);
}

template <typename DataType>
void Tree<DataType>::postOrder(node<DataType> *rootNode) {
    if(rootNode == NULL)
        return;
    preOrder(rootNode->left);
    preOrder(rootNode->right);
    cout << rootNode->data << " ";
}

#endif