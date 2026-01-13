#include <iostream>
#include <vector>
using namespace std;

/*Rules: Arrays are sorted both horizontally and vertically but there isnt any rule like first element of row is greater than last element of prev row.. can/ cannot be… But we know for sure that least element is at matrix[0][0] and largest element is at matrix[m-1][n-1].. we consider the range.. now we assume either right upper corner element or lower left corner element as mid.. why ? only these 2 elements have only 2 traversal routes.. either left for lower elements and down for greater elements for right upper corner mid.. ⇒ matrix[0][n-1].
And consider cur r = 0, c = n-1
As we consider we check.. if target < matrix[r][c] ⇒ we dont need the col.. so c - -; and of target > matrix[r][c] ⇒ we search in that col.. there r++.
*/

bool searchMatrix(vector<vector<int>> &matrix, int target){
    int m = matrix.size(), n = matrix[0].size();
    int r = 0, c = n-1; // index/coordinates of upper right corner element which is going to be our mid.
    
    while(r<m && c>=0){
        if(target == matrix[r][c]) return true;
        else if(target < matrix[r][c]) c--; // we dont the col where values are even greater than greater mid.
        else r++; // if target > mid element.. then the element can be in the col.. we iterate by incrementing the row and check,
    }
    return false;
}

int main(){
    vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int target = 5;
    cout << searchMatrix(matrix, target);
}