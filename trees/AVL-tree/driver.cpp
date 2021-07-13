#include <iostream>
#include "./AVL.h"
using namespace std;
 
int main() {
 
    AVL<int> tll;
    AVL<int> trr;
    AVL<int> tlr;
    AVL<int> trl;

    tll.root = tll.rInsert(tll.root, 30);
    tll.root = tll.rInsert(tll.root, 20);
    tll.root = tll.rInsert(tll.root, 10);
    tll.root = tll.rInsert(tll.root, 45);
    tll.root = tll.rInsert(tll.root, 57);
    tll.root = tll.rInsert(tll.root, 21);
    tll.root = tll.rInsert(tll.root, 17);
 
    tll.Inorder();
    cout << endl;
 
    trr.root = trr.rInsert(trr.root, 10);
    trr.root = trr.rInsert(trr.root, 20);
    trr.root = trr.rInsert(trr.root, 30);
 
    trr.Inorder();
    cout << endl;

    tlr.root = tlr.rInsert(tlr.root, 50);
    tlr.root = tlr.rInsert(tlr.root, 10);
    tlr.root = tlr.rInsert(tlr.root, 20);
 
    tlr.Inorder();
    cout << endl;

    trl.root = trl.rInsert(trl.root, 20);
    trl.root = trl.rInsert(trl.root, 50);
    trl.root = trl.rInsert(trl.root, 30);
 
    trl.Inorder();
    cout << endl;
 
    return 0;
}