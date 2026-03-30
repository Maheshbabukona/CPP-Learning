#include <iostream>
#include <vector>
using namespace std;

void getuniquesubsets(vector<int> &nums, vector<int> &ans, int i, vector<vector<int>> &allsubsets){
    if(i==nums.size()){
        allsubsets.push_back(ans);
        return;
    }
    ans.push_back(nums[i]);
    getuniquesubsets(nums,ans,i+1,allsubsets);
    ans.pop_back();
    // duplication happens when we include the same element thats excluded.. so when an element is excluded we check the next elements and skip until the next is unique
    int idx=i+1;
    while(idx<nums.size() && nums[idx]==nums[idx-1]){
        idx++;
    }
    getuniquesubsets(nums,ans,idx,allsubsets);
}
vector<vector<int>> subsets(vector<int> &nums){
    vector<vector<int>> allsubsets;
    vector<int> ans;
    getuniquesubsets(nums,ans,0,allsubsets);
    return allsubsets;
}

int main(){
    vector<int> nums = {1,2,2};
    vector<vector<int>> result = subsets(nums);
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