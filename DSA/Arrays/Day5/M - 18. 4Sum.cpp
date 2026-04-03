/*
4 sum, 
a, b - two for loops,
c, d- two pointer
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> foursum(vector<int> &nums, int target){
    int n=nums.size();
    sort(nums.begin(),nums.end());
    vector<vector<int>> res;
    for(int i=0;i<n-3;i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        for(int j=i+1;j<n-1;j++){
            if(j>i+1 && nums[j]==nums[j-1]) continue;

            int p=j+1,q = n-1l;
            while(p<q){
                long long sum = (long long)nums[i]+nums[j]+nums[p]+nums[q];
                if(target==sum){
                    res.push_back({nums[i],nums[j],nums[p],nums[q]});
                    while(p<q && nums[p]==nums[p+1]) p++;
                    while(p<q && nums[q]==nums[q-1]) q--;
                    p++;q--;
                }
                else if(target<sum) q--;
                else p++;
            }
        }
    }
    return res;
}

int main(){
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;
    vector<vector<int>> ans = foursum(nums,target);

    cout << "3sum-- triplets equalling to zero:\n";
    for(int i = 0; i < ans.size(); i++){
        cout << "[ ";
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }  
        cout << "]";
    }
}