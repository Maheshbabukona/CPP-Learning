#include <iostream>
#include <vector>
using namespace std;

bool issafe(vector<string> &board, int row, int col, int n){
    for(int r=row-1;r>=0;r--){
        if(board[r][col]=='Q') return false;
    }
    for(int r=row-1,c=col-1; r>=0 && c>=0; r--,c--){
        if(board[r][c]=='Q') return false;
    }
    for(int r=row-1,c=col+1; r>=0 && c<n;r--,c++){
        if(board[r][c]=='Q') return false;
    }
    return true;
}
void nqueens(vector<string> &board, int row, int n, int &ans){
    if(row==n){
        ans++;
        return;
    }
    for(int c=0;c<n;c++){
        if(issafe(board,row,c,n)){
            board[row][c]='Q';
            nqueens(board,row+1,n,ans);
            board[row][c]='.';
        }
    }

}
int totalNQueens(int n) {
    vector<string> board(n,string(n,'.'));
    int ans = 0;
    nqueens(board,0,n,ans);
    return ans;
}

int main(){
    int n=4;
    int result = totalNQueens(n);
    cout << "Total possible arrangements: "<< result<< endl;
}