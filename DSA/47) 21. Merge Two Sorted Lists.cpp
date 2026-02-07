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
        head=tail=NULL;
    }

    void push_back(int val){
        node* newnode = new node(val);
        if(head==NULL){
            head = tail = newnode;
        }
        node* temp = tail;
        temp->next = newnode;
        tail = newnode;
    }

    void printlist(node* head){ // modified printlist to take the result head and print too
        node* temp = head;
        while(temp!=NULL){
            cout << temp->data << "->";
            temp= temp->next;
        }
        cout << "NULL";
    }
};

/*
we consider the smallest of both the heads as result head.. and pass the remaining lists and expect the next smallest head which we point to .
*/
class Solution{
public:
    node* mergetwolists(node* head1, node* head2){
        if(head1==NULL || head2==NULL) return head1==NULL ? head2 : head1;
        if(head1->data<=head2->data){
            head1->next = mergetwolists(head1->next,head2);
            return head1;
        }
        else{
            head2->next = mergetwolists(head1,head2->next);
            return head2;
        }
    }
};

int main(){
    List ll1;
    List ll2;
    ll1.push_back(1);
    ll1.push_back(2);
    ll1.push_back(4);

    ll2.push_back(1);
    ll2.push_back(3);
    ll2.push_back(4);

    cout << "Before sorting\n" << "L1: ";
    ll1.printlist(ll1.head);
    cout << " and L2: ";
    ll2.printlist(ll2.head);
    
    Solution s;

    node* result = s.mergetwolists(ll1.head, ll2.head);
    cout << "\nAfter Sorting\nResult: ";
    ll1.printlist(result);
}