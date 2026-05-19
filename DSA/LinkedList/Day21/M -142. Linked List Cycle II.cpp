/*
Cycle detection --

can be done using slow,fast pointer approach.
Slow pointer moves 1 step a time, fastpointer moves 2 steps a time. 

if the cycle exists they both meet at one point.
By the time they reach, fast pointer has already completed a loop.. so the distance between start->loop == meetingpoint->loop.
Therefore place the slow at start and fast at meeting point -- move one a time -- when the reach thats the loop.
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

class LinkedList{
public:
    node* head;
    node* tail;

    LinkedList(){
        head = tail = NULL;
    }
    void push_back(int val){
        node* newnode =  new node(val);
        if(head == NULL){
            head = tail = newnode;
            return;
        }
        tail->next = newnode;
        tail = newnode;
    }

    void printll(node* head){
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

class Solution{
public:
    node* detectCycle(node* head){
        node* slow = head;
        node* fast = head;
        bool iscycle = false;

        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow==fast){
                iscycle = true;
                break;
            }
        }
        if(!iscycle) return NULL;
        slow = head;
        while(slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

int main(){
    LinkedList ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);

    // lets create a cycle at index 2;
    ll.createcycle(2);

    Solution s;
    node* result = s.detectCycle(ll.head);
    cout << result->data;
}