#include <iostream>
#include <vector>
using namespace std;

// int MaxRowSum(vector<vector<int>> matrix){
//     int maxrowsum = INT32_MIN;
//     for(int i=0;i<matrix.size();i++){
//         int currow_sum =0;
//         for(int j=0;j<matrix[i].size();j++){
//             currow_sum+=matrix[i][j];
//         }
//         maxrowsum=max(maxrowsum,currow_sum);
//     }
//     return maxrowsum;

// }

pair<int,int> MaxRowSum(vector<vector<int>> matrix){
    int maxrow_sum = INT32_MIN;
    int maxrow = -1;
    for(int r=0;r<matrix.size();r++){
        int currow_sum=0;
        for(int c=0;c<matrix[r].size();c++){
            currow_sum+=matrix[r][c];
        }
        if(currow_sum>maxrow_sum){
            maxrow_sum=currow_sum;
            maxrow=r;
        }
    }
    return {maxrow,maxrow_sum};
}

pair<int,int> MaxColSum(vector<vector<int>> matrix){
    int maxCol_sum = INT32_MIN;
    int maxcol =-1;
    for(int c=0;c<matrix[0].size();c++){
        int curcol_sum = 0;
        for(int r=0;r<matrix.size();r++){
            curcol_sum+=matrix[r][c];
        }
        if(curcol_sum>maxCol_sum){
            maxCol_sum=curcol_sum;
            maxcol=c;
        }
    }
    return {maxcol,maxCol_sum};
}

int diagonalsum(vector<vector<int>> matrix){
    int diagsum=0; // sum of first diagonal and second diagonal
    for(int i=0;i<matrix.size();i++){
        diagsum+=matrix[i][i];
        if(i!=matrix.size()-1-i) diagsum+=matrix[i][matrix.size()-1-i]; // common value to be added only once. so for eg: when size is 3 1,1 which is going to be added twice is added only once.
    }
    
    return diagsum;
}

int main(){
    vector<vector<int>> matrix = {{3,4,1},{1,3,4},{5,4,3}};
    cout << MaxRowSum(matrix).first+1 << " is the row with maximum sum of: "<< MaxRowSum(matrix).second << endl;
    cout << MaxColSum(matrix).first+1 << " is the Col with maximum sum of: "<< MaxColSum(matrix).second<< endl;
    cout << "Diagonal sum: "<< diagonalsum(matrix);
}