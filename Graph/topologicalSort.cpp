#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Graph{
    int V;
    list<int> *l;

    void topo_helper(int cur, vector<int> &vis, stack<int> &s){
        vis[cur] = true;
        for(int neigh: l[cur]){
            if(!vis[neigh]){
                topo_helper(neigh,vis, s);
            }
        }
        s.push(cur);
    }
public:
    Graph(int V){
        this->V = V;
        l = new list<int> [V];
    }

    void addEdge(int u, int v){
        l[u].push_back(v); // directional
    }

    void printadjlist(){
        for(int i=0;i<V;i++){
            cout << i << " : ";
            for(int neigh : l[i]){
                cout << neigh << " ";
            }
            cout << endl;
        }
    }

    void topological_sort(){
        vector<int> vis(V,false);
        stack<int> s;

        for(int i=0;i<V;i++){
            if(!vis[i]){
                topo_helper(i,vis,s);
            }
        }

        while(!s.empty()){
            cout << s.top() << " ";
            s.pop();
        }
    }
};

int main(){
    Graph G(6);
    G.addEdge(5, 0);
    G.addEdge(5, 2);
    G.addEdge(4, 0);
    G.addEdge(4, 1);    
    G.addEdge(2, 3);
    G.addEdge(3, 1);
    G.printadjlist();
    cout <<"\nTopological Sort of this graph:\n";
    G.topological_sort();
}