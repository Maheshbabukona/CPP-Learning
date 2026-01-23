#include <iostream>
#include <vector> 
using namespace std;

void helpermazerun(vector<vector<int>> &maze, int r, int c, string path, vector<string> &ans){
    // base conditions
    int n=maze.size();
    if(r<0 || c<0 || r>=n || c>=n || maze[r][c]==0 || maze[r][c]==-1){ // cell = 0 -> cannot visit. cell = -1 already visited.
        return;
    }

    if(r==n-1 && c==n-1){ // found the ans
        ans.push_back(path);
        return;
    }

    maze[r][c]=-1; // making a cell visited before going to next recursion

    // GFG expects path to be lexicographic --> D->L->R->U

    helpermazerun(maze,r+1,c,path+"D",ans); // going down
    helpermazerun(maze,r,c-1,path+"L",ans); // going left
    helpermazerun(maze,r,c+1,path+"R",ans); // going right
    helpermazerun(maze,r-1,c,path+"U",ans); // going up

    maze[r][c]=1; // backtrack - making a cell unvisited
}
vector<string> ratInMaze(vector<vector<int>> &maze){
    string path="";
    vector<string> ans;
    helpermazerun(maze,0,0,path,ans);
    return ans;
}
int main(){
    vector<vector<int>> maze = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    vector<string> result = ratInMaze(maze);
    cout << "[";
    for(int i=0; i<result.size(); i++){
        cout << result[i];
        if(i<result.size()-1) cout << ",";
    }
    cout << "]";
}