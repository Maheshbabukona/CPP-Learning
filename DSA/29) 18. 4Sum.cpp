#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// same as three sum, we need 2 outer loops to find other 2 first numbers
vector<vector<int>> foursum(vector<int> &nums, int &target){
    int n = nums.size();
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;
    for(int i=0;i<n-3;i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        for(int j=i+1;j<n-1;j++){
            if(j>i && nums[j]==nums[j-1]) continue;
            int p=j+1,q=n-1;
            while(p<q){
                int sum = nums[i]+nums[j]+nums[p]+nums[q];
                if(sum==target){
                    ans.push_back({nums[i],nums[j],nums[p],nums[q]});
                    while(p<q && nums[p]==nums[p+1]) p++;
                    while(p<q && nums[q]==nums[q-1]) q--;
                    p++,q--;
                }
                else if(sum>target) q--;
                else p++;
            }
        }
    }
    return ans;
}

int main(){
    vector<int> nums= {1,0,-1,0,-2,2};
    int target = 0;
    vector<vector<int>> result = foursum(nums,target);
    cout << "[";
    for(int i=0;i<result.size();i++){
        cout << "[";
        for(int j=0;j<result[i].size();j++){
            cout << result[i][j];
            if (j < result[i].size()-1) cout <<  ",";
        }
        cout << "]";
    }
}