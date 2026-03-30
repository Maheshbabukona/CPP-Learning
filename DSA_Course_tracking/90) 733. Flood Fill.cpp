#include <iostream>
#include <vector>
using namespace std;

// similar to rotten oranges -- but this time -- all adjacent -- so dfs filling.
/*
Given a grid -- that contains integers -- each integer representing a color -- eg: 0,1 -- red, blue.
Goal is to paint with target color all those grids which are adjacent and equal to source grid lets say source grid is 0.. repeatedly color all adjacent grids with 0 to target color.

Approach:
    base condition: 
    1) boundaries
    2) grid!= source color -- need not paint this
    3) grid == target color -- while returning back you may be visiting already painted grids -- need not double paint.
    color the cell
    Now repeat the same for all 4 sides -- top, right, bottom, left
*/
class Solution{
    void dfs_painter(vector<vector<int>> &image, int i,int j, int newcolor, int origcolor){
        if(i<0 || j<0 || i>=image.size() || j>=image[0].size() || image[i][j]!=origcolor || image[i][j]==newcolor) return;
        image[i][j]= newcolor;
        dfs_painter(image,i-1,j,newcolor,origcolor);
        dfs_painter(image,i,j+1,newcolor,origcolor);
        dfs_painter(image,i+1,j,newcolor,origcolor);
        dfs_painter(image,i,j-1,newcolor,origcolor);
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs_painter(image,sr,sc,color,image[sr][sc]);
        return image;
    }
};

int main(){
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    int sr = 1,sc = 1, color = 2;
    Solution S;
    vector<vector<int>> res = S.floodFill(image,sr,sc,color);

    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[0].size();j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}