#include <iostream>
#include <vector>
using namespace std;

/*
For each node we start dfs search and mark visited.
dfs_grid -- what it does marks visited for all its connected neighbours which are not 0.
numIsIslands -- iterates through all nodes -- finds the unique calls -- which represent disconnected components.
*/
class Solution{
    void dfs_grid(int i, int j, vector<vector<bool>> &vis, vector<vector<char>> &grid, int n, int m){
        if(i<0 || j<0 || i>=n || j>=m || vis[i][j] || grid[i][j]!='1') return;
        vis[i][j]= true;
        // 4 neighbours
        dfs_grid(i-1,j,vis,grid,n,m);// top
        dfs_grid(i,j+1,vis,grid,n,m);// right
        dfs_grid(i+1,j,vis,grid,n,m);// bottom
        dfs_grid(i,j-1,vis,grid,n,m);// left
    }
public:
    int numIsIslands(vector<vector<char>> &grid){
        int islands = 0;
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> vis(n,vector<bool>(m,false));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    dfs_grid(i,j,vis,grid,n,m); // 1 call 
                    islands++;
                }
            }
        }
        return islands; 
    }
};

int main(){
    vector<vector<char>> grid = {
    {'1','1','0','0','0'},
    {'1','1','0','0','0'},
    {'0','0','1','0','0'},
    {'0','0','0','1','1'}
    };
    Solution S;
    cout << "Number of islands in the grid are: " << S.numIsIslands(grid);
}
