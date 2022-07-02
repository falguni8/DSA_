#include<iostream>
#include<stack>
using namespace std;


void insertatbottom(stack <int>&s,int element){
    if(s.empty()){
        s.push(element);
        return ;
    }
    int k=s.top();
    s.pop();
    insertatbottom(s,element);
    s.push(k);
}
void reversestack(stack <int> &s){
    if(s.empty()){
        return ;
    }
    int ele=s.top();
    s.pop();
    reversestack(s);
    insertatbottom(s,ele);
}

int main(){
    stack<int>s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    reversestack(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}