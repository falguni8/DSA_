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
int prefix(string s){
    stack <int> stk;
    for(int i=s.length();i>=0;i--){
        if(isdigit(s[i])){
            stk.push(s[i]-'0');
        }
        else if(isoperator(s[i])){
            int a=stk.top();
            stk.pop();
            int b=stk.top();
            stk.pop();
            int c=calculate(a,b,s[i]);
            stk.push(c);
        }
    }
    return stk.top();
}

int main(){
    string s;
    cin>>s;
    cout<<prefix(s);
    return 0;
}