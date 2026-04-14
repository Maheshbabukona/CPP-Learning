/*
A board contains a word that can be constructed from sequentially adjacent cells -- either vertically or horizontally..
classic dfs search on 4 sides for each index.

For each index -- check 4 sides -- mark the cell as visited if its matching with its relavant index of target word..
On completing the target word length return true.. have the combination boolean of 4 sides -- finding it on any direction is positive.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
    bool dfs_helper(vector<vector<char>> &board, int i, int j, string &word, int idx){
        if(idx==word.size()) return true; // successfully reached end of the word -- all are matching return true;

        // boundaries & matching 
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!=word[idx]) return false;

        char temp = board[i][j];
        board[i][j]='#'; // mark visited
        bool found = dfs_helper(board,i-1,j,word,idx+1) ||
                     dfs_helper(board,i,j+1,word,idx+1) ||
                     dfs_helper(board,i+1,j,word,idx+1) ||
                     dfs_helper(board,i,j-1,word,idx+1);
        
        board[i][j]=temp; // backtrack -- unmark the visited.

        return found;
    }
public:
    bool exists(vector<vector<char>> &board, string word){
        int m = board.size(), n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dfs_helper(board,i,j,word,0)) return true;
            }
        }
        return false;
    }
};

int main(){
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCCED";
    Solution S;
    cout << "Does the word exist on the board? "<< ((S.exists(board,word)) ? "Yes" : "No");
}