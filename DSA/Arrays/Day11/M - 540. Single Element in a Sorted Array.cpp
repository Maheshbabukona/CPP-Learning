/*
An array contains only one unique element.
eg: {1,1,2,3,3,4,4,8,8} -- this makes it odd size.
An array is odd sized when case 1- odd+unique+odd case2- even+unique+even.
Goal is to find a mid thats unique.
3 base cases
1) - mid==0 index. then check mid+1 --> if unique - return mid
2) mid==nums.size()-1 then check mid-1 --> if unique -- return mid
3) Main basse -- its unique if nums[mid-1]!=nums[mid]!=nums[mid+1] -- return the mid

Now for cases 
1) Even+unique+even
if on the left if mid matches with its prev -- nums[mid-1]==nums[mid] --> it makes it even-matching el = odd --> so definitely unique exists on the same side.. so search on the same side
2) Odd+unique+odd
if on the left if mid matches with its prev -- nums[mid-1]==nums[mid] --> it nakes it odd- matching el = even --> so unique doesnt exists here so search other side.
*/

#include <iostream>
#include <vector>
using namespace std;

int singleNonDuplicate(vector<int>& nums){
    // single element arraay
    if(nums.size()==1) return nums[0];

    int st=0, end = nums.size()-1;
    while(st<=end){
        int mid = st+(end-st)/2;
        if(mid==0 && nums[mid]!=nums[mid+1]) return nums[mid];
        if(mid==nums.size()-1 && nums[mid-1]!=nums[mid]) return nums[mid];
        if(nums[mid-1]!=nums[mid] && nums[mid]!=nums[mid+1]) return nums[mid];

        if(mid%2==0){ // even size on the left
            if(nums[mid-1]==nums[mid]) end = mid-1; // search same side
            else st = mid+1;
        }
        else{
            if(nums[mid-1]==nums[mid]) st=mid+1; // search other side
            else end = mid-1;
        }
    }
    return -1;
}

int main(){
    vector<int> nums = {1,1,2,3,3,4,4,8,8};
    cout << "The unique element is: " << singleNonDuplicate(nums);
}