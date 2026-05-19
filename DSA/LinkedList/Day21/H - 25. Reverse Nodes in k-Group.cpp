/*
The same reverse logic -- but we reverse nodes in the same group -- we start with next element after k - leaving out the first group -- we pass in recursion --

each recursion - returns a prevnode for the before group - this prevnode becomes the nextnode for the prior group.

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
        node* newnode = new node(val);
        if(head == NULL){
            head = tail = newnode;
            return;
        }
        tail->next = newnode;
        tail = newnode;
    }

    void printLL(node* head){
        node* temp = head;
        while(temp!=NULL){
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL";
    }
};

class Solution{
public:
    node* reverseKGroup(node* head, int k){
        node* temp = head;
        int cnt =0;
        while(cnt<k){
            if(temp==NULL) return head;
            temp=temp->next;
            cnt++;
        }
        node* prevnode = reverseKGroup(temp,k);
        temp = head, cnt =0;
        while(cnt<k){
            node* tempnext = temp->next;
            temp->next = prevnode;
            prevnode = temp;
            temp = tempnext;
            cnt++;
        }
        return prevnode;
    }
};

int main(){
    LinkedList ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);

    int k =2;
    Solution s;
    node* result = s.reverseKGroup(ll.head,k);

    ll.printLL(result);
}