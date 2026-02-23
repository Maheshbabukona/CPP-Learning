// implement queue using Linked List.

#include <iostream>
using namespace std;

class node{
public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};

class queue{
public:
    node* head;
    node* tail;

    queue(){
        head = tail = NULL;
    }

    bool isempty(){
        if (head==NULL){
            return true;
        }
        return false;
    }
    void push(int val){ // push_back of linkedlist 
        node* newnode = new node(val);

        if(isempty()){
            head = tail = newnode;
            return;
        }
        tail->next = newnode;
        tail = newnode;
    }

    void pop(){ // pop front linkedlist.
        if(isempty()){
            cout << "Queue is empty\n"<<endl;
            return;
        }
        node* temp = head;
        head = head->next;
        delete temp;
    }

    int front(){
        if(head==NULL) return -1;
        return head->data;
    }
};

int main(){
    queue qu;
    qu.push(1);
    qu.push(2);
    qu.push(3);
    qu.push(4);
    qu.pop();
    qu.pop();
    cout << qu.front()<< endl;
    cout << qu.isempty()<< endl;
    qu.pop();
    qu.pop();
    cout << qu.isempty();
}