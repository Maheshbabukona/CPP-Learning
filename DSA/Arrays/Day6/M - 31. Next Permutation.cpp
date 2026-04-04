/*
goal -- find the next lexicographical permutation.
eg: [1 3 5 4 3 2 1] -- [1 4 1 2 3 3 5]

Step1 - Find the pivot -- which is having elements ascending order on the left to it and elements descending order right to it.
Step2 -- 
Case 1 - if pivot is still -1. 
    the array is in descending order.
    reverse the array
Case 2 - find the next greater element for the pivot  -- swap with it.
Step3 - reverse the array next to pivot pos-- which is in descending -- to make it ascending.
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution{
    void reverse(vector<int> &nums, int i, int j){
        while(i<=j){
            swap(nums[i],nums[j]);
            i++;j--;
        }
    }
public:
    void nextPermutation(vector<int>& nums){
        int n = nums.size();
        int pivot = -1;
        // find the pivot
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                pivot = i;
                break;
            }
        }
        if(pivot==-1){ // array is in descending order -- reverse it
            reverse(nums,0,n-1);
            return;
        }
        for(int i=n-1;i>=0;i--){ // find the next greater element.
            if(nums[i]>nums[pivot]){
                swap(nums[i],nums[pivot]);
                break;
            }
        }
        reverse(nums,pivot+1,n-1); // reverse the elements to the right of pivot pos
    }
};

int main(){
    vector<int> nums = {1,3,5,4,3,2,1};
    Solution S;
    S.nextPermutation(nums);
    cout << "The next perm: ";
    for(int val: nums){
        cout << val << " ";
    }
}