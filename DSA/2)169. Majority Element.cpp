/*
Moore's alg intuition:
if an element with freq > n/2 exist. then the element exists even if you cancel out combined freq of every other element.
*/

#include <iostream>
#include <vector>
#include <algorithm> // required for sort function.
using namespace std;
int moores_maxfrequency(vector<int> nums){
    int candidate = -1;
    int freq =0;
    for (int val: nums){
        if (freq==0){
            candidate=val;
            freq=1;
        }
        else if(candidate==val) freq++; // we got to add freq... only if freq is not zero.
        else freq--;
    }
    return candidate;
}

int brute(vector<int> & nums){
    for(int val:nums){
        int frequency=0;
        for(int el:nums){
            if (val==el){
                frequency++;
            }
        }
        if (frequency>nums.size()/2) return val;
    }
    return 0;

}
int optsort(vector<int> nums){
    sort(nums.begin(),nums.end());
    int ans = nums[0];
    for (int i =1; i<nums.size()-1; i++){
        int freq;
        if (nums[i]==nums[i-1]) freq++;
        else{
            freq=1;
            ans = nums[i];
        }
        if (freq>nums.size()/2) return ans;
    }
}

int main(){
    vector<int> nums = {2,2,1,1,1};
    cout << "brute force: " << brute(nums) << endl;
    cout << "opt using sort: " << optsort(nums) << endl;
    cout << "moore: "<< moores_maxfrequency(nums) << endl;
}
