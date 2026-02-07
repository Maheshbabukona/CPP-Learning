#include <iostream>
#include <unordered_map>
using namespace std;

class node {
public:
    int data;
    node* next;
    node* random;

    node(int val) {
        data = val;
        next = NULL;
        random = NULL;
    }
};

class List {
public:
    node* head;
    node* tail;

    List() {
        head = tail = NULL;
    }

    void push_back(int val) {
        node* newnode = new node(val);
        if (head == NULL) {
            head = tail = newnode;
            return;
        }
        tail->next = newnode;
        tail = newnode;
    }

    // Helper to access node by index (to set random pointers)
    node* getNodeAt(int index) {
        node* temp = head;
        int i = 0;
        while (temp != NULL && i < index) {
            temp = temp->next;
            i++;
        }
        return temp;
    }

    // Print list showing next + random
    void printList(node* head) {
        node* temp = head;
        while (temp != NULL) {
            cout << "Node(" << temp->data << ")";
            if (temp->random)
                cout << " Random->(" << temp->random->data << ")";
            else
                cout << " Random->(NULL)";
            cout << endl;
            temp = temp->next;
        }
        cout << "------------------\n";
    }
};

class Solution {
public:
    node* copyRandom(node* head) {
        if (head == NULL) return NULL;

        unordered_map<node*, node*> m;

        // Step 1: Copy nodes + next pointers
        node* newhead = new node(head->data);
        m[head] = newhead;

        node* oldTemp = head->next;
        node* newTemp = newhead;

        while (oldTemp != NULL) {
            node* copynode = new node(oldTemp->data);
            m[oldTemp] = copynode;
            newTemp->next = copynode;

            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        // Step 2: Copy random pointers
        oldTemp = head;
        newTemp = newhead;

        while (oldTemp != NULL) {
            newTemp->random = oldTemp->random ? m[oldTemp->random] : NULL;
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
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
    node* copiedHead = s.copyRandom(ll.head);

    cout << "Copied List:\n";
    ll.printList(copiedHead);

    return 0;
}
