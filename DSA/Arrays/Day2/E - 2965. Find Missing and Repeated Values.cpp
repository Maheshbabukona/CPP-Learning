#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*
Goal -- given 2d array containing elements 1-n*n there exists a element 'a' which is repeated exactly twice. and a element 'b' which is missing.

for a -- use set -- if it repeats its 'a'.
for b --
expected sum = (n*n)*(n*n+1)/2 = actualsum-repeatedelement+missing element.
missing element = b = expectedsum-actualsum+repeatedelemenet(a)
*/

vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    unordered_set<int> s;
    int n = grid.size();
    vector<int> ans;
    int a,b;
    int actualsum=0,expectedsum;

    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            actualsum+=grid[i][j];
            if(s.find(grid[i][j])!=s.end()){
                a = grid[i][j];
                ans.push_back(a);
            }
            s.insert(grid[i][j]);
        }
    }
    expectedsum = (n*n)*(n*n+1)/2;
    b = expectedsum - actualsum + a;
    ans.push_back(b);

    return ans;
}

int main(){
    vector<vector<int>> grid = {{9,1,7},{8,9,2},{3,4,6}};
    vector<int> res = findMissingAndRepeatedValues(grid);
    cout << "Repeated val: " << res[0] << endl;
    cout << "Missing val: " << res[1] << endl;
}