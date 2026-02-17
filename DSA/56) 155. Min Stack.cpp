#include <iostream>
#include <stack>
using namespace std;

class Minstack{     
public:
    stack<pair<int,int>> st1;
    
    Minstack(){

    }

    void push(int val){
        if(st1.empty()){
            st1.push({val,val});
        }
        else{
            int minval = min(val, st1.top().second);
            st1.push({val,minval});
        }

    }
    void pop(){
        st1.pop();
    }

    int top(){
        return st1.top().first;
    }
    int getMin(){
        return st1.top().second;
    }
};

int main() {
    Minstack minStack;

    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);

    cout << minStack.getMin() << endl;
    minStack.pop();
    cout << minStack.top() << endl;
    cout << minStack.getMin() << endl;
}

