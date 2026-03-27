#include <iostream>
#include <vector>
#include <queue>
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

void dijkstra(int src, vector<vector<Edge>> &G, int V){
    vector<int> dist(V,INT32_MAX);
    dist[src]=0;
    // priority_queue<int> -- max heap
    // priority_queue<int,vector<int>(- how int is stored),greater<int>(comparater)> -- min heap 
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // dist[u],u  --to get sorted based on dist[u]
    pq.push({0,src});
    while(pq.size()>0){
        int u = pq.top().second;
        pq.pop();
        for(Edge e : G[u]){
            if(dist[e.v] > dist[u]+e.wt){
                dist[e.v] = dist[u]+e.wt;
                pq.push({dist[e.v],e.v});
            }
        }
    }

    for(int i=0;i<V;i++){
        cout << dist[i] << " ";
    }
    
}

int main(){
    int V = 6;
    vector<vector<Edge>> G(V);
    G[0].push_back(Edge(1,2));
    G[0].push_back(Edge(2,4));

    G[1].push_back(Edge(3,7));
    G[1].push_back(Edge(2,1));

    G[2].push_back(Edge(4,3));

    G[3].push_back(Edge(5,1));

    G[4].push_back(Edge(3,2));
    G[4].push_back(Edge(5,5));

    dijkstra(0,G,V);
}