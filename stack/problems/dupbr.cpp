#include "../stack.h"
#include<iostream>
#include<string>

int isBalanced(string);

int main(){
    string input;
    cin>>input;
    
    if(isBalanced(input))
        cout<<"false";
    else
        cout<<"true";
    
}

int isBalanced(string input){
    Stack *st = new Stack();
    
    for(char c:input){
        st->push(c);
        if(st->peek()==')'){
            while(st->peek()!='('){
                st->pop();
            }st->pop();
        }
    }

    return st->empty();
}












// 1. You are given a string exp representing an expression.
// 2. Assume that the expression is balanced  i.e. the opening and closing brackets match with each other.
// 3. But, some of the pair of brackets maybe extra/needless. 
// 4. You are required to print true if you detect extra brackets and false otherwise.

// e.g.'
// ((a + b) + (c + d)) -> false
// (a + b) + ((c + d)) -> true