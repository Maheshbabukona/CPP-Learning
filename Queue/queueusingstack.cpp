/*
to maintain the order of queueu.. as soon as push is called. 
we move all the elements to s2(helper) and push the new element to empty s1. and then push them back from s2 -> s1
*/

#include <iostream>
#include <stack>
using namespace std;

class Myqueue{
public:
    stack<int> s1;
    stack<int> s2;

    Myqueue(){

    }
    void push(int x){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop(){
        int ans = s1.top();
        s1.pop();
        return ans;
    }

    int peek(){
        return s1.top();
    }

    bool isempty(){
        return s1.empty();
    }
};

int main(){
    Myqueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.pop() << endl;
    cout << q.peek()<<endl;
    cout << q.isempty();
}