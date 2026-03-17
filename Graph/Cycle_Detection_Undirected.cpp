#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph{
    int V;
    list<int> *l;
    /*
    Using dfs -- for all neighboours there are 2 options  --> unvisited / visited. 
    for univisted nodes --- we visit them.
    for visited nodes -- we have 2 options --> same src, different src. If it is identified as visited but from a different src -- cycle does exist.
    */
    bool iscycle_dfs_helper(int src, vector<bool> &visited, int par){
        visited[src]= true;
        for(int v: l[src]){
            if(!visited[v]){
                if(iscycle_dfs_helper(v,visited,src)) return true;
            }
            else if(v!=par) return true; // its coming from different parent 
            // else case -- its coming from same parent -- here for all vs -- same parent
        }
        return false;
    }
    bool iscycle_bfs_helper(int src, vector<bool>&visited){
        queue<pair<int,int>> q;
        q.push({src,-1});
        visited[src]=true;
        while(q.size()>0){
            int u = q.front().first;
            int par = q.front().second;
            q.pop();
            for(int v: l[u]){
                if(!visited[v]){
                    q.push({v,u});
                    visited[v]=true;
                }
                else if(v!=par){
                    return true;
                }
            }
        }
        return false;
    }
public:
    Graph(int V){
        this-> V = V;
        l = new list<int> [V]; // new list of size V -- V number of nodes
    }
    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void printadjlist(){
        for(int i=0;i<V;i++){
            cout << i << " : ";
            for(int v : l[i]){
                cout << v << " ";
            }
            cout << endl;
        }

    }

    bool isCycle_DFS(){
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++){ // why for all --> to detect disconnected graphs.
            if(!visited[i]){
                if(iscycle_dfs_helper(i,visited,-1)) return true;
            }
        }
        return false;
    }
    bool isCycle_BFS(){
        vector<bool> Visited(V,false);
        for(int i=0;i<V;i++){
            if(!Visited[i]){
                if(iscycle_bfs_helper(i,Visited)) return true;
            }
        }
        return false;
    }
};

int main(){
    Graph G(5);

    G.addEdge(0,1);
    G.addEdge(0,2);
    G.addEdge(1,2);
    G.addEdge(0,3);
    G.addEdge(3,4);
    cout << "The adj list:\n";
    G.printadjlist();
    cout << "\nIs there a cycle ?? -- Using DFS\n";
    cout << ((G.isCycle_DFS()) ? "true": "false");
    cout << "\nIs there a cycle ?? -- Using BFS\n";
    cout << ((G.isCycle_BFS()) ? "true": "false");

}