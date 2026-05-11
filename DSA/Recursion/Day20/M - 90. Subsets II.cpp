/*
Find the subsets of an array -- but this time we need unique

For any element it has 2 options - include/exclude -- but while we exclude we do not want its duplicate to take it place and cause a final duplicate subset
--> so if we exclude a element -- we exclude all its duplicates and pass to next unique instance --> for this we sort
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution{
    void uniquesubsets(vector<int> nums, int i, vector<int> &subset, vector<vector<int>> &allsubsets){
        if(i==nums.size()){
            allsubsets.push_back(subset);
            return;
        }

        subset.push_back(nums[i]); // include case
        uniquesubsets(nums,i+1,subset,allsubsets);
        subset.pop_back(); // exclude case
        int idx = i+1;
        while(idx<nums.size() && nums[idx]==nums[idx-1]){
            idx++;
        }
        uniquesubsets(nums,idx,subset,allsubsets);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums){
        sort(nums.begin(),nums.end());
        vector<int> subset;
        vector<vector<int>> allsubsets;
        uniquesubsets(nums,0,subset,allsubsets);
        return allsubsets;
    }
};
int main(){
    vector<int> nums = {1,2,2};
    Solution S;
    vector<vector<int>> result = S.subsetsWithDup(nums);
    cout << "[";
    for(int i=0;i<result.size();i++){
        cout << "[";
        for(int j=0;j<result[i].size();j++){
            cout << result[i][j];
            if(j < result[i].size()-1) cout << ",";
        }
        cout << "]";
        if(i<result.size()-1) cout << ",";
    }
    cout << "]";
}