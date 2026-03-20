#include <iostream>
#include <vector>
#include <queue>
using namespace std;


// Let there be n number of rotten oranges -- each second the 1st neighboring oranges are rotten. -- BFS 
// In BFS -- we push a single source -- mark the source visited -- and in each iteration -- add the neighbours of the source into Queue and mark them visited.
// Instead here -- sicne we can have multiple sources -- we push all the sources -- and then perform BFS.
class Solution{
public:
    int orangesRotting(vector<vector<int>> &grid){
        int n=grid.size();
        int m = grid[0].size();
        int ans =0;

        vector<vector<bool>> vis(n,vector<bool>(m,false));
        queue<pair<pair<int,int>,int>> Q; // node(i,j),time

        // ingest all the rotten oranges
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    Q.push({{i,j},0});
                    vis[i][j]=true;
                }
            }
        }

        while(Q.size()>0){
            int i=Q.front().first.first;
            int j=Q.front().first.second;
            int time = Q.front().second;
            Q.pop();
            ans = max(ans,time);
            // there can be four boundaries for any node.
            if(i-1>=0 && !vis[i-1][j] && grid[i-1][j]==1){
                Q.push({{i-1,j},time+1}); 
                vis[i-1][j]=true;
            }
            if(j+1<m && !vis[i][j+1] && grid[i][j+1]==1){
                Q.push({{i,j+1},time+1});
                vis[i][j+1]=true;
            }
            if(i+1<n && !vis[i+1][j] && grid[i+1][j]==1){
                Q.push({{i+1,j},time+1});
                vis[i+1][j]=true;
            }
            if(j-1>=0 && !vis[i][j-1] && grid[i][j-1]==1){
                Q.push({{i,j-1},time+1});
                vis[i][j-1]=true;
            }
        }
        
        // even after bfs rotting there can still be oranges that are not rotten
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    return -1;
                }
            }
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    Solution S;
    cout << "time taken rot the oranges: " << S.orangesRotting(grid);
}