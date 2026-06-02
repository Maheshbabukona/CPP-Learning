/*
Two lists are given in reverse order. 
eg: 2->4->3 and 5->6->4 == we add each element and return their sum in nodes 7->0->8 
We sum each node --> sum = val1+val2+ carry and carry = sum/10 and next node val = sum%10
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
        node* newnode =  new node(val);
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
            temp=temp->next;
        }
        cout << "NULL";
    }
};

class Solution{
public:
    node* addtwonumbers(node* l1, node* l2){
        node dummy(0);
        node* tail = &dummy;
        int carry =0;
        while(l1 || l2 || carry){
            int sum = carry;
            if(l1){
                sum+=l1->data;
                l1 = l1->next;
            }
            if(l2){
                sum+=l2->data;
                l2 =l2->next;
            }

            carry = sum/10;
            tail->next = new node(sum%10);
            tail = tail->next;
        }
        return dummy.next;
    }
};

int main(){
    List l1;
    List l2;
    l1.push_back(2);
    l1.push_back(4);
    l1.push_back(3);

    l2.push_back(5);
    l2.push_back(6);
    l2.push_back(4);

    Solution S;
    node* result = S.addtwonumbers(l1.head,l2.head);
    l1.printLL(result);

}