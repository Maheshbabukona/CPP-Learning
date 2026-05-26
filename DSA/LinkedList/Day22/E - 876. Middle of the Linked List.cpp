/*
Finding the middle node -- use slow and fast pointer - by the time fast pointer reaches the end - slow pointer is at the middle
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
};

class Solution{
public:
    node* middleNode(node* head){
        node* slow = head;
        node* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

int main(){
    List LL;
    LL.push_back(1);
    LL.push_back(2);
    LL.push_back(3);
    LL.push_back(4);
    LL.push_back(5);
    LL.push_back(6);

    Solution S;
    node* result = S.middleNode(LL.head);
    cout << result->data;
}