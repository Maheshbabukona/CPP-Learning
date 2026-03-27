#include <iostream>
#include <vector>
using namespace std;

class Edge{
public:
    int v;
    int wt;

    Edge(int v, int wt){
        this->v = v;
        this->wt = wt;
    }
};

// In bellman -- We calculate going from u->v via all edges -- 
// why do it v-1 times --> in worst case -- going from src->v might be through all intermittent nodes -- V-1.. so on first iteration we consider going from src->v through 1 node,2 on second likewise we do for v-1.
void bellman_ford(int src, vector<vector<Edge>> &G,int V){
    vector<int> dist(V,INT32_MAX);
    dist[src]= 0;
    for(int i=0;i<V-1;i++){
        for(int u=0;u<V;u++){
            for(Edge e: G[u]){
                if(dist[e.v]>dist[u]+e.wt){
                    dist[e.v] = dist[u]+e.wt;
                }
            }
        }
    }
    cout << "optimized dist using bellman ford: ";
    for(int dis : dist){
        cout << dis << " ";
    }
}
int main(){
    int V = 5;
    vector<vector<Edge>> G(V);
    
    G[0].push_back(Edge(1,2));
    G[0].push_back(Edge(2,4));
    
    G[1].push_back(Edge(4,-1));
    G[1].push_back(Edge(2,-4));

    G[2].push_back(Edge(3,2));

    G[3].push_back(Edge(4,4));

    bellman_ford(0,G,V);
}