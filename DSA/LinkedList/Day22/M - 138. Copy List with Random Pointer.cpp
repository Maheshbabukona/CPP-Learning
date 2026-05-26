/*
Goal is to create exact copy of the original list
But the list contains a random pointer which points to other nodes or null.. replicating this without copying addrress is the goal.

We use map<node*,node*> -- store respective addresses of old,new
 this way if there exists a random pointer we can find the respective new lists address by m[old->random]

*/

#include <iostream>
#include <unordered_map>
using namespace std;

class node{
public:
    int data;
    node* next;
    node* random;

    node(int val){
        data = val;
        next = random = NULL;
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

    node* getNodeAt(int idx){
        node* temp = head;
        int cnt=0;
        while(temp!=NULL && cnt<idx){
            temp = temp->next;
            cnt++;
        }
        return temp;
    }

    void printList(node* head){
        node* temp = head;
        while(temp!=NULL){
            cout << "Node->(" << temp->data << ")";
            
            if(temp->random!=NULL){
                cout << "random->(" << temp->random->data << ")";
            }
            else cout << "random->(NULL)";

            temp = temp->next;
        }
        cout << "---------------------------------\n";
    }
};

class Solution{
public:
    node* CopyRandomList(node* head){
        if(head == NULL) return NULL;

        unordered_map<node*,node*> m;

        node* newhead = new node(head->data);
        m[head] = newhead;
        node* oldtemp = head->next;
        node* newtemp = newhead;

        while(oldtemp!=NULL){
            node* copynode = new node(oldtemp->data);
            m[oldtemp]=copynode;
            newtemp->next = copynode;

            oldtemp = oldtemp->next;
            newtemp = newtemp->next;        
        }

        oldtemp = head;
        newtemp = newhead;
        while(oldtemp!=NULL){
            newtemp->random = oldtemp->random ? m[oldtemp->random] : NULL;
            oldtemp=oldtemp->next;
            newtemp=newtemp->next;
        }
        return newhead;
    }
};

int main() {
    // Build original list (same as LeetCode example)
    List ll;
    ll.push_back(7);
    ll.push_back(13);
    ll.push_back(11);
    ll.push_back(10);
    ll.push_back(1);

    // Set random pointers manually
    ll.getNodeAt(0)->random = NULL;                 // 7 -> NULL
    ll.getNodeAt(1)->random = ll.getNodeAt(0);      // 13 -> 7
    ll.getNodeAt(2)->random = ll.getNodeAt(4);      // 11 -> 1
    ll.getNodeAt(3)->random = ll.getNodeAt(2);      // 10 -> 11
    ll.getNodeAt(4)->random = ll.getNodeAt(0);      // 1 -> 7

    cout << "Original List:\n";
    ll.printList(ll.head);

    // Copy list
    Solution s;
    node* copiedHead = s.CopyRandomList(ll.head);

    cout << "Copied List:\n";
    ll.printList(copiedHead);

    return 0;
}