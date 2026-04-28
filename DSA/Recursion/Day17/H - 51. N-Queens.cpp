/*
Given a input n..
There is nxn board -- you need your queens to be filled.
Rules: 
No queen should see other queen  Horizontally, vertically, diagonally.

output -- possible board formations returned in a vector.

Approach
1) Iterate and place a queen in a col -- run the recursion of placing it next rows -- but only safe placing..
2) Issafe function -- check vertically from current row to above -- since down rows q is not placed yet.
horizontal check is not needed since we are iterating col placing over for loop -- and placing only one q in a col
for diagonal check -- left upper diagonal and right upper diagonal..

For backtracking -- unmark the q cell as '.'
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution{
    bool isSafe(vector<string> &boards, int row, int col, int n){
        for(int r=row;r>=0;r--){
            if(boards[r][col]=='Q') return false;
        }
        for(int r=row,c=col;r>=0 && c>=0; r--,c--){
            if(boards[r][c]=='Q') return false;
        }
        for(int r=row,c=col;r>=0 && c<n; r--,c++){
            if(boards[r][c]=='Q') return false;
        }
        return true;
    }
    void nqueens(vector<string> &boards, int row, int n, vector<vector<string>> &ans){
        if(row==n){
            ans.push_back(boards);
            return;
        }
        for(int c=0;c<n;c++){
            if(isSafe(boards,row,c,n)){
                boards[row][c]='Q';
                nqueens(boards,row+1,n,ans);
                boards[row][c]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> boards(n,string(n,'.'));
        vector<vector<string>> ans;
        nqueens(boards,0,n,ans);
        return ans;
    }
};

int main(){
    int n =4;
    Solution S;
    vector<vector<string>> result = S.solveNQueens(n);
    cout << "[";
    for(int i=0;i<result.size();i++){
        cout << "[";
        for(int j=0;j<result[i].size();j++){
            cout << result[i][j];
            if(j<result[i].size()-1) cout << ",";
        }
        if (i<result.size()-1) cout << ",";
        cout << "]";
    }
    cout << "]";
}