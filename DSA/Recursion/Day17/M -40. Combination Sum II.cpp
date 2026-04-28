/*
The only difference between previous is no multiple inclusion and no duplicates.

APproach.
Sort the array before recursion. Now iterate in for loop -- skip the duplicates and for each el - its either inclusion or no inclusion.
inclusion - - target-el and i+1, no inclusion - pop_back() the added el
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
    void uniqcombsum(vector<int> &candidates, int start, vector<int> &uniqcomb, vector<vector<int>> &ans, int target){
        if(target==0){
            ans.push_back(uniqcomb);
            return;
        }
        for(int i=start;i<candidates.size();i++){
            if(i>start && candidates[i]==candidates[i-1]) continue; // skip duplicates
            if(target<0) break; // over shoot

            uniqcomb.push_back(candidates[i]);
            uniqcombsum(candidates,i+1,uniqcomb,ans,target-candidates[i]);
            uniqcomb.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
        sort(candidates.begin(),candidates.end());
        vector<int> uniqcomb;
        vector<vector<int>> ans;
        uniqcombsum(candidates,0,uniqcomb,ans,target);
        return ans;
    }
};

int main(){
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    Solution S;
    vector<vector<int>> res= S.combinationSum2(candidates,target);
    for(int i=0;i<res.size();i++){
        for(int val: res[i]){
            cout << val << " ";
        }
        cout << endl;
    } 
}