/*
ANy node can have child and the list on child -- somwhere can have child -- this makes it multilevel.. 

So goal is to flatten it. 

If a node is having a child -- save its next node in temp. Then connect the child node as its next -- pass on all the nodes of child -- connect the temp next to connected last.
*/

#include <iostream>
using namespace std;

class node{
public:
    int data;
    node* next;
    node* prev;
    node* child;

    node(int val){
        data= val;
        next = prev = child = NULL;
    }
};

class MultilevelList{
public:
    node* head;
    
    MultilevelList(){
        head = NULL;
    }

    void buildExample(){
        node* n1 = new node(1);
        node* n2 = new node(2);
        node* n3 = new node(3);
        node* n4 = new node(4);
        node* n5 = new node(5);
        node* n6 = new node(6);

        n1->next = n2; n2->prev = n1;
        n2->next = n3; n3->prev = n2;
        n3->next = n4; n4->prev = n3;
        n4->next = n5; n5->prev = n4;
        n5->next = n6; n6->prev = n5;

        node* n7 = new node(7);
        node* n8 = new node(8);
        node* n9 = new node(9);
        node* n10 = new node(10);
        node* n11 = new node(11);
        node* n12 = new node(12);

        n3->child = n7;
        n7->next = n8; n8->prev = n7;
        n8->next = n9; n9->prev = n8;
        n9->next = n10; n10->prev = n9;
        n8->child = n11;
        n11->next = n12; n12->prev = n11;

        head = n1;
    }

    void printflatten(node* head){
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
    node* flatten(node* head){
        if(head==NULL) return head;
        node* cur = head;
        while(cur!=NULL){
            if(cur->child!=NULL){
                node* tempnext = cur->next;
                cur->next = flatten(cur->child);
                cur->next->prev = cur;
                cur->child=NULL; 

                while(cur->next!=NULL){
                cur=cur->next;
                }
                if(tempnext!=NULL){
                    cur->next = tempnext;
                    tempnext->prev = cur;
                }
            }
            cur=cur->next;  
        }
        return head;
    }
};

int main(){
    MultilevelList ml;
    ml.buildExample();
    Solution s;

    node* flatHead = s.flatten(ml.head);
    cout << "After flatten:\n";
    ml.printflatten(flatHead);

    return 0;
}