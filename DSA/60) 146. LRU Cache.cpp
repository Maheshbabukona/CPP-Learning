/*
We implement this using DLL and map, DLL -> to store the key,value. Map to retrieve the required from dll.
Here as per LRU -> Most recently used MRU is stored at the start of DLL. 
and LRU -> least recently used is stored at end of DLL.

Two dll functions addnode -> adds the node at the start right after dummy head,
delnode -> removes the pointing node.

put(key,val) -> a newnode is created addnode is called.. m[key]=newnode(address of the node)
get(key) -> m[key]->val
*/

#include <iostream>
#include <unordered_map>
using namespace std;

class LRU_Cache{
public:
    class node{
    public:
        int key,val;
        node* next;
        node* prev;

        node(int k,int v){
            key = k;
            val = v;
            prev=next = NULL;
        }
    };
    
    // dummy head and tail
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    unordered_map<int,node*> m;
    int limit;

    LRU_Cache(int capacity){
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }

    // addnode -> to add the newnode at the starting

    void addnode(node* newnode){
        node* oldnext = head->next;
        head->next = newnode;
        oldnext->prev = newnode;
        newnode->next = oldnext;
        newnode->prev = head;
    }
    // delnode -> to remove the node at place.
    void delnode(node* oldnode){
        node* oldprev = oldnode->prev;
        node* oldnext = oldnode->next;
        oldprev->next = oldnext;
        oldnext->prev = oldprev;
    }

    int get(int key){
        if (m.find(key)!=m.end()){
            int ans = m[key]->val;
            node* ansnode = m[key];
            delnode(ansnode);
            addnode(ansnode);
            m[key]=ansnode;
            return ans;
        }
        return -1;
    }

    void put(int key, int value){
        // check 1 - if key already exists
        if(m.find(key)!=m.end()){
            node* oldnode = m[key];
            delnode(oldnode);
            m.erase(key);
        }
        //check 2 -> overloading capacity -> remove lru
        if(m.size()==limit){
            m.erase(tail->prev->key);
            delnode(tail->prev);
        }

        node* newnode = new node(key,value);
        addnode(newnode);
        m[key]=newnode;
    }

};

int main(){
    LRU_Cache* lRUCache = new LRU_Cache(2);

    lRUCache->put(1, 1);                 // cache is {1=1}
    lRUCache->put(2, 2);                 // cache is {1=1, 2=2}

    cout << lRUCache->get(1) << endl;    // return 1

    lRUCache->put(3, 3);                 // evicts key 2

    cout << lRUCache->get(2) << endl;    // return -1

    lRUCache->put(4, 4);                 // evicts key 1

    cout << lRUCache->get(1) << endl;    // return -1
    cout << lRUCache->get(3) << endl;    // return 3
    cout << lRUCache->get(4) << endl;    // return 4
}
