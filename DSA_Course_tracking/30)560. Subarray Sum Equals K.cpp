#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Goal to find the number of subarrays whose sum==target

// Normal brute force to calculate subarrays can be n3 timecomplexity.. but we can have 2 loops.. traverse j everytime.. for each i add the elements.. therfore calculate the subarray sum..
// Kind of optimal brute force.
int subarraysumbrute(vector<int> &nums, int &k){
    int count=0;
    int n=nums.size();
    for(int i=0;i<n;i++){
        int sum=0; 
        for(int j =i;j<n;j++){
            sum+=nums[j];
            if(sum==k) count ++;
        }
    }
    return count;
}
// using prefix sum -> we will have an array which is having sum of all the previous values.. so subarraysum(i,j)=ps[j]-ps[i-1]
int subarraysumoptimal(vector<int> &nums, int &k){
    int n=nums.size();
    int count =0;
    vector<int> ps(n,0);
    ps[0]=nums[0];
    for(int i=1;i<n;i++){
        ps[i]=nums[i]+ps[i-1];
    }
    unordered_map <int,int> m; // stores ps, frequency
    for(int j=0;j<n;j++){
        if(ps[j]==k) count++;
        int val = ps[j]-k; // from k=ps[j]-ps[i-1]
        if(m.find(val)!=m.end()) count+=m[val];
        if(m.find(ps[j])==m.end()) m[ps[j]]=1; // if prefix sum didnt exist-- initialize it.
        else m[ps[j]]++;
    }
    return count;
}
int main(){
    vector<int> nums = {1,1,1};
    int k=2;
    cout << subarraysumbrute(nums,k) << endl;
    cout << subarraysumoptimal(nums,k)<< endl;
}