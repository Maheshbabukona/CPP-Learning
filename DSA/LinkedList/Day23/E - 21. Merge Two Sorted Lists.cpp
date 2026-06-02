/*
lets say there are 2 lists 
1->3->5
2->4->6

We compare 1,3 take 1 first and then the remaining list becomes 3->5 && 2->4->6.

Same exact problem again. Therefore we use recursion to find the smallest next at each recursion.

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

    void printll(node* head){
        if(head==NULL) return;
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
    node* mergeTwoLists(node* head1, node* head2){
        if(head1==NULL || head2==NULL) return head1==NULL ? head2 : head2;

        if(head1->data <= head2->data){
            head1->next = mergeTwoLists(head1->next,head2);
            return head1;
        }
        else{
            head2->next = mergeTwoLists(head1, head2->next);
            return head2;
        }
    }
};

int main(){
    List ll1;
    List ll2;
    ll1.push_back(1);
    ll1.push_back(3);
    ll1.push_back(5);

    ll2.push_back(2);
    ll2.push_back(4);
    ll2.push_back(6);

    Solution S;
    node* result = S.mergeTwoLists(ll1.head, ll2.head);
    cout << "After merging:\n";
    ll1.printll(result);

}