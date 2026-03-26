#include <iostream>
#include <queue>
#include <vector>
#include <list>
using namespace std;

class Graph{
    int V;
    list<int> *l;
public:
    Graph(int V){
        this->V = V;
        l = new list<int>  [V];
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
    }

    void Topo_kahn(){
        vector<int> indeg(V,0);
        queue<int> Q;
        vector<int> res;
        for(int i=0;i<V;i++){
            for(int v: l[i]){
                indeg[v]++;
            }
        }
        for(int i=0;i<V;i++){
            if(indeg[i]==0){
                Q.push(i);
            }
        }
        
        while(Q.size()>0){
            int cur = Q.front();
            Q.pop();
            res.push_back(cur);
            for(int v: l[cur]){
                indeg[v]--;
                if(indeg[v]==0){
                    Q.push(v);
                }
            }
        }
        cout << "Topo sort: ";
        for(int val: res){
            cout << val << " ";
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
    G.Topo_kahn();
}