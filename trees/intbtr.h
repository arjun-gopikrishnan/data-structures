#ifndef ITREENODE_H
#define ITREENODE_H

class IntTreeNode{
    public:
    int data;
    IntTreeNode *rchild;
    IntTreeNode *lchild;
    IntTreeNode(){
        lchild=nullptr;
        rchild=nullptr;
    }

    IntTreeNode(int a, IntTreeNode *left = nullptr,IntTreeNode *right = nullptr){
        data=a;
        lchild=left;
        rchild=right;
    }

    ~IntTreeNode(){
        delete rchild;
        delete lchild;
    }
};

class IBtree{
    private:
        IntTreeNode *root;
    public:
        IBtree(){
            root=nullptr;
        }
        ~IBtree(){
            delete root;
        }
        
};

#endif