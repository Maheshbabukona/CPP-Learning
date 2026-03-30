#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>> & matrix, int target){
    for(int r =0;r<matrix.size();r++){
        if(matrix[r][0]<=target && target<=matrix[r][matrix[r].size()-1]){
            int st =0, end = matrix[r].size()-1;
            while(st<=end){
                int mid = st+(end-st)/2;
                if(target==matrix[r][mid]) return true;
                else if(target>matrix[r][mid]) st=mid+1;
                else end = mid-1;
            }
        }
    }
    return false;
}

int main(){
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 34;
    cout << searchMatrix(matrix,target)<<endl;
}