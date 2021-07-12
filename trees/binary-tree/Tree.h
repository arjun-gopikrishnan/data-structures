#ifndef TREE_H
#define TREE_H
#include<iostream>
#include<queue>
#include<string.h>
#include<string>
using namespace std;


template <typename DataType>
class Tree{
    private: 
        template <typename NodeType>
        class node {
            public:
                NodeType data;
                node *left, *right;
                node(){
                    left=nullptr;
                    right=nullptr;
                }
                node(NodeType val){
                    data=val;
                    left=nullptr;
                    right=nullptr;
                }
        };
        node<DataType>* root;
        void inOrder(node<DataType>*);
        void preOrder(node<DataType>*);
        void postOrder(node<DataType>*);
        int count(node<DataType>*);
        int height(node<DataType>*);
        int leafNode(node<DataType>*);


    public:
        Tree(){root=nullptr;}
        ~Tree(){};
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
        void levelOrder();
        int count();
        int height();
        int leafNode();


};

template <typename DataType>
void Tree<DataType>::levelOrder(){
    queue<node<DataType>*>q;
    q.push(root);
    node<DataType> *temp=q.front();
    cout<<temp->data<<" ";
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(temp->left){
            cout<<temp->left->data<<" ";
            q.push(temp->left);
        }
        if(temp->right){
            cout<<temp->right->data<<" ";
            q.push(temp->right);
        };     
    }  
}

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

template <typename DataType>int Tree<DataType>::count() {
    int x=0,y=0;
    if(root!=nullptr){
        x=count(root->right);
        y=count(root->left);

        return x+y+1;
    }
    return 0;
}

template <typename DataType>int Tree<DataType>::count(node<DataType> *Node) {
 int x=0,y=0;
    if(Node!=nullptr){
        x=count(Node->right);
        y=count(Node->left);

        return x+y+1;
    }
    return 0;
}

template <typename DataType>int Tree<DataType>::height() {
    int x=0,y=0;
    if(root==nullptr)
        return 0;
    x=height(root->left);
    y=height(root->right);
    
    if(x>y)
        return x+1;
    else 
        return y+1;
}

template <typename DataType>int Tree<DataType>::height(node<DataType> *Node) {
    int x=0,y=0;
    if(Node==nullptr)
        return 0;
    
    x=height(Node->right);
    y=height(Node->left);
    
    if(x>y)
        return x+1;
    else 
        return y+1;
        
    
    return 0;
}

template <typename DataType>int Tree<DataType>::leafNode() {
    int x=0,y=0;
    if(root==nullptr)
        return 0;
    x=leafNode(root->left);
    y=leafNode(root->right);
    
    if(root->left==nullptr&&root->right==nullptr)
        return x+y+1;
    else 
        return x+y;
}

template <typename DataType>int Tree<DataType>::leafNode(node<DataType> *Node) {
    int x=0,y=0;
    if(Node==nullptr)
        return 0;
    
    x=leafNode(Node->right);
    y=leafNode(Node->left);
    
    if(Node->left==nullptr&&Node->right==nullptr)
        return x+y+1;
    else 
        return x+y;
        
    
    return 0;
}




#endif