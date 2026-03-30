#include <iostream>
#include <vector>
using namespace std;

int singleNonDuplicate(vector<int>& nums){
    int n = nums.size();
    if (n==1) return nums[0];
    int st =0,end=n-1;
    while(st<=end){
        int mid = st+(end-st)/2;
        if(nums[mid]==0 && nums[mid]!=nums[mid+1]) return nums[mid];
        if(nums[mid]==n-1 && nums[mid-1]!=nums[mid]) return nums[mid];

        if(nums[mid-1]!=nums[mid] && nums[mid]!=nums[mid+1]) return nums[mid];
        // If unique element exists nums length is odd.
        if (mid%2==0){ // left side we have even number of elements.. and we remove the mid matching el, so even - matching el = odd -> here exists the unique element
            if(nums[mid-1]==nums[mid]) end=mid-1;
            else st=mid+1;   
        }
        else{ // left side odd number of elements, if we remove matching el then no. if el become even on left so search on other side.
            if(nums[mid-1]==nums[mid]) st=mid+1;
            else end =mid-1;
        }
    }
    return -1;

}

int main(){
    vector<int> nums = {1,1,2,3,3,4,4,8,8};
    cout << "unqiue element is " << singleNonDuplicate(nums)<< endl;
}