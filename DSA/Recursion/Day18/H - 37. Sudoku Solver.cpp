/*
Given a presemi filled sudoku board -- goal  is to fill out remaining empty cells as per sudoku rules.
traversal logic -- nextC = col+1 , nextR = row until nextC=9 lastcol- go to nextrow - nextR = row+1 and nextC=0

if(any filled cell -- !='.) go to next cell -- helper(board,nextR,nextC)
filling logic
for(char dig - 1->9) if the dig issafe - board[row][col]=dig and check for future calls -- helper(board,nextR,nextC)
if future calls fail -- returned false -- backtrack -- board[row][col]=='.'

isSafe logic
vertical check -- iterate row
horizontal check -- iterate col
grid level check -- in here grid start indexes are at 0,3,6 -- we get to know the grid group a pos belongs to if we divide it/3 -- there are 3 grids for row and 3 for col
so --> to identify the grid indexes -- (pos/3)*3 -- iterate +2 indexes -- to search that grid.
*/
#include <iostream>
#include <vector>
using namespace std;
class sudoku{
    bool isSafe(vector<vector<char>> &board, int row, int col, char dig){
        for(int r=0;r<9;r++){
            if(board[r][col]==dig) return false;
        }
        for(int c=0;c<9;c++){
            if(board[row][c]==dig) return false;
        }
        int srow=(row/3)*3, scol=(col/3)*3;
        for(int r=srow;r<=srow+2;r++){
            for(int c=scol;c<=scol+2;c++){
                if(board[r][c]==dig) return false;
            }
        }
        return true;
    }
    bool helper(vector<vector<char>> &board, int row, int col){
        if(row==9) return true; // base logic

        int nextR = row;
        int nextC = col+1;
        if(nextC==9){
            nextR= row+1;
            nextC=0;
        } // traversing logic col first and then next row

        if(board[row][col]!='.') return helper(board,nextR,nextC); // already filled -- go to next cell

        for(char dig='1';dig<='9';dig++){
            if(isSafe(board,row,col,dig)){
                board[row][col]=dig;
                if(helper(board,nextR,nextC)) return true;
            }
            board[row][col]='.'; // if future fails -- backtrack
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        helper(board,0,0);
    }
};

int main(){
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    sudoku S;   
    S.solveSudoku(board);
    cout << "[";
    for(int i=0;i<board.size();i++){
        cout << "[";
        for(int j=0;j<board[i].size();j++){
            cout << board[i][j];
            if(j<board[i].size()-1) cout << ",";
        }
        cout << "]";
        if (i<board.size()-1) cout << ",";
        
    }
    cout << "]";
}