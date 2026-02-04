/*
Gaol → to reverse the links in the linked list
eg: given 1→2→3→NULL output = 3→2→1→NULL

So we have 3 pointers current, prev and next
in a loop..  initially cur =head, prev=next = null

next = cur→next // save the next nodes address
cur→next = prev // point the curs next to prev

prev = cur // move the prev
cur = next // move the cur

*/

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

class Solution{
public:
    node* reverseList(node* head){
        node* cur = head;
        node* prev = NULL;
        node* next = NULL;
        while(cur!=NULL){
            next = cur->next;
            cur->next = prev;

            prev =cur;
            cur = next;
        }
        return prev;
    }
};

int main(){
    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);

    Solution s;
    node* oldhead = ll.head;
    ll.head = s.reverseList(ll.head);
    ll.tail = oldhead;
    ll.printlist();
}