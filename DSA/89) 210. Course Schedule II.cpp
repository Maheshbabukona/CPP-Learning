#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution{
    bool iscycle(int src, vector<bool> &vis, vector<bool> &recpath, vector<vector<int>> &edges){
        vis[src]= true;
        recpath[src] = true;
        for(int i=0;i<edges.size();i++){
            int v = edges[i][0];
            int u = edges[i][1];

            if(src ==u){
                if(!vis[v]){
                    if(iscycle(v,vis,recpath,edges)) return true;
                }
                else if(recpath[v]) return true;
            }
        }
        recpath[src] = false;
        return false;
    }

    void topoOrder(int src, vector<bool> &vis, stack<int> &s, vector<vector<int>> &edges){
        vis[src]= true;
        for(int i=0;i<edges.size();i++){
            int v = edges[i][0];
            int u = edges[i][1];

            if(src==u){
                if(!vis[v]){
                    topoOrder(v,vis,s,edges);
                }    
            }    
        }
        s.push(src);
    }
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges){
        vector<bool> vis(n,false);
        vector<bool> recpath(n,false);
        vector<int> ans;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(iscycle(i,vis,recpath,edges)) return ans;
            }
        }

        stack<int> s;
        vis.assign(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                topoOrder(i,vis,s,edges);
            }
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};

int main(){
    vector<vector<int>> prerequisites = {{1,0},{2,0},{3,1},{3,2}};
    int numcourses = 4;
    Solution S;
    vector<int> res = S.findOrder(numcourses,prerequisites);
    cout << "possible order: ";
    for(int val: res){
        cout << val << " ";
    }
}