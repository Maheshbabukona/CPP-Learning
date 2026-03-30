/*
kadanes -- to calculate maximum sum possible in a subarray -- make the sum=0. if it goes to zero. 
having 0 is better than having negative.
*/
#include <iostream>
#include <vector>
using namespace std;

int maxSubArray_sum(vector<int> &nums){
    int maxsum = INT32_MIN;
    int cursum = 0;
    for(int i=0;i<nums.size();i++){
        cursum+=nums[i];
        maxsum = max(maxsum, cursum);

        if(cursum<0) cursum =0;
    }
    return maxsum;
}

int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << "Max sum from a subarray possible: " << maxSubArray_sum(nums);
}