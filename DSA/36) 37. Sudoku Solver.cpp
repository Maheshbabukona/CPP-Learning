#include <iostream>
#include <vector>
using namespace std;

bool issafe(vector<vector<char>> &board, int row, int col, char dig){
    // checking vertically
    for(int r=0;r<9;r++){
        if(board[r][col]==dig) return false;
    }
    //checking horizontally
    for(int c=0;c<9;c++){
        if(board[row][c]==dig) return false;
    }
    /* To check the grid.. 
    we know the board is 9*9.. and each grids index starts with row&col=0/3/6 - multiples of 3
    so at any pos if we divide the pos/3  we get to know in which region it exists remainder 0 - 1st region, 1-2nd region, 2- 3rd region
    and if we multiply the rem*3 we get to have the starting row and starting col  
    */
   int srow=(row/3)*3, scol=(col/3)*3;
   for(int r=srow;r<=srow+2;r++){
    for(int c=scol;c<=scol+2;c++){
        if(board[r][c]==dig) return false;
    }
   }
   return true;
}

bool helper(vector<vector<char>> &board, int row, int col){

    // nextRows and nextCols for each recursion
    int nextR=row,nextC=col+1;
    if (nextC==9)
    {
        nextR=row+1;
        nextC=0;
    }
    
    // base condition
    if(row==9) return true; // sucessful execution till now.. all values are ingested.

    if(board[row][col]!='.') return helper(board,nextR,nextC); // if number already exists we move to next place.

    for(char dig='1';dig<='9';dig++){
        if(issafe(board,row,col,dig)){
            board[row][col]=dig;
            if(helper(board,nextR,nextC)) return true;
        }
        board[row][col]='.'; // we backtrack if itsnt true..
    }
    return false;
}
void sudokusolver(vector<vector<char>> &board){
    helper(board,0,0);
}
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
    sudokusolver(board);
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