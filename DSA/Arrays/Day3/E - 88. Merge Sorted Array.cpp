#include <iostream>
#include <vector>
using namespace std;

/*
Given nums1(m+n) -- here only m cells are filled with numbers, nums2(n)
both num1(->m) and nums2(n) are sorted.. merge both of them into nums1 -- sorted.
so instead of replacing filled ones.. place the unfilled ones with larger between two. -- fill from backwards
*/
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
    int i=m-1,j=n-1,cur = m+n-1;
    while(j>=0){
        if(i>=0 && nums1[i]>=nums2[j]){
            nums1[cur]= nums1[i];
            i--;
            cur--;
        }
        else{
            nums1[cur]=nums2[j];
            j--;
            cur--;
        }
    }
}

int main(){
    int m = 3;
    int n = 3;
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    merge(nums1,m,nums2,n);
    for(int val: nums1){
        cout << val << " ";
    }
}