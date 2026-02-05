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

    void createcycle(int pos){ // just to create the cycle as per problem statement
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

// here we use slow fast approach
/*
 Why the distance between slow fast increases by 1 on each iteration it reaches one point
 where the distance is equal to the distance of the cycle.. where slow and fast meet.
*/
class Solution{
public:
    bool iscycle(node* head){
        node* slow = head;
        node* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return true;
        }
        return false;
    }
};

int main(){
    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);

    // lets create a cycle at index 2;
    ll.createcycle(2);

    Solution s;
    cout << s.iscycle(ll.head);
}

