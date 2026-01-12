#include <iostream>
#include <vector>
using namespace std;

int binarysearch(vector<int> &nums, int target){
    int start = 0, end = nums.size()-1;
    while(start<=end){
        int mid = start+ (end-start)/2;  // half value can go to negative -- overflow -> to prevent that we add start+half of value the index of median
        if (nums[mid]<target) start=mid+1;
        else if (nums[mid]>target) end = mid-1;
        else return mid;
    }
    return -1;
}

int recbinarysearch(vector<int> &nums, int target, int start, int end){
    if (start>end) return -1;
    int mid = start+(end-start)/2;
    if (nums[mid]==target) return mid;
    else if (nums[mid]>target) return recbinarysearch(nums,target,start,mid-1);
    else if(nums[mid]<target) return recbinarysearch(nums,target,mid+1,end);
}

int main(){
    vector<int> nums = {-1,0,3,4,5,9,12};
    int target = 12;
    cout << "target found at: " << binarysearch(nums, target);
    cout << "with recursion target found at: "<< recbinarysearch(nums,target, 0, nums.size()-1);
}