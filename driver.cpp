#include<iostream>
#include<string>
#include"stack.h"
using namespace std;
int main(){
    Stack *newstack = new Stack();
    string input="((a+b)+(c+d)))";
    for(char s:input){
        if(s=='(')
            newstack->push(s);
        else if(s==')'){
            try{
                newstack->pop();
            }
            catch(const char* message){
                continue;
            }
        }
            
        
    }

    newstack->display();

}
