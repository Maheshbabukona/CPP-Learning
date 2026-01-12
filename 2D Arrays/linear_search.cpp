#include <iostream>
#include <vector>
using namespace std;

pair<int,int> linear_search(vector<vector<int>> matrix, int key){
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            if(matrix[i][j]==key) return {i,j};
        }
    }
    return {-1,-1};
}
int main(){
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
    int key =5;
    
    if (linear_search(matrix,key).first!=-1) cout << key << " is found at: [" << linear_search(matrix,key).first << "," << linear_search(matrix,key).second << "]" << endl;
    else cout << key << " Not found" << endl;
     
    
}