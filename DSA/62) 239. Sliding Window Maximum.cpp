// viable elements.
// should be part of cur window
// and prev elements should be greater than or equal to cur element -> 
// why.. less elements cannot become answer anyway.. we remove them..so that the front of the dq becomes the ans for  that window.

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution{
public:
    vector<int> maxSlidingWindow(vector<int> nums, int k){
        deque<int> dq;
        vector<int> res;
        // 1. Analyze the first window.
        for(int i=0;i<k;i++){
            while(dq.size()>0 && nums[dq.back()]<=nums[i]){ //element checking
                dq.pop_back();
            }
            dq.push_back(i);  // store index.
        } // by now we have the viable elements

        //2 . Sliding window for other windows.  
        // now that we have first window.. we can just iterate one by one for upcoming.. simultaneously remove non belonging elements from dq.

        for(int i=k;i<nums.size();i++){
            res.push_back(nums[dq.front()]); // as you remove non viable.. front element becomes ans for that window
            while(dq.size() && dq.front()<=i-k){ // index checking - remove non belonging from dq
                dq.pop_front();
            }

            while(dq.size()>0 && nums[dq.back()]<=nums[i]){ //element checking
                dq.pop_back();
            }
            
            dq.push_back(i);
        }
        res.push_back(nums[dq.front()]);
        return res;
    }
};

int main(){
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k =3;
    Solution S;
    vector<int> ans = S.maxSlidingWindow(nums,k);
    for(int val: ans){
        cout << val <<" ";
    }
}