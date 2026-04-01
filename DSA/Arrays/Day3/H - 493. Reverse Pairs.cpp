/*
Given a array eg: [40,25,19,12,9,6,2] -- here we need to find the pairs where i<j and arr[i]>2*arr[j].
eg: {40,2},{40,6},{19,2} -- can be pairs.. {9,6},{12,6} -- these cant be.

So primary issue is -- sorting.. Here the array might not be sorted. 
if the array is sorted -- that would have been easy. 
Outer logic: 
so we divide using merge sort -- divide till we have 2 sorted arrays.. we compare both sides.. find the count of pairs.

Count pairs logic:
    Here we need i elements to be largest -- and j elements to be smallest.
    if there were a i and j where a[i]>2*a[j] and these arrays are sorted .. then all the elements before j can be part of possible pairs..
    so we iterate through i  -- 1st array.. check for possible js -- each time count cumulates.
    eg:
    a1 = [6,13,21,25] , a2 = [1,2,3,4,4,5,9,11,13].., cnt =0
    Here we iterate through a1. 
    1 -> 6 for 6 we check for all feasible js in a2 --> {1,2} --> cnt=2-- outside while loop till where the j goes --
    2-> 13 a2-->{1,2,3,4,4,5} cnt =6 here cnt cumulates --> cnt = cnt+ cur cnt -- 6 -- 6+2 = 8.
*/

#include <iostream>
#include <vector>
using namespace std;

class solution{
    void merge(vector<int> &nums, int st, int mid, int end){
        int i=st, j= mid+1;
        vector<int> temp;
        while(i<=mid && j<=end){
            if(nums[i]<=nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid){
            temp.push_back(nums[i]);
            i++;
        }
        while(j<=end){
            temp.push_back(nums[j]);
            j++;
        }
        for(int idx=0;idx<temp.size();idx++){
            nums[st+idx] = temp[idx];
        }
    }
    int countrevpairs(vector<int> &nums, int st, int mid, int end){
        int cnt = 0, j=mid+1;
        for(int i=st;i<=mid;i++){
            while(j<=end && nums[i]>2*nums[j]){
                j++;
            }
            cnt+=(j-(mid+1)); // cnt the j till its feasible.
        }
        return cnt;
    }

    int divideNcount(vector<int> &nums, int st, int end){
        if(st>=end) return 0;
        int mid = st+(end-st)/2;
        int cnt = 0;
        cnt+=divideNcount(nums,st,mid); // left division count
        cnt+=divideNcount(nums,mid+1,end); // right division count
        cnt+=countrevpairs(nums,st,mid,end);
        merge(nums,st,mid,end);
        return cnt;
    }
public:
    int reversePairs(vector<int>& nums){
        return divideNcount(nums,0,nums.size()-1);
    }
};

int main(){
    vector<int> nums = {40,25,19,12,9,6,2};
    solution S;
    cout << "Number of reverse Pairs possible: " << S.reversePairs(nums);
}