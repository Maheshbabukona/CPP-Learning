// we follow swap prcoess.
// we swap cur element with next elements at each place.
#include <iostream>
#include <vector>
using namespace std;

void getperms(vector<int> &nums, int idx, vector<vector<int>> &ans){
    if(idx==nums.size()){
        ans.push_back(nums);
        return;
    }
    for(int i=idx;i<nums.size();i++){
        swap(nums[idx],nums[i]); // swap with other elements.
        getperms(nums,idx+1,ans); // to go to next index position.
        swap(nums[idx],nums[i]); // swap back.. Why as per first iteration.. every element at each index swaps itself.. as for next iteration.. every element at each index swaps with next element. and after that.. they should return back to orginal to apply perms.

    }
}

vector<vector<int>> permut(vector<int> &nums){
    vector<vector<int>> ans;
    getperms(nums,0,ans);
    return ans;
}

int main(){
    vector<int> nums = {1,2,3};
    vector<vector<int>> result = permut(nums);
    cout << "[";
    for(int i=0;i<result.size();i++){
        cout << "[";
        for(int j=0;j<result[i].size();j++){
            cout << result[i][j];
            if(j<result[i].size()-1) cout << ",";
        }
        cout << "]";
        if (i<result.size()-1) cout << ",";
    }
    cout << "]";
}