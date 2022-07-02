#include<iostream>
#include<stack>
#include<math.h>
using namespace std;

bool isoperator(char c){
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^'){
        return true;
    }
    return false;
}

int calculate(int a,int b,char c){
    if(c=='+'){
        return a+b;
    }
    if(c=='-'){
        return a-b;
    }
    if(c=='*'){
        return a*b;
    }
    if(c=='/'){
    return a/b;
    }
    return a^b;
}
int postfix(string s){
    stack <int> stk;
    for(int i=0;i<s.length();i++){
        if(isdigit(s[i])){
            stk.push(s[i]-'0');
        }
        else if(isoperator(s[i])){
            int a=stk.top();
            stk.pop();
            int b=stk.top();
            stk.pop();
            int c=calculate(b,a,s[i]);
            stk.push(c);
        }
    }
    return stk.top();
}

int main(){
    string s;
    cin>>s;
    cout<<postfix(s);
    return 0;
}