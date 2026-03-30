/*
Goal to find the best rewarding path to reach the end of the maze. 
vector<vector<int>> will have points at each place can be positive or negative.

the path with max sum is returned 
*/

#include <iostream> 
#include <vector>
using namespace std;

void dfs(vector<vector<int>> &grid, int r, int c, int cursum, string path, int &maxsum, string &bestpath){
    // base conditions
    int n = grid.size();
    if(r>=n || c>=n) return;
    cursum+= grid[r][c];
    if(r==n-1 && c==n-1){
        if(cursum>maxsum){
            bestpath=path;
            maxsum=cursum;
        }
        return;
    }

    dfs(grid,r+1,c,cursum, path+"D", maxsum,bestpath); // going down
    dfs(grid,r,c+1,cursum, path+"R",maxsum,bestpath); // going down
}

string bestpathmaze(vector<vector<int>> &grid){
    int cursum=0, maxsum=INT32_MIN;
    string path ="", bestpath="";
    dfs(grid,0,0,cursum,path,maxsum,bestpath);
    return bestpath;
}

int main(){
    vector<vector<int>> grid = {{0,10,-5,6},{4,-2,10,8},{-6,5,-4,2},{3,2,-3,0}};
    cout << bestpathmaze(grid);
}