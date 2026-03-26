#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

class Graph{
    int V;
    list<int> *l;

// In the same dfs -- since this is directed.. a cycle can exist if the node is already visited and the same node is present in recursion path.

    bool Cycle_detection_DFS_helper(int cur, vector<int> &vis, vector<int> &recpath){
        vis[cur] = true;
        recpath[cur] = true; // mark the node as visited in this path
        for(int neigh: l[cur]){
            if(!vis[neigh]){
                if(Cycle_detection_DFS_helper(neigh, vis,recpath)) return true;
            }
            else if(recpath[neigh]) return true;
        }
        recpath[cur] = false; // unmark the node as you complete the recursion run.
        return false;
    }
public:
    Graph(int V){
        this->V = V;
        l = new list<int> [V];
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
    }

    void printadjlist(){
        for(int i=0;i<V;i++){
            cout << i << " : ";
            for(int neigh: l[i]){
                cout << neigh << " ";
            }
            cout << endl;
        }
    }

    bool Cycle_detection_DFS(){
        vector<int> vis(V,false);
        vector<int> recpath(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(Cycle_detection_DFS_helper(i,vis,recpath)) return true; 
            }
        }

        return false;
    }
};

int main(){
    Graph G(4);
    G.addEdge(1,0);
    G.addEdge(0,2);
    G.addEdge(2,3);
    G.addEdge(3,0);

    G.printadjlist();
    cout << "Is there a cycle in this graph? "<< G.Cycle_detection_DFS();
}