/*
given array contains all elements appearing twice and only one number appearing once.
to find that -- we do xor.. cause xor of same elements is 0, unique elements is 1.
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    int singleNumber(vector<int> &nums){
        int res=0;
        for(int val: nums){
            res^=val;
        }
        return res;
    }
};

int main(){
    vector<int> nums = {4,1,2,1,2};
    Solution S;
    cout << "The unique number is: " << S.singleNumber(nums);
}