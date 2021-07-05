#ifndef TREE_H
#define TREE_H
#include<iostream>

template <typename DataType>
class TreeNode{
    public:
    DataType data;
    TreeNode *rchild;
    TreeNode *lchild;
    TreeNode(){
        lchild=nullptr;
        rchild=nullptr;
    }

    TreeNode(DataType d, TreeNode *left = nullptr,TreeNode *right = nullptr){
        data=d;
        lchild=left;
        rchild=right;
    }

    ~TreeNode(){
        delete rchild;
        delete lchild;
    }
};
template <typename DataType>
class Tree{
    private:
        TreeNode<DataType> *root;
    public:
        Tree(){
            root=nullptr;
        }
        Tree(std::initializer_list <DataType>);
        ~Tree(){
            delete root;
        }
};

#endif