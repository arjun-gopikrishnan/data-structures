#ifndef BST_H
#define BST_H
#include<iostream>
#include<queue>
#include <stack>
#include<string.h>
#include<string>

using namespace std;

template <typename DataType>
class BST{
    private: 
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
        node *root;
        node *Rinsert(DataType key,node* curr){
            if(curr==nullptr){
                node *temp = new node();
                temp->data=key;
                temp->left=nullptr;
                temp->right=nullptr;
                return temp;
            }
            
            if(key<root->data)
                curr->left=Rinsert(key,curr->left);
            else if(key>curr->data)
                curr->right=Rinsert(key,curr->right);
            return curr;
        }    
        int height(node*);
        void inOrder(node*);
        node* InPre(node* p){
            while(p && p->right!=nullptr){
                p=p->right;
            }
            return p;
        }
        node* InSucc(node* p){
            while(p && p->left!=nullptr){
                p=p->left;
            }
            return p;
        }
    public:
        node* remove(node *p, DataType key) {
            node* q;
            if (p == nullptr){
                return nullptr;
            }
            if (p->left == nullptr && p->right == nullptr){
                if (p == root){
                    root = nullptr;
                }
                delete p;
                return nullptr;
            }
            if (key < p->data){
                p->left = remove(p->left, key);
            }else if (key > p->data){
                p->right = remove(p->right, key);
            }else {
                if (height(p->left) > height(p->right)){
                    q = InPre(p->left);
                    p->data = q->data;
                    p->left = remove(p->left, q->data);
                }else {
                    q = InSucc(p->right);
                    p->data = q->data;
                    p->right = remove(p->right, q->data);
                }
            }
            return p;
        }
        BST(){root=nullptr;}
        ~BST(){};
        node* getRoot(){
            return root;
        }
        void insert(DataType);
        void Rinsert(DataType);
        void displayInOrder(){
            inOrder(root);
        }
        int height();
        void remove(DataType);
        void genPreOrder(DataType[],int);
};

template <typename DataType>
void BST<DataType>::insert(DataType key){
    node *temp=root;
    node *rear,*current;

    if(root==nullptr){
        root = new node();
        root->data=key;
        root->left=nullptr;
        root->right=nullptr;
        return;
    }
    while(temp!=nullptr){
        rear=temp;
        if(key<temp->data){
            temp=temp->left;
        }else if(key>temp->data){
            temp=temp->right;
        }else{
            return;
        }
    }

    current = new node();
    current->data=key;
    current->left=nullptr;
    current->right=nullptr;

    if(key<rear->data)
        rear->left=current;
    else
        rear->right=current;
}

template <typename DataType>
void BST<DataType>::inOrder(node *rootNode) {
    if(rootNode == NULL)
        return;
    inOrder(rootNode->left);
    cout << rootNode->data << " ";
    inOrder(rootNode->right);
}

template <typename DataType>
void BST<DataType>::Rinsert(DataType key){
    if(root==nullptr){
        root = new node();
        root->data=key;
        root->left=nullptr;
        root->right=nullptr;
        return;
    }

    if(key<root->data)
        root->left=Rinsert(key,root->left);
    else if(key>root->data)
        root->right=Rinsert(key,root->right);
}

template <typename DataType>
int BST<DataType>::height() {
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

template <typename DataType>
int BST<DataType>::height(node *Node) {
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

template <typename DataType>
void BST<DataType>::genPreOrder(DataType *tree,int size){
    int i = 0;
    root = new node();
    root->data = tree[i++];
    root->left = nullptr;
    root->right = nullptr;
 
    // Iterative steps
    node* t;
    node* p = root;
    stack<node*> stk;
 
    while (i<size){
        if (tree[i]<p->data){
            t = new node();
            t->data = tree[i++];
            t->left = nullptr;
            t->right = nullptr;
            p->left = t;
            stk.push(p);
            p = t;
        } else {
            if (tree[i] > p->data && tree[i] < stk.empty() ? 32767 : stk.top()->data){
                t = new node();
                t->data = tree[i++];
                t->left = nullptr;
                t->right = nullptr;
                p->right = t;
                p = t;
            } else {
                p = stk.top();
                stk.pop();
            }
        }
    }
}

#endif