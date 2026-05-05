/*
Any knight has 8 options 2 go from its pos r,c -->
1) r-2,c+1
2) r-1,c+2
3) r+1, c+2
4) r+2,c+1
5) r+2,c-1
6) r+1,c-2
7) r-1, c-2
8) r-2, c-1

Here given a travel sequence of a knight -- we should check if the knight would be able to follow the same order. I.e-- from any pos is it possible to reach pos+1

Approach --- if next cell is out of booundaries or grid[r][c]!=expval then false -- cant be possible with those chosen moves.
Final cell == expval == n**2-1  why -- if nxn there are nxn-1 cells.. if expval is final cell val -- it finally reached the last cell -- true

run through all 8 options.. and return if any 1 option makes the knight reach final cell.
*/

#include<iostream>
#include <vector>
using namespace std;

class Solution{
    bool isvalid(vector<vector<int>> grid,int r, int c, int n, int expval){
        if(r<0 || c<0 || r>=n || c>=n || grid[r][c]!=expval) return false;
        if(expval==n*n-1) return true;

        // 8 options chain
        bool ans1 = isvalid(grid,r-2,c+1,n,expval+1);
        bool ans2 = isvalid(grid,r-1,c+2,n,expval+1);
        bool ans3 = isvalid(grid,r+1,c+2,n,expval+1);
        bool ans4 = isvalid(grid,r+2,c+1,n,expval+1);
        bool ans5 = isvalid(grid,r+2,c-1,n,expval+1);
        bool ans6 = isvalid(grid,r+1,c-2,n,expval+1);
        bool ans7 = isvalid(grid,r-1,c-2,n,expval+1);
        bool ans8 = isvalid(grid,r-2,c-1,n,expval+1);

        return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
    }
public:
    bool checkValidGrid(vector<vector<int>>& grid){
        return isvalid(grid,0,0,grid.size(),0);
    }
};

int main(){
    vector<vector<int>> grid = {{0,11,16,5,20},{17,4,19,10,15},{12,1,8,21,6},{3,18,23,14,9},{24,13,2,7,22}};
    Solution S;
    cout << "Is it possible for knight: " << (S.checkValidGrid(grid) ? "Yes" : "No"); 
}