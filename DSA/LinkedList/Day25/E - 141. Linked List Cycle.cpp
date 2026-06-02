/*
Slow fast pointer approach
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

class List{
public:
    node* head;
    node* tail;

    List(){
        head = tail = NULL;
    }

    void push_back(int val){
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

    void createcycle(int pos){
        if(pos<0) return; // leetcode uses -1 for no cycle

        node* temp = head;
        node* cyclenode = NULL;
        int index = 0;

        while(temp!=NULL){
            if(index==pos) cyclenode = temp; // find the pos where cycle is required and point the cyclenode to that

            if(temp->next==NULL){
                temp->next = cyclenode; // point the last node to cycle node.
                return;
            }
            temp=temp->next;
            index++;
        }
    }

};

class Solution{
public:
    bool hasCycle(node* head){
        if(head==NULL) return false;

        node* slow = head;
        node* fast = head;

        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast=fast->next->next;

            if(slow==fast) return true;
        }
        return false;
    }
};

int main(){
    List l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);

    // l.printlist();

    l.createcycle(2);

    Solution s;
    cout << s.hasCycle(l.head) << endl;
}