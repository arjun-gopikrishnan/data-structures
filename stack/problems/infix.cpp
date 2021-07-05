#include "../stack.h"
#include "../intStack.h"
#include<iostream>
#include<string>
using namespace std;

bool isOperand(char);
string solution(string);
int precedence(char);
int operation(int a,int b,char x);

int main(){
    string input="2+6*4/8-3";
    try{
        string output=solution(input);
        cout<<output;
    }catch(const char* message){
        cout<<message;
    }
   
}

string solution(string input){
    Stack *operators = new Stack();
    intStack *operands = new intStack();

    //cout<<input<<endl;

    for(char c:input){
        if(c=='('){
            //cout<<" CASE 1\n";
            operators->push(c);
        }else if(c==')'){
            //cout<<" CASE 2\n";
            while(operators->peek()!='('){
                char op = operators->pop();
                int b = operands->pop();
                int a = operands->pop();
                operands->push(operation(a,b,op));
                // cout<<operands->peek()<<endl;
            }operators->pop();
            
        }else if(isOperand(c)){
            //cout<<" CASE 3\n";
            operands->push(c-'0');
            // cout<<operands->peek()<<endl;
        }else{
            //cout<<" CASE 4\n";
            if(operators->empty()){
                operators->push(c);
            }else{
                while(!operators->empty()||operators->peek()=='('||precedence(c)<=precedence(operators->peek())){
                cout<<" CASE 4\n";
                char op = operators->pop();
                int b = operands->pop();
                int a = operands->pop();
                operands->push(operation(a,b,op));
                // cout<<operands->peek()<<endl;
            }operators->pop();
            }
        }
    }
    while(!operators->empty()){
        char op = operators->pop();
        int b = operands->pop();
        int a = operands->pop();
        operands->push(operation(a,b,op));
        // cout<<operands->peek()<<endl;
    }
    
    return "";
}

int precedence(char x){
    if (x == '+' || x == '-'){
        return 1;
    } else if (x == '*' || x == '/'){
        return 2;
    }
    return 2;
}

bool isOperand(char c){
    return (c=='('||c==')'||c=='+'||c=='-'||c=='*'||c=='/')?false: true;
}

int operation(int a,int b,char x){
    switch(x){
        case '+': return a+b;
        break;
        case '-': return a-b;
        break;
        case '*': return a*b;
        break;
        case '/': return a-b;
        break;
        default: throw "Invalid operator";
        break;
    }
}