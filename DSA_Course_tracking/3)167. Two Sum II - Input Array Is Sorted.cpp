// 2 pointer approach

#include <iostream>
#include <vector>
using namespace std;

vector<int> brute_pair(vector<int> & nums, int k){
    vector<int> ans;
    for(int i=0; i<nums.size()-1; i++){
        for (int j=i+1; j<nums.size();j++){
            if (nums[i]+nums[j]==k){
                ans.push_back(i);
                ans.push_back(j);
            }
        }
    }
    return ans;
}
vector<int> twopointer(vector<int> & nums, int k){
    vector<int> ans;
    int i=0,j=nums.size()-1;
    while(i<j){
        if (nums[i]+nums[j]==k){
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
        else if((nums[i]+nums[j])>k) j-=1;
        else i+=1;
    }
}

int main(){
    vector<int> nums = {2,7,11,15};
    int k = 13;
    vector<int> ans = brute_pair(nums,k);
    cout << "Brute"<< " ";
    for (int val : ans){
        cout << val << " ";
    }
    cout << endl;
    vector<int> optans = twopointer(nums,k);
    cout << "2pointer ";
    for (int val: ans){
        cout << val << " ";
    }
}