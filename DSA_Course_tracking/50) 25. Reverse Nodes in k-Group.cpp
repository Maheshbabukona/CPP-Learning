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
    void printlist(node* head){
        node* temp = head;
        while(temp!=NULL){
            cout << temp->data << "->";
            temp=temp->next;
        }
        cout << "NULL";
    }
};

// we are going to divide the problem into first group of k elements and the remaining list.

// we are going to call recursive function for the remaining function. and expect it to give the head of the completed reverse list.

// we then traverse the first kgroup left to right. and link to left of the prevnode(returned remaining list after recursion)

class Solution{
public:
    node* reverseKGroup(node* head, int k){
        node* temp = head;
        int cnt = 0;
        while(cnt<k){
            if(temp==NULL) return head;
            temp=temp->next;
            cnt++;
        } 

        // recursive call for remaining list
        node* prevnode = reverseKGroup(temp, k);

        // link the first k group to left of prevnode.

        temp=head, cnt=0;
        while(cnt<k){
            node* tempnext = temp->next;
            temp->next = prevnode;
            prevnode=temp;
            temp=tempnext;
            cnt++;
        }
        return prevnode;
    }
};

int main(){
    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);

    int k =2;
    Solution s;
    node* result = s.reverseKGroup(ll.head,k);

    ll.printlist(result);
}