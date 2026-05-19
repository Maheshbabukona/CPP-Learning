/*
Goal:
given - 1->2->3->4->NULL
result - NULL<-1<-2<-3<-4 

For this we use 3 points cur, next, prev. 

Track the cur node using cur, next node using next before removing the connection and prev node to connect the curent with.

mark the next node before removing the connection using next, point the cur->next to prev and then move the prev to cur and cur to next.. likewise remove forward connections and creation backward. which reverses

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
    node* reverseLL(node* head){
        node* cur = head;
        node* next = NULL;
        node* prev = NULL;

        while(cur!=NULL){
            next = cur->next;
            cur->next = prev;

            prev = cur;
            cur=next;
        }

        return prev;
    }
};

int main(){
    LinkedList LL;
    LL.push_back(1);
    LL.push_back(2);
    LL.push_back(3);
    LL.push_back(4);
    LL.push_back(5);

    cout << "Before: ";
    LL.printLL(LL.head);
    
    Solution S;
    node* oldhead = LL.head;
    LL.head = S.reverseLL(oldhead);
    LL.tail = oldhead;
    cout << "\nAfter: ";
    LL.printLL(LL.head);
}