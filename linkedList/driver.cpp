#include<iostream>
#include<string>
#include"./stack/stack.h"
#include <string.h>
using namespace std;

int isOperand(char x){
    if (x == '+' || x == '-' || x == '*' || x == '/' ||
        x == '^' || x == '(' || x == ')'){
        return 0;
    }
    return 1;
}
 
int outPrecedence(char x){
    if (x == '+' || x == '-'){
        return 1;
    } else if (x == '*' || x == '/'){
        return 3;
    } else if (x == '^'){
        return 6;
    } else if (x == '('){
        return 7;
    } else if (x == ')'){
        return 0;
    }
    return -1;
}
 
int inPrecedence(char x){
    if (x == '+' || x == '-'){
        return 2;
    } else if (x == '*' || x == '/'){
        return 4;
    } else if (x == '^'){
        return 5;
    } else if (x == '('){
        return 0;
    }
    return -1;
}
 
char* convert(char* infix){
    char* postfix = new char [strlen(infix) + 1];
 
    Stack *stk = new Stack();
 
    int i = 0;
    int j = 0;
 
    while (infix[i] != '\0'){
        if (isOperand(infix[i])){
            postfix[j++] = infix[i++];
        } else {
            if (stk->empty() || outPrecedence(infix[i]) > inPrecedence(stk->peek())){
                stk->push(infix[i++]);
            } else if (outPrecedence(infix[i]) == inPrecedence(stk->peek())){
                stk->pop();
            }
            else {
                postfix[j++] = stk->peek();
                stk->pop();
            }
        }
    }
 
    while (! stk->empty() && stk->peek() != ')'){
        postfix[j++] = stk->peek();
        stk->pop();
    }
 
    postfix[j] = '\0';
 
    return postfix;
 
}


int main(){
    char infix[] = "((a+b)*c)-d^e^f";
    cout << convert(infix) << endl;
}
