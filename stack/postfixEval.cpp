#include<iostream>
#include<string>
#include"stack.h"
#include"intStack.h"
#include <string.h>
#include"postfix.h"
#include<math.h>
using namespace std;

int Eval(char*);

int main(){
    char infix[] = "6-5+8^3";
    char *postfix=convert(infix);
    cout<<postfix<<endl;
    int result = Eval(postfix);
    cout<<result<<endl;
}

int Eval(char *postfix){
    intStack *st = new intStack();
    int i,x,y,r;
    for(i=0;postfix[i]!='\0';i++){
        if(isOperand(postfix[i])){
            st->push(postfix[i]-'0');
        }else{
            y=st->pop();
            x=st->pop();
            switch(postfix[i]){
                case '+':
                    r=x+y;
                    break;
                case '-':
                    r=x-y;
                    break;
                case '*':
                    r=x*y;
                    break;
                case '/':
                    r=x/y;
                    break;
                case '^':
                    r=pow(x,y);
                    break;
            }st->push(r);
        }
    }
    cout<<"\nSize is "<<sizeof(*st)<<endl;
    return st->pop();
}