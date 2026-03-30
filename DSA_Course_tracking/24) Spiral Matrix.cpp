#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix){
    int m = matrix.size(), n = matrix[0].size();
    int srow=0,scol=0,erow=m-1,ecol =n-1;
    vector<int> ans;
    while(srow<=erow && scol<=ecol){
        for(int j=scol;j<=ecol;j++){ // Pushing top row elements row const, col iterates
            ans.push_back(matrix[srow][j]);
        }
        for(int j=srow+1;j<=erow;j++){ //pushing right col elements -> col constant, row iterates.
            ans.push_back(matrix[j][ecol]);    
        }
        for(int j=ecol-1;j>=scol;j--){ // pushing bottom row elements -> row const and col iterates.
            if(srow==erow) break; // when its reading already read row twice.. break
            ans.push_back(matrix[erow][j]);
        }
        for(int j=erow-1;j>=srow+1;j--){ // pushing left col elements -> col const and row iterates.
            if(scol==ecol) break; // when its reading same col twice break.
            ans.push_back(matrix[j][scol]);
        }
        srow++,scol++,erow--,ecol--;
    }
    return ans;
}

int main(){
    vector<vector<int>> matrix ={{1,2,3},{4,5,6},{7,8,9}} ;
    for(int val: spiralOrder(matrix)){
        cout << val << " ";
    }
    cout << endl;
}