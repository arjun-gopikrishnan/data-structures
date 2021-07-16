#ifndef AVL_H
#define AVL_H
#include<iostream>
#include<queue>
#include <stack>
#include<string.h>
#include<string>

using namespace std;
template <typename DataType>
class AVL{
private:
    class Node {
        public:
            Node* lchild;
            DataType data;
            Node* rchild;
            int height;
    };
        Node* InPre(Node*);
        Node* InSucc(Node* p);
public:

    Node* root;
    Node* remove(Node*,DataType); 
    AVL(){ root = nullptr; }
 
    int NodeHeight(Node* p);
    int BalanceFactor(Node* p);
    Node* LLRotation(Node* p);
    Node* RRRotation(Node* p);
    Node* LRRotation(Node* p);
    Node* RLRotation(Node* p);
    Node* rInsert(Node* p, DataType key);
    void Inorder(Node* p);
    void Inorder(){ Inorder(root); }
    Node* getRoot(){ return root; }
    void remove(DataType);
};

template <typename DataType>
typename AVL<DataType>::Node* AVL<DataType>::InPre(Node *p) {
    while(p && p->rchild!=nullptr){
        p=p->rchild;
    }
    return p;
}
template <typename DataType>
typename AVL<DataType>::Node* AVL<DataType>::InSucc(Node *p) {
    while(p && p->lchild!=nullptr){
        p=p->lchild;
    }
    return p;
}


template <typename DataType> 
int AVL<DataType>::NodeHeight(Node *p) {
    int hl;
    int hr;
 
    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;
 
    return hl > hr ? hl + 1 : hr + 1;
}
template <typename DataType> 
int AVL<DataType>::BalanceFactor(Node *p) {
    int hl;
    int hr;
 
    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;
 
    return hl - hr;
}
template <typename DataType>
typename AVL<DataType>::Node* AVL<DataType>::LLRotation(Node *p) {
    Node* pl = p->lchild;
    Node* plr = pl->rchild;
 
    pl->rchild = p;
    p->lchild = plr;
 
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
 
    if (root == p){
        root = pl;
    }
    return pl;
}
template <typename DataType>
typename AVL<DataType>::Node* AVL<DataType>::RRRotation(Node *p) {
    Node* pr = p->rchild;
    Node* prl = pr->lchild;
 
    pr->lchild = p;
    p->rchild = prl;
 
    
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
 
    
    if (root == p){
        root = pr;
    }
    return pr;
}

template <typename DataType>
typename AVL<DataType>::Node* AVL<DataType>::LRRotation(Node *p) {
    Node* pl = p->lchild;
    Node* plr = pl->rchild;

    pl->rchild=plr->lchild;
    p->lchild=plr->rchild;

    plr->lchild  =pl;
    plr->rchild=p;

    pl->height=NodeHeight(pl);
    p->height=NodeHeight(p);
    plr->height=NodeHeight(plr);

    if(p==root)
        root=plr;
    return plr;
}

template <typename DataType>
typename AVL<DataType>::Node* AVL<DataType>::RLRotation(Node *p) {
    Node* pr = p->rchild;
    Node* prl = pr->lchild;

    pr->lchild = prl->rchild;
    p->rchild = prl->lchild;
 
    prl->rchild = pr;
    prl->lchild = p;

    pr->height=NodeHeight(pr);
    p->height=NodeHeight(p);
    prl->height=NodeHeight(prl);

    if(p==root)
        root=prl;


    return prl;
}

template <typename DataType>
typename AVL<DataType>::Node* AVL<DataType>::rInsert(Node *p, DataType key) {
    Node* t;
    if (p == nullptr){
        t = new Node;
        t->data = key;
        t->lchild = nullptr;
        t->rchild = nullptr;
        t->height = 1;  
        return t;
    }
 
    if (key < p->data){
        p->lchild = rInsert(p->lchild, key);
    } else if (key > p->data){
        p->rchild = rInsert(p->rchild, key);
    }
 
    
    p->height = NodeHeight(p);
 
    
    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1) {
        return LLRotation(p);
    } else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1){
        return LRRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1){
        return RRRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1){
        return RLRotation(p);
    }
 
    return p;
}

template <typename DataType>
void AVL<DataType>::Inorder(Node *p) {
    if (p){
        Inorder(p->lchild);
        cout << p->data << ", " << flush;
        Inorder(p->rchild);
    }
}

template <typename DataType>
typename AVL<DataType>::Node* AVL<DataType>::remove(Node *p, DataType key) {
if (p == nullptr){
        return nullptr;
    }
 
    if (p->lchild == nullptr && p->rchild == nullptr){
        if (p == root){
            root = nullptr;
        }
        delete p;
        return nullptr;
    }
 
    if (key < p->data){
        p->lchild = remove(p->lchild, key);
    } else if (key > p->data){
        p->rchild = remove(p->rchild, key);
    } else {
        Node* q;
        if (NodeHeight(p->lchild) > NodeHeight(p->rchild)){
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = remove(p->lchild, q->data);
        } else {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = remove(p->rchild, q->data);
        }
    }
 
    p->height = NodeHeight(p);
 
    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1) {  // L1 Rotation
        return LLRotation(p);
    } else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1){  // L-1 Rotation
        return LRRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1){  // R-1 Rotation
        return RRRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1){  // R1 Rotation
        return RLRotation(p);
    } else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 0){  // L0 Rotation
        return LLRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 0){  // R0 Rotation
        return RRRotation(p);
    }
 
    return p;
}

#endif