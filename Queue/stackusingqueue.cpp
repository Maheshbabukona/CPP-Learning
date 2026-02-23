/*
to maintain the order of stack.. as soon as push is called. 
we move all the elements to q2(helper) and push the new element to empty q1. and then push them back from q2 -> q1
*/
#include <iostream>
#include <queue>
using namespace std;

class Mystack{
public:
    queue<int> q1; // main
    queue<int> q2; // helper

    Mystack(){

    }

    void push(int x){
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop(){
        int ans = q1.front();
        q1.pop();
        return ans;
    }

    int front(){
        return q1.front();
    }

    bool isempty(){
        return q1.empty();
    }
};

int main(){
    Mystack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.pop()<<endl;
    cout << s.front()<<endl;
    cout << s.isempty();
}