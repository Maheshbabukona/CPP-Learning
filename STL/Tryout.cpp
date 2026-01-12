#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
using namespace std;

int main(){
    // vector<pair<int,int>> v = {{1,2},{2,3}};
    // v.push_back({3,4}); // push_back assumes object is already present and it just inserts there.  -> need to insert in the form of dtype
    // v.emplace_back(4,5); // emplace back creates the defined object type space and inserts
    // for(auto i: v){
    //     cout << i.first << " " << i.second << endl;
    // }

    // stack<int> s;
    // s.emplace(1);
    // s.push(2);
    // s.push(3);
    // by default if we use -> priority_queue<int> --> it creates in descending order => default = priority_queue<int,vector<int>,less<int>>
    // priority_queue<int,vector<int>,greater<int>> pq; // This creates the min heap priority queue.. elements are in ascending order
    // pq.push(4);
    // pq.push(2);
    // pq.push(1);
    // pq.push(3);
    // while(!pq.empty()){
    //     cout << pq.top() << " ";
    //     pq.pop();
    // }
    // cout << endl;
    map<string,int> m;
    for(int i=0;i<3;i++){
        string k; int v;
        cin >> k >> v;
        m[k]=v;
    }
    m.insert({"4",5}); // should stick to dtype
    m.emplace("4",6);

    for(auto &p: m){
        cout << p.first << " : "<< p.second << endl;
    }
}