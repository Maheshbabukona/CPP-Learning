/*
for each index -- calculate left product and right product

To calculate left product -- forward pass and product res[i]=res[i-1]*nums[i-1]
To calculate right product -- backward pass -- have a suffix that multiplies nums --stores it as suffix -- let it multiply with current res.
suffix* = nums[i+1]
res[i]* = suffix
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums){
    vector<int> res(nums.size(),1);
    // forward pass
    for(int i=1;i<nums.size();i++){
        res[i]=res[i-1]*nums[i-1];
    }
    // backward pass
    int suffix=1;
    for(int j=nums.size()-2;j>=0;j--){
        suffix*=nums[j+1];
        res[j]*=suffix;
    }

    return res;
}

int main(){
    vector<int> nums = {1,2,3,4};
    vector<int> ans = productExceptSelf(nums);
    cout << "Product array: \n";
    for(int val: ans){
        cout << val << " ";
    }
}