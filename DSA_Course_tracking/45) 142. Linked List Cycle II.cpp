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
    void printlist(){
        node* temp = head;
        while(temp!=NULL){
            cout << temp->data << "->";
            temp=temp->next;
        }
        cout << "NULL";
    }

    void createcycle(int pos){ // just to create the cycle as per problem statement
        if(pos<0) return; // leetcode uses -1 for no cycle

        node* temp = head;
        node* cyclenode = NULL;
        int index = 0;

        while(temp!=NULL){
            if(index==pos) cyclenode = temp; // find the pos where cycle is required and point the cyclenode to that

            if(temp->next==NULL){
                temp->next = cyclenode; // point the last node to cycle node.
                return;
            }
            temp=temp->next;
            index++;
        }
    }
};

class Solution{
public:
    node* detectcycle(node* head){
        node* slow = head;
        node* fast = head;
        bool iscycle = false;
        // we find the point where they both meet.
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast = fast->next->next;
            if(slow==fast){
                iscycle =true;
                break; 
            }
        }
        if(!iscycle) return NULL;
        // Now how did they meet at this meeting point.. by the time.. slow reaches the meeting point.. fast has completed the loop and travelled the distance slow has travelled till the startin cycle
        // => distance between start - cyclestart = meeting point - cycle start
        // the distance x(from start to cycle start) = some k times looped distance d(distance of loop)+ distance between meeting point and cycle start.
        slow = head;
        while(slow!=fast){
            slow=slow->next;
            fast = fast->next;
        }
        return slow; // the point where they travel equal distance from their offsets  and meet is where the cycle start.

    }
};

int main(){
    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);

    // lets create a cycle at index 2;
    ll.createcycle(2);

    Solution s;
    node* result = s.detectcycle(ll.head);
    cout << result->data;
}