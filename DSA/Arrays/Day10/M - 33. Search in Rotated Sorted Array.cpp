/*
Consider eg:[1,2,3,4,5,6] -- lets say after rotation it is [6,5,1,2,3,4] -- here elements left to 1 are not sorted and elements right to 1 are sorted.

There always exist a subarray that is sorted. -> Use binary search on that sorted.
Appraoch --
Check if its left sorted
i yes -- confirm if target is in this left sorted range between st and mid. if yes -- continue binary search in this range.
if no -- target lies in non sorted right -- move the st to mid+1 -- find the sorted subarray in that range

If its right sorted 
if yes -- confirm range -- continue binary search
if no -- move the end -- find the sorted in left
*/

#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> &nums, int target){
    int st=0, end = nums.size()-1;
    while(st<=end){
        int mid = st+(end-st)/2;
        if(nums[mid]==target) return mid;
        if(nums[st]<=nums[mid]){ // left array is sorted
            if(nums[st]<=target && target<=nums[mid]){
                end = mid-1;
            }
            else st = mid+1;
        }
        else{
            if(nums[mid]<=target && target<=nums[end]){
                st = mid+1;
            }
            else end = mid-1;
        }
    }
    return -1;
}

int main(){
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    cout << "The target is found at index: " << search(nums,target);
}