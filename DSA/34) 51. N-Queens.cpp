#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool issafe(vector<string> board, int row, int col, int n){
    // horizontal check is not required since only 1 q is placed at each row
    // vertical check we are gonna check with upper values in the col 
    for(int r=row-1;r>=0;r--){
        if(board[r][col]=='Q') return false;
    }
    // for diagonal we are gonna check left upper and right upper.. since we dont need to check unplaced down elements.
    // left upper
    for(int r=row,c=col;r>=0 && c>=0;r--,c--){ // as we go up row receeds, as we go left column receeds
        if(board[r][c]=='Q') return false;
    }
    //right upper
    for(int r=row,c=col;r>=0 && c<n;r--,c++){ // as we go up row receeds, as we go right column increases
        if(board[r][c]=='Q') return false;
    }
    return true;
}

void nqueens(vector<string> &board, int row, int n, vector<vector<string>> &ans){
    // base case
    if(row==n){
        ans.push_back(board);
        return;
    }
    for(int c=0;c<n;c++){ // iterating to every pos on the row.. finding safe square for q
        if(issafe(board,row,c,n)){ 
            board[row][c]='Q';
            nqueens(board,row+1,n,ans);
            board[row][c]='.'; // backtracking step.. if there isnt found any c value for a row then its gonna come back .. change the q to next pos.
        }
    }
}

vector<vector<string>> solvenqueens(int n){
    vector<string> board(n,string(n,'.')); // we initialize board with .
    vector<vector<string>> ans; // we will have vector of vector to store all the possible board arrangements possible
    nqueens(board,0,n,ans);
    return ans;
}

int main(){
    int n =4;
    vector<vector<string>> result = solvenqueens(n);
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