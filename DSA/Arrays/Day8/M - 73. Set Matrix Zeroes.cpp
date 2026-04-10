/*
In any matrix - on encounter of 0 -- mark its entire row, col to 0
Approach --
Step1 - traverse the first row, col - if any zero -- have a flag marking its 0 bool row0,col0
Step2 - for inner matrix - if you encounter any zero -- mark its first col,row to 0 -- why ? -- firstcol,row is accessible to entire row,col -- to mark them entirely as 0
Step3 - Based on first col0, first row0 -- mark every element in the row/col to 0
Step4 --Now after inner matrix is done -- mark 0s if the flag is true for row/col accordingly

Q -- why not mark the entire row,col to zeros as we encounter 0 anywhere -- we would be seeing unneccessary 0s resulting in zeros in entire matrix.
*/

#include <iostream>
#include <vector>
using namespace std;

void setZeroes(vector<vector<int>>& matrix){
    int m=matrix.size(), n = matrix[0].size();
    bool row0= false, col0= false;

    // identify 0s in row0,col0 -- flag them
    for(int j=0;j<n;j++){
        if(matrix[0][j]==0) row0=true;
    }
    for(int i=0;i<m;i++){
        if(matrix[i][0]==0) col0=true;
    }

    // inner matrix
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(matrix[i][j]==0){
                matrix[0][j]=0;
                matrix[i][0]=0;
            }
        }
    }

    // based on marked first row, first col zeros -- mark their entire col, row to 0s
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(matrix[0][j]==0 || matrix[i][0]==0) matrix[i][j]=0;
        }
    }

    // now as per flag -- make first row,col to 0s
    if(row0){
        for(int j=0;j<n;j++) matrix[0][j]=0;
    }
    if(col0){
        for(int i=0;i<m;i++) matrix[i][0]=0;
    }
}


int main(){
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    setZeroes(matrix);
    cout << "After setting out zeros:\n";
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

