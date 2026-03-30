/*
Here knight can go to 8 different sqaures from center 
1) r-2,c+1
2) r-1,c+2
3) r+1, c+2
4) r+2,c+1
5) r+2,c-1
6) r+1,c-2
7) r-1, c-2
8) r-2, c-1

knight can go to any square above.. but here we need to go to a eliglble square where the value is curvalue+1=expectedvalue.
each time knight searches  for expected value in its eligible squares.. jumps there repeats the process.

Finally when it moves for the final move n*n-1 == expected value .. then return true..
*/

#include <iostream>
#include <vector>
using namespace std;

bool isvalid(vector<vector<int>> &grid, int r, int c, int n, int expval){
    if(r<0 || c<0 || r>=n || c>=n || grid[r][c]!=expval) return true;
    if(expval==n*n-1) return true; // here it means knight at expval  cause earlier condition is met.. and the final expval=n*n-1
    // knight explore 8 different moves.
    bool ans1 = isvalid(grid, r-2,c+1,n,expval+1);
    bool ans2 = isvalid(grid,r-1,c+2,n,expval+1);
    bool ans3 = isvalid(grid,r+1,c+2,n,expval+1);
    bool ans4 = isvalid(grid,r+2,c+1,n,expval+1);
    bool ans5 = isvalid(grid,r+2,c-1,n,expval+1);
    bool ans6 = isvalid(grid,r+1,c-2,n,expval+1);
    bool ans7 = isvalid(grid,r-1,c-2,n,expval+1);
    bool ans8 = isvalid(grid,r-2,c-1,n,expval+1);
    return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
}

bool checkvalidgrid(vector<vector<int>> &grid){
    return isvalid(grid,0,0,grid.size(),0);
}

int main(){
    vector<vector<int>> grid = {{0,11,16,5,20},{17,4,19,10,15},{12,1,8,21,6},{3,18,23,14,9},{24,13,2,7,22}};
    cout << checkvalidgrid(grid);
}
