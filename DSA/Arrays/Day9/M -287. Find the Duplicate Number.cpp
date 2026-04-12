/*
Use set to track all the integer values -- if you find something already present - return
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int findDuplicate(vector<int>& nums){
    unordered_set<int> s;
    for(int val: nums){
        if(s.find(val)!=s.end()){
            return val;
        }
        s.insert(val);
    }
    return -1;
}

int main(){
    vector<int> nums = {1,3,4,2,2};
    cout << "The dup is : " << findDuplicate(nums);
}