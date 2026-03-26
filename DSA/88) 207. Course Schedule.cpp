#include <iostream>
#include <vector>
using namespace std;

class Solution{
    bool iscycle_course(int src, vector<bool> &vis, vector<bool> &recpath, vector<vector<int>>&edges ){
        vis[src]= true;
        recpath[src]=true;

        for(int i=0;i<edges.size();i++){
            int u=edges[i][1];
            int v = edges[i][0];

            if(src == u){
                if(!vis[v]){
                    if(iscycle_course(v,vis,recpath,edges)) return true;
                }
                else if(recpath[v]) return true;
            }
        }
        recpath[src]=false;
        return false;
    }
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n,false);
        vector<bool> recpath(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(iscycle_course(i,vis,recpath,edges)) return false; // if cycle is true -- topo is false 
            }
        
        }

        return true;
    }
};

int main(){
    vector<vector<int>> prerequisites = {{1,0},{2,0},{3,1},{3,2}};
    int numcourses = 4;
    Solution S;
    cout << "Is it possible to finish: " << ((S.canFinish(numcourses,prerequisites)) ? "Yes" : "No");
}  