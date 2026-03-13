#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph{
    int V;
    list<int> *l; // this is pointer list.. which stores addresses

    void dfs_helper(int u, vector<bool> &visited){
        cout << u << " ";
        visited[u]=true;
        for(int v: l[u]){
            if(!visited[v]){
                dfs_helper(v,visited);
            }
        }
    }
public:
    Graph(int V){
        this->V = V;
        l = new list<int> [V]; // this creates V number of lists and each address is stored in l;
    }

    void addEdge(int u, int v){ // if u and v are connected and if this is undirected graph -- u is stored in v adjlist and v is stored in u adjlist;
        l[u].push_back(v);
        l[v].push_back(u);
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

    void BFS(){ // visit the neighbour nodes first.
        // BFS -- uses queue -- 
        queue<int> Q;
        vector<bool> Visited(V,false);

        Q.push(0);
        Visited[0]=true;

        while(Q.size()){
            int u = Q.front();
            Q.pop();
            cout << u << " ";
            for(int v: l[u]){
                if(!Visited[v]){
                    Visited[v]=true;
                    Q.push(v);
                }
            }
        }
    }

    void DFS(){
        vector<bool> visited(V,false);
        int src=0;
        dfs_helper(src,visited);
    }

};


int main(){
    Graph G(5);
    G.addEdge(0,1);
    G.addEdge(1,2);
    G.addEdge(1,3);
    G.addEdge(2,3);
    G.addEdge(2,4);
    
    G.printadjlist();
    cout << "\nBFS\n";
    G.BFS();
    cout << "\nDFS:\n";
    G.DFS();

}