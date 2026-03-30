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

class List{ // not necessary.. but just to create the linked list
public:
    node* head;
    node* tail;

    List(){
        head = tail = NULL;
    }

    void push_back(int val){\
        node* newnode = new node(val);
        if(head==NULL){
            head = tail = newnode;
            return;
        }
        tail->next = newnode;
        tail = newnode;
    }
    void printlist(){
        node* temp = head;
        while(temp!=NULL){
            cout << temp->data << "->";
            temp=temp->next;
        }
        cout << "NULL";
    }
};

// slow fast approach -> slow= slow+1, fast=fast+2 -> at the end slow is at the middle

class Solution{
public:
    node* middlenode(node* head){
        node* slow = head;
        node* fast = head;

        while(fast!=NULL && fast->next!=NULL){ // why both -> at the end we update fast=fast->next->next = null.. so null->next throws error
            slow = slow->next;
            fast= fast->next->next;
        }

        return slow;
    }
};

int main(){
    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.push_back(6);

    Solution s;

    node* result = s.middlenode(ll.head);
    cout << result->data << endl;
}