#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

/*using hashing
outer loop for a and hashing same as 2sum for b and c ⇒ except since its unique triplets.. 
store the triplets in vector, sort and then add to set. → convert to vector again and return*/

vector<vector<int>> threesumhashing(vector<int> &nums){
    int n = nums.size();
    set<vector<int>> uniquetriplets; // To store the unique triplets
    for(int i=0;i<n;i++){
        int target = -nums[i]; // a+b+c =0 -> b+c = -a(nums[i])
        set<int> s; // to track the elements inside after a;
        // from here its same as 2 sum
        for(int j=i+1;j<n;j++){
            int tofind = target - nums[j]; //b+c = -a => c = -a-b(nums[j])
            if(s.find(tofind)!=s.end()){
                vector<int> trip = {nums[i],nums[j],tofind}; // why we need array to.. specifically sort and then add to set
                sort(trip.begin(),trip.end());
                uniquetriplets.insert(trip);
            }
            s.insert(nums[j]);
            
        }
    }
    vector<vector<int>> ans(uniquetriplets.begin(),uniquetriplets.end());
    return ans;
}

/*  2 Pointer
Sort to avade duplicates, Outer loop iterates once has a( skip if duplicate) inside have a while loop first pointer from i+1 and another pointer at end.. 
if sum(nums[j]+nums[k]) == -nums[i] =⇒ add the triplet to ans. as you add increase the j value and k value to go for next elements.. 
also add j and k respectively if they find adjacent duplicates.*/

vector<vector<int>> threesum2pointer(vector<int> &nums){
    sort(nums.begin(),nums.end());
    int n = nums.size();
    vector<vector<int>> ans;
    for(int i=0;i<n-2;i++){
        if(i>0 && nums[i]==nums[i-1]) continue; // skips if duplicate
        int target =  -nums[i];
        int j=i+1,k=n-1;
        while(j<k){
            int sum =nums[j]+nums[k];
            if(sum==target){
                ans.push_back({nums[i],nums[j],nums[k]});
                while(j<k && nums[j]==nums[j+1]) j++;
                while(j<k && nums[k]==nums[k-1]) k--;
                j++,k--;
            }
            else if(sum<target) j++;
            else k--;
        }
    }
    return ans;
}
int main(){
    vector<int> nums = {-1,0,1,2,-1,-4};
    cout << "Triplets using hashing" << endl;
    cout << "[";
    vector<vector<int>> hashingresult = threesumhashing(nums);
    for(int i=0;i<hashingresult.size();i++){
        cout << "[";
        for(int j=0;j<hashingresult[i].size();j++){
            cout << hashingresult[i][j];
            if (j < hashingresult[i].size()-1) cout <<  ",";
        }
        cout << "]";

    }
    cout << "]" << endl;
    cout << "Result using 2 pointer approach \n";
    vector<vector<int>> twopointerresult = threesum2pointer(nums);
    cout << "[";
    for(int i=0;i<twopointerresult.size();i++){
        cout << "[";
        for(int j=0;j<twopointerresult[i].size();j++){
            cout << twopointerresult[i][j];
            if (j < twopointerresult[i].size()-1) cout <<  ",";
        }
        cout << "]";

    }
    cout << "]" << endl;
}