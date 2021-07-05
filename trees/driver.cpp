#include<iostream>
#include"./intbtr.h"

using namespace std;
void fuck(initializer_list <int> inputs){
    for(int i:inputs){
        cout<<i<<" ";
    }
}
int main(){
    IBtree *tree;
    cout<<"Driver is functional"<<endl;
   
    fuck({1,2,3,4,5});
}