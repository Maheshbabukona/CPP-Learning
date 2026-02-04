#include <iostream>
using namespace std;

class node{
public:
    int data;
    node* next;

    node(int val){
        data=val;
        next = NULL;
    }
};

class List{
    node* head;
    node* tail;

public:
    List(){
        head=tail=NULL; // initially an empty linked list is created.
    }

    void push_front(int val){
        node* newnode = new node(val); // new allocates memory and then points to node(Val)
        if(head==NULL){
            head=tail=newnode;
        }
        else{
            newnode->next = head; // current head is pointing to the prev node.. so we insert before it.. so cur next should be pointing to that.
            head=newnode;
        }
    }

    void push_back(int val){
        node* newnode = new node(val);
        if(head==NULL){
            head=tail=newnode;
        }
        else{
            tail->next=newnode; // make the last node point to the new node.
            tail=newnode;
        }
    }

    void insertatpos(int val, int pos){
        if(pos<0) return;
        if(pos==0){
            push_front(val);
            return;
        }
        node* temp = head;
        for(int i=0; i<pos-1;i++){
            if(temp==NULL){
                cout << "Invalid pos\n";
                return;
            }
            temp = temp->next;
        }

        node* newnode = new node(val);
        newnode->next = temp->next;
        temp->next = newnode;
    }

    void search_ll(int val){
        if(head==NULL){
            cout << "Not found";
            return;
        }
        node* temp = head;
        int idx = 0;
        while(temp->next!=NULL){
            if(temp->data==val){
                cout << "Found at "<< idx << endl;
                return;
            }
            temp=temp->next;
            idx++;
        }
        cout << "Not found";
        return;
    }

    void pop_front(){
        if(head==NULL){
            return;
        }
        node* temp = head;
        head = head->next;
        delete temp;
    }

    void pop_back(){
        if(head==NULL){
            return;
        }
        node* temp = head;
        while(temp->next!=tail){
            temp = temp->next;
        }
        temp->next=NULL;
        delete tail; // delete the node tail pointing to 
        tail = temp; // point the tail to prev node of last.
    }
    void printlist(){
        node* temp = head;
        while(temp!=NULL){
            cout << temp->data << "->";
            temp= temp->next;
        }
        cout << "NULL"<< endl;
    }
};

int main(){
    List ll;
    ll.push_front(2);
    ll.push_front(1);
    ll.push_back(3);
    ll.insertatpos(4,1);
    ll.search_ll(5);
}