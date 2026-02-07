#include <iostream>
using namespace std;

class node{
public:
    int data;
    node* next;
    node* prev;

    node(int val){
        data = val;
        next=prev=NULL;
    }
};

class doublylist{
public:
    node* head;
    node* tail;

    doublylist(){
        head = tail = NULL;
    }

    void push_front(int val){
        node* newnode = new node(val);
        if (head==NULL){
            head = tail = newnode;
            return;
        }
        head->prev = newnode;
        newnode->next = head;
        head = newnode;
    }

    void push_back(int val){
        node* newnode = new node(val);
        if(head==NULL){
            head = tail = newnode;
            return;
        }
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }

    void insert_middle(int pos, int val){
        if (pos<0) return;
        if(pos==0){
            push_front(val);
            return;
        }
        node* temp = head;
        for(int i=0;i<pos-1;i++){
            if(temp==NULL){
                cout << "Invalid pos\n";
                return;
            }
            temp=temp->next;
        }
        node* newnode = new node(val);
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next = newnode;

        // backward link
        if(newnode->next!=NULL){
            newnode->next->prev=newnode;
        }
        else tail = newnode;
    }

    int search_list(int val){
        node* temp = head;
        int idx=0;
        while(temp!=NULL){
            if(temp->data==val) return idx;
            temp=temp->next;
            idx++;
        }
        return -1;
    }

    void printlist(){
        node* temp = head;
        cout << "NULL<->";
        while(temp!=NULL){
            cout << temp->data << "<->";
            temp=temp->next;
        }
        cout << "NULL"<<endl;
    }

    void pop_back(){
        if(head==NULL) return;
        if(head==tail){
            delete head;
            head=tail = NULL;
            return;
        }
        node* temp = tail;
        tail=tail->prev;
        tail->next=NULL;
        delete temp;
    }

    void pop_front(){
        if(head==NULL) return;
        if(head==tail){
            delete head;
            head=tail=NULL;
            return;
        }
        node* temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
    }
};

int main(){
    doublylist dll;
    dll.push_front(1);
    dll.push_back(2);
    dll.push_back(4);
    dll.push_back(5);
    dll.push_front(0);
    dll.insert_middle(3,3);
    dll.pop_front();
    dll.pop_back();
    dll.printlist();
}