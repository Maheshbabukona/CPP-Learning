/*
Consider 3 ranges -- 
0-low -- for 0s
low-mid -- for 1s
mid-high for 2s

start from mid=0,low=0, high =n-1. as you iterate if its 0 - swap with low, if its 2 swap with high, if its 1 leave as is.
*/
#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector<int>& nums){
    int mid=0,low=0,high =nums.size()-1;

    while(mid<=high){
        if(nums[mid]==0){
            swap(nums[mid],nums[low]);
            mid++;
            low++;
        }
        else if(nums[mid]==1) mid++;
        else{
            swap(nums[mid],nums[high]);
            high--; // why not mid++ -- since swapped element is from right and unseen
        }
    }
}

int main(){
    vector<int> nums = {2,0,2,1,1,0};
    cout << "After sorting: ";
    sortColors(nums);
    for(int val: nums){
        cout << val << " ";
    }
}