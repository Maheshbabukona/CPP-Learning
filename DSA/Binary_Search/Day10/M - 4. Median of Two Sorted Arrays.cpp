/*
There are 2 arrays nums1,nums2 - sorted. Find the median of the sorted arrays --
everything comes down to finding the right length of l1 on the left and on the right.

So run a binary search on the range of elements of nums1 to be used on the left..
For every range -- check if its valid range - if its valid
for total even case -- median = max(left)+min(right)/2
for odd case -- (since we choose more on the left ) -- median = max(left)
*/

#include <iostream>
#include <vector>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
    int n1=nums1.size();
    int n2 = nums2.size();
    if(n1>n2) return findMedianSortedArrays(nums2,nums1); // to run binary search on shorter array

    int st = 0, end = n1;
    int left = (n1+n2+1)/2; // Number of elements on the left. +1 -- to have more elements on the left
    while(st<=end){
        int mid1 = st+(end-st)/2;
        int mid2 = left-mid1;

        int l1=INT32_MIN, l2= INT32_MIN;
        int r1 = INT32_MAX, r2 = INT32_MAX;

        // assign l1,l2,r1,r2
        if(mid1<n1) r1 = nums1[mid1];
        if(mid2<n2) r2 = nums2[mid2];
        if(mid1-1>=0) l1 = nums1[mid1-1];
        if(mid2-1>=0) l2 = nums2[mid2-1];

        // check if its valid
        if(l1<=r2 && l2<=r1){
            if((n1+n2)%2==1) return max(l1,l2); // odd case --- more elements on the left -- median is on theleft.
            return (double)(max(l1,l2)+min(r1,r2))/2.0; // even case -- max(left)+min(right)/2
        }
        else if(l1>r2) end=mid1-1; // we need lesser of nums1 on the left -- choosing something smaller than mid
        else st = mid1+1;
    }
    return 0;
}

int main(){
    vector<int> nums1 = {1,2,3,4,9,11};
    vector<int> nums2 = {7,12,14,15};

    cout << "Median of two: " << findMedianSortedArrays(nums1,nums2);
}