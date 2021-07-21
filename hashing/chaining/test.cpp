#include<iostream>
#include"./linkedList.h"
using namespace std;

int hashAddress(int);
bool search(int,LinkedList<int>[]);
void insert(int,LinkedList<int>[]);

int main(){
    LinkedList<int> hashTable[10];
    int arr[] = {0,1,3,4,5,6,7,8,9,10,11,23,54,33,78,91,23,56,76};
    
    for(int i:arr){
        insert(i,hashTable);
    }

    // for(int i=0;i<10;i++){
    //     hashTable[i].display();
    //     cout<<endl;
    // }

    for(int i=1;i<15;i++)
       search(i,hashTable)?cout<<i<<" Is Present\n":cout<<i<<" Is Absent\n";
}

bool search(int key,LinkedList<int> H[10]){
    return H[hashAddress(key)].search(key);
}

int hashAddress(int key){
    return key%10;
}

void insert(int key,LinkedList<int> H[10]){
    H[hashAddress(key)].SortedInsert(key);
}
