/*
Merge sort - divide and merge
*/

#include <iostream>
#include <vector>
using namespace std;

class MergeSort{
    void merge(vector<int> &nums, int st, int mid, int end){
        vector<int> temp;
        int i=st, j=mid+1;
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
            nums[st+idx]=temp[idx];
        }
    }

    void divide(vector<int> &nums, int st, int end){
        if(st>=end) return;
        int mid = st+(end-st)/2;
        divide(nums,st,mid);
        divide(nums,mid+1,end);
        merge(nums,st,mid,end);
    }
public:
    vector<int> sortArray(vector<int>& nums){
        divide(nums,0,nums.size()-1);
        return nums;
    }
};

int main(){
    vector<int> nums = {5,2,3,1};
    MergeSort Sort;
    vector<int> sorted_res = Sort.sortArray(nums);
    for(int val: sorted_res){
        cout << val << " ";
    }
}