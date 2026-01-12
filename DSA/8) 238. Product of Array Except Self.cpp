#include <iostream>
#include <vector>
using namespace std;

/*vector<int> bruteforce(vector<int> &nums){
    vector<int> res(nums.size(),1);

    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums.size(); j++) {
            if (i == j) continue;
            res[i] *= nums[j];
        }
    }

    nums = res;
    return nums;
}*/

vector<int> optimal(vector<int> &nums){
    vector<int> res(nums.size(),1);

    for(int i=1; i<nums.size();i++){
        res[i]*=res[i-1]*nums[i-1];
    }
    int suffix=1;
    for(int i=nums.size()-2;i>=0;i--){
        suffix*=nums[i+1];  // here we are multiplying next element with suffix -> why use extra variable as they are going to be changed.
        res[i]*=suffix;
        
    }
    nums=res;
}
int main(){
    vector<int> nums = {1,2,3,4};
    optimal(nums);
    for(int val : nums){
        cout << val << " ";
    }
    cout << endl;
    return 0;
}