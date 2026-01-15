#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/* In hashmaps search is constant... we iterate only once.. now as we have the first element.. the second element should be:
complement of target and num -> target - nums[i] .. we search for that in the map.. if it does exist we are going to return.. 
so as we need indexes of the values.. we are going to store value as key and index as pair.. as we go.*/

vector<int> twosum(vector<int> &nums, int &target){
    unordered_map<int,int> hashmap;
    for(int i=0;i<nums.size();i++){
        int complement = target - nums[i];
        if(hashmap.count(complement)) return {i,hashmap[complement]};
        hashmap[nums[i]]=i;
    }
    return {};
}

int main(){
    vector<int> nums= {2,11,7,15};
    int target = 9;
    for (int val : twosum(nums,target)){
        cout << val << " ";
    
    }
}