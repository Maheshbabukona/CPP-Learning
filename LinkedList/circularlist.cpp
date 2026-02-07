#include <iostream>
using namespace std;

class node{
public:
    int data;
    node* next;

    node(int val){
        data =val;
        next=NULL;
    }
};

class circular_list{
public:
    node* tail; // head is tail->next

    circular_list(){
        tail=NULL;
    }

    void insertattail(int val){
        node* newnode = new node(val);
        if(tail==NULL){
            tail=newnode;
            tail->next = tail;
            return;
        }
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;
    }

    void insertathead(int val){
        node* newnode = new node(val);
        if(tail==NULL){
            tail=newnode;
            tail->next = tail;
            return;
        }
        newnode->next = tail->next;
        tail->next = newnode;
    }

    void insertatmiddle(int pos, int val){
        if(pos<0) return;
        if(pos==0){
            insertathead(val);
            return;
        }
        node* temp = tail->next;
        for(int i=0;i<pos-1;i++){
            temp=temp->next;
            if(temp==tail->next){
                cout << "Invalid pos\n";
                return;
            }
        }
        node* newnode = new node(val);
        newnode->next = temp->next;
        temp->next = newnode;  
        if(temp==tail){
            tail=newnode;
        }
    }

    void delete_at_head(){
        if(tail==NULL) return;
        if(tail==tail->next){
            delete tail;
            tail=NULL;
            return;
        }
        node* temp = tail->next;
        tail->next = temp->next;
        delete temp;
    }

    void delete_at_tail(){
        if(tail==NULL) return;
        if(tail==tail->next){
            delete tail;
            tail=NULL;
            return;
        }
        node* temp = tail->next;
        while(temp->next!=tail){
            temp=temp->next;
        }
        temp->next = tail->next;
        delete tail;
        tail=temp;
    }

    int search_circularlist(int val){
        if(tail==NULL) return -1;
        node* temp = tail->next;
        int idx =0;
        do{ // why do while.. tail->next = head where we started.. to cover all.. we check atleast once and then compare.
            if(temp->data==val) return idx;
            temp=temp->next;
            idx++;
        }while(temp!=tail->next);
        return -1;
    }

    void printcircularlist(){
        if(tail==NULL){
            cout << "NULL";
            return;
        }
        node* temp = tail->next;
        do{
            cout << temp->data<<"->";
            temp=temp->next;
        }while(temp!=tail->next);
        cout << " cycle starts here";
    }
};

int main(){
    circular_list cll;
    cll.insertathead(1);
    cll.insertattail(3);
    cll.insertatmiddle(1,2);
    cll.insertathead(0);
    cll.insertattail(5);
    cll.delete_at_head();
    cll.delete_at_tail();
    cll.printcircularlist();
}