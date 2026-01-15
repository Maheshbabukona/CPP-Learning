#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// finding duplicate using sets
int findDuplicate_sets(vector<int> &nums){
    unordered_set<int> s;
    for(int i=0;i<nums.size();i++){
        if(s.find(nums[i])!=s.end()) return nums[i];
        s.insert(nums[i]);
    }
    return -1;
}

int main(){
    vector<int> nums = {1,3,4,2,2};
    cout << findDuplicate_sets(nums) << " :Result using sets" << endl;
}