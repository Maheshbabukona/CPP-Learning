#include <iostream>
using namespace std;

class CircularQueue{
    int* arr; // pointer array
    int cursize, cap;
    int f,r;

public:
    CircularQueue(int size){
        cap = size;
        cursize = 0;
        arr = new int[cap]; // dynamic memory
        f=0,r=-1;
    }

    void push(int data){
        if(cursize==cap){
            cout << "CQ capacity reached"<< endl;
            return;
        }
        r=(r+1)%cap;
        arr[r]=data;
        cursize++;
    }

    void pop(){
        if(empty()){
            cout << "CQ is empty" << endl;
            return;
        }
        f=(f+1)%cap; //we point the pointer to next element. so previous element is irrelavant.. its not actual pop but..
        cursize--;

    }

    int front(){
        if(empty()){
            cout << "CQ is empty"<<endl;
            return -1;
        }
        return arr[f];
    }

    bool empty(){
        if(cursize==0){
            return true;
        }
        return false;
    }

};

int main(){
    CircularQueue cq(3);
    cq.push(1);
    cq.push(2);
    cq.push(3);
    cq.pop();
    cq.pop();
    cq.pop();
    cq.front();
}