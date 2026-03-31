/*
Moore's algorithm - if an element exists more than n/2 times. its freq>0 even if its cancelled out on its non existence.
eg: each time it exists and equals freq++, if it doesnt freq--.. at the end its freq>0
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int majorityElement(vector<int> &nums){
        int candidate = -1;
        int freq = 0;
        for(int val: nums){
            if(freq==0){
                candidate= val;
                freq=1;
            }
            else if(candidate == val) freq++;
            else freq--;
        }
        return candidate;
    }
};

int main(){
    vector<int> nums = {2,2,1,1,1,2,2};
    Solution S;
    cout << "The majority Element: " << S.majorityElement(nums);
}