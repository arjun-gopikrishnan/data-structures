#include "../stack.h"
#include<iostream>
#include<string>

void isBalanced(string);

int main(){

    string input_a="[(a+b)+{(c+d)*(e/f)}]";
    string input_b="[(a+b)+{(c+d)*(e/f)]}";
    
    isBalanced(input_a);
    isBalanced(input_b);
    
}

void isBalanced(string input){
    Stack *st = new Stack();
    
    for(char c:input){
        if(c=='('||c=='{'||c=='[')
            st->push(c);
        else if(c==')'){
            if(st->empty()||st->peek()!='('){
                cout<<"FALSE"<<endl;
                return;
            }
            else
                st->pop();

        }
        else if(c=='}'){
            if(st->empty()||st->peek()!='{'){
                cout<<"FALSE"<<endl;
                return;
            }
            else
                st->pop();
        }
        else if(c==']'){
            if(st->empty()||st->peek()!='['){
                cout<<"FALSE"<<endl;
                return;
            }
            else
                st->pop();
        }

    }
    st->display();
    if(st->empty()==0)
        cout<<"TRUE"<<endl;
    else
        cout<<"FALSE"<<endl;
}












// 1. You are given a string exp representing an expression.
// 2. You are required to check if the expression is balanced i.e. closing brackets and opening brackets match up well.

// e.g.
// [(a + b) + {(c + d) * (e / f)}] -> true
// [(a + b) + {(c + d) * (e / f)]} -> false
// [(a + b) + {(c + d) * (e / f)} -> false
// ([(a + b) + {(c + d) * (e / f)}] -> false