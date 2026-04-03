/*
3sum, 
run for loop for a, 
while -- using 2 pointer for b and c.. skip the duplicates.. add the unique ones to vector
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> threesum(vector<int> &nums){
    sort(nums.begin(),nums.end());
    int n = nums.size();
    vector<vector<int>> res;
    for(int i=0;i<n-2;i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        int target = -nums[i];
        int j = i+1, k = n-1;
        while(j<k){
            if(target == nums[j]+nums[k]){
                res.push_back({nums[i],nums[j],nums[k]});
                while(j>k && nums[j]==nums[j+1])j++;
                while(k<j && nums[k]==nums[k-1]) k--;
                j++;k--;
            }
            else if(target>nums[j]+nums[k]) j++;
            else k--;
        }
    }
    return res;
}

int main(){
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> ans = threesum(nums);

    cout << "3sum-- triplets equalling to zero:\n";
    for(int i = 0; i < ans.size(); i++){
        cout << "[ ";
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }  
        cout << "]";
    }
}