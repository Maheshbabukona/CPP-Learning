#include <iostream>
using namespace std;

class node{
public:
    int data;
    node* next;
    node* prev;
    node* child;

    node(int val){
        data = val;
        next = prev = child = NULL;
    }
};

class multilevellist{
public:
    node* head;

    multilevellist(){
        head = NULL;
    }

    // build the famous LeetCode example
    void buildExample(){
        node* n1 = new node(1);
        node* n2 = new node(2);
        node* n3 = new node(3);
        node* n4 = new node(4);
        node* n5 = new node(5);
        node* n6 = new node(6);

        n1->next=n2; n2->prev=n1;
        n2->next=n3; n3->prev=n2;
        n3->next=n4; n4->prev=n3;
        n4->next=n5; n5->prev=n4;
        n5->next=n6; n6->prev=n5;

        node* n7 = new node(7);
        node* n8 = new node(8);
        node* n9 = new node(9);
        node* n10 = new node(10);

        n7->next=n8; n8->prev=n7;
        n8->next=n9; n9->prev=n8;
        n9->next=n10; n10->prev=n9;

        n3->child = n7;

        node* n11 = new node(11);
        node* n12 = new node(12);

        n11->next=n12; n12->prev=n11;

        n8->child = n11;

        head = n1;
    }

    // print only next pointers (used after flatten)
    void printList(node* head){
        node* temp = head;
        while(temp){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class Solution{
public:
    node* flatten(node* head){
        if(head==NULL) return head;

        node* cur= head;
        while(cur!=NULL){
            if(cur->child!=NULL){
                node* tempnext = cur->next; // store the cur->next in temp to link it after linking child branch
                cur->next = flatten(cur->child); // recursive call to get the flatten list of child branch
                cur->next->prev = cur;
                cur->child = NULL; // as child branch is flattened.. its changed to NULL

                // right now cur is pointing to node where child was present.. now the child branch is flattened .. we traverse the
                // flattened child branch and go till last element to link with tempnext

                while(cur->next!=NULL){
                    cur=cur->next;
                }

                if(tempnext!=NULL){
                    cur->next = tempnext;
                    tempnext->prev= cur;
                }
            }
            cur=cur->next;
        }
        return head;
    }
};

int main(){
    multilevellist ml;
    ml.buildExample();
    Solution s;

    node* flatHead = s.flatten(ml.head);
    cout << "After flatten:\n";
    ml.printList(flatHead);

    return 0;
}
