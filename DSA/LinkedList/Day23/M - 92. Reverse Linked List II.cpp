/*
Reversing a portion of elements in the linked list
given 1->2->3->4->5 left=2, right =4 ==> the portion is 1->|2->3->4|->5 to be reversed the output = 1->4->3->2->5
How do you do that?

Have a dummy node created and point its next to head  Node dummy(0) -- dummy.next = head
Create a beforeleft node point to the address of dummy. node* beforeleft = &dummy
Now move the before left - as per given left 
Now the nextnode of before left becomes the cur -- from which reversal needs to happen -- store this in leftnode so as to point its next to cur -- at the last
Now for the range of right-left+1 --- reverse the elements -- and finally beforeleft->next = prev and leftnode->next = cur

return dummy.next == which would have been changed.
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
    node* ReverseBetween(node* head, int left,int right){
        node dummy(0);
        dummy.next = head;
        node* beforeleft = &dummy;

        for(int i=1;i<left;i++){
            beforeleft=beforeleft->next;
        }

        node* cur = beforeleft->next;
        node* leftnode = cur;
        node* prev = NULL;
        node* next = NULL;

        int k = right - left +1;
        while(k--){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        beforeleft->next = prev;
        leftnode ->next = cur;

        return dummy.next;
    }
};

int main(){
    List L1;
    L1.push_back(1);
    L1.push_back(2);
    L1.push_back(3);
    L1.push_back(4);
    L1.push_back(5);
    int left =2 , right =4;

    Solution S;
    node* result = S.ReverseBetween(L1.head,left,right);
    L1.printLL(result);
}