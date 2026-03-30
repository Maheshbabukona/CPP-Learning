#include <iostream>
using namespace std;

class node{
public:
    int data;
    node* next;

    node(int val){
        data = val;
        next=NULL;
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
            head=tail=newnode;
            return;
        }
        tail->next = newnode;
        tail = newnode;
    }

    void printlist(node* head){
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
    node* swapPairs(node* head){
        if(head==NULL || head->next==NULL) return head;

        node* first =head;
        node* sec = head->next;
        node* prev = NULL;

        while(first!=NULL && sec!=NULL){
            node* third = sec->next;

            sec->next = first;
            first->next = third;
            if(prev!=NULL) prev->next = sec;
            else head = sec;

            // Go to next group 
            prev = first;
            first = third;
            if(third!=NULL){
                sec = third->next;
            }
            else sec = NULL;
        }
        return head;
    }
};

int main(){
    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    Solution s;
    node* result = s.swapPairs(ll.head);
    ll.printlist(result);

}