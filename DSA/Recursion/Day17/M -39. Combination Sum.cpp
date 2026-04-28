/*
Goal - to find out all the combinations of cand -- whose sum is equal to target.

So for any element there are three options.
1) include it multiple times - include the same element multiple times to reach the target
2) doesnt include it - without including it skip to next index
3) include it but only once -- include the element - go to next index.

Here in our recursion
we use multiple inclusion -- staying at the same index -- subtracting the target -- multiple inclusion
for single inclusion -- the first case of multiple inclusion where an el is considered first time and no inclusion from next-- is single inclusion.
removing the added el and moving to next index -- no inclusion
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
    void combsum(vector<int> &candidates, int i, vector<int> &comb, vector<vector<int>> &ans, int target){
        if(target==0){
            ans.push_back(comb);
            return;
        }
        if(target<0 || i==candidates.size()) return; // overshoot on target sum or on index -- return 

        comb.push_back(candidates[i]);
        combsum(candidates,i,comb,ans,target-candidates[i]); // multiple inclusion
        comb.pop_back();
        combsum(candidates,i+1,comb,ans,target); // no inclusion
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target){
        vector<int> comb;
        vector<vector<int>> ans;
        combsum(candidates,0,comb,ans,target);
        return ans;
    }
};

int main(){
    vector<int> candidates = {2,3,5};
    int target = 8;
    Solution S;
    vector<vector<int>> res = S.combinationSum(candidates,target);
    for(int i=0;i<res.size();i++){
        for(int val: res[i]){
            cout << val << " ";
        }
        cout << endl;
    }
}