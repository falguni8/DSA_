#include<iostream>
#include<queue>
using namespace std;

class stack{

    queue<int> q;

    public:

    void push(int x){

        q.push(x);
    }
    void pop(){
        if(q.empty()){
            //cout<<"EMPTY\n";
            return;
        }
        queue<int>temp;
        while(q.size()!=1){
            temp.push(q.front());
            q.pop();
        }
        //cout<<q.front()<<"\n";
        q.pop();
        swap(q,temp);
    }

    int peek(){
        if(q.empty()){
            //cout<<"EMPTY\n";
            return -1;
        }
        queue<int>temp;
        while(q.size()!=1){
            temp.push(q.front());
            q.pop();
        }
        int x=q.front();
        q.pop();
        temp.push(x);
        swap(q,temp);
        return x;
    }

    bool empty(){
        return q.empty();
    }

};

int main(){


    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    while(!st.empty()){
        cout<<st.peek()<<endl;
        st.pop();
    }

    return 0;
}