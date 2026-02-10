#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;

class Stack_vector{
public:
    vector<int> v;
    void push(int val){
        v.push_back(val);
    }
    void pop(){
        v.pop_back();
    }

    int top(){
        return v[v.size()-1];
    }
    bool empty(){
        return v.size()==0;
    }
};

class Stack_list{
public:
    list<int> ll;
    // head is considered top element
    void push(int val){
        ll.push_front(val); // with this new elements are added left.. and new element becomes top
    }

    void pop(){
        ll.pop_front(); // top element is deleted
    }
    int top(){
        return ll.front();
    }

    bool empty(){
        return ll.size()==0;
    }

};

int main(){
    Stack_vector vec_s;
    vec_s.push(1);
    vec_s.push(2);
    vec_s.push(3);
    vec_s.push(4);
    cout << "Using vector" << endl;
    while(!vec_s.empty()){
        cout << vec_s.top() << " ";
        vec_s.pop();
    }

    Stack_list list_s;
    list_s.push(10);
    list_s.push(20);
    list_s.push(30);
    list_s.push(40);
    cout << "\nUsing Linked List" << endl;
    while(!list_s.empty()){
        cout << list_s.top() << " ";
        list_s.pop();
    }

    stack<int> s;
    s.push(100);
    s.push(200);
    s.push(300);
    s.push(400);
    cout << "\nUsing STL stacks" << endl;
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }

}