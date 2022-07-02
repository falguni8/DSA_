#include <iostream>
#include <stack>
using namespace std;

class queue{

    stack<int> s1;

    public:

    void push(int x){
        s1.push(x);
    }

   int pop(){

        if (s1.empty()){
            cout<<"NO ELEMENTS:(";
            return -1;
        }
        int x=s1.top();
        s1.pop();
        if(s1.empty()){
            return x;
        }
        int k=pop();
        s1.push(x);
        return k;
    }

    bool empty(){
        if(s1.empty()){
            return true;
        }
        return false;
    }
};

int main()
{

    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    while(!q.empty()){
        cout<<q.pop()<<endl;
    }
    
        return 0;
}