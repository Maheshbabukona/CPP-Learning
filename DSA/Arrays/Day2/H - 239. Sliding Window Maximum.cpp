#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k){
    int n = nums.size();
    deque<int> dq;
    vector<int> ans;

    // first window
    for(int i=0;i<k;i++){
        while(dq.size()>0 && nums[dq.back()]<=nums[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }

    // by now max of first window is on front
    // iterate one at a time.. till n remove elements that are not from window-- previousones.. and the elements which are less too --non viable
    for(int i=k;i<n;i++){
        ans.push_back(nums[dq.front()]);
        while(dq.size()>0 && dq.front()<=i-k){// index check -- remove which dont belong
            dq.pop_front();
        }
        while(dq.size()>0 && nums[dq.back()]<=nums[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    ans.push_back(nums[dq.front()]);
    return ans;
}

int main(){
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k =3;
    vector<int> res = maxSlidingWindow(nums,k);
    for(int val: res){
        cout << val << " ";
    }
}