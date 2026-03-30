#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> findMissingandRepeatedValues(vector<vector<int>> &grid){
    unordered_set <int> s;
    vector<int> ans;
    int n = grid.size();
    int a,b;
    int actualsum=0, expectedsum;
    // for duplicate element we are traverse, add the elements to set and see if anything is repeated.
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){ // square matrix so matrix.size()=matrix[0].size()
            actualsum+=grid[i][j];
            if(s.find(grid[i][j])!=s.end()){ // checking if the value is already existing in set.
                a = grid[i][j]; // a is going to be the duplicate value
                ans.push_back(a);
            }
            s.insert(grid[i][j]);
        }
    }
    // by now we have the element thats repeated.

    /* for missing element.. we are going to follow total sum in range approach.
     so if elements are in range 1-n*n -> total sum of elements = n(n+1)/2 => (n*n)(n*n+1)/2 
     ==> expected sum = actualsum-a(duplicate element)+b(missing element) => b=expectedsum-actualsum+a
    */

    expectedsum = (n*n)*(n*n+1)/2;
    b = expectedsum-actualsum+a;
    ans.push_back(b);
    return ans;
}

int main(){
    vector<vector<int>> grid = {{9,1,7},{8,9,2},{3,4,6}};
    for(int val : findMissingandRepeatedValues(grid)){
        cout << val << " ";
    }
}