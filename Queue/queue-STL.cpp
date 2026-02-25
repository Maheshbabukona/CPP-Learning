#include <iostream>
#include <queue>
#include <deque>
using namespace std;

int main(){
    queue<int> que;
    que.push(1);
    que.push(2);
    que.pop();
    que.pop();
    que.pop();
    cout << "You see a garbage value since you are trying to pop on empty queue and memory is underflowed - "<<que.size()<<endl; // memory underflowed -- trying to pop on empty queu


    deque<int> deq;
    deq.erase(deq.begin()+2);
    
}