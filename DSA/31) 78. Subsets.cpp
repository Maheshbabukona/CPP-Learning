#include <iostream>
#include <vector>
using namespace std;

/*Goal to find out all the subset and adding them to a vector.

Think of this approach as a tree.. tree expands at each step at each element. 
At each element we have 2 choices to include the element or exclude it.. so to include we push_back.. 
to consider exclusion we pop_back and then continue.. 

*/

void getallsubsets(vector<int> &nums, vector<int> &ans, int i, vector<vector<int>> &allsubsets){
    if(i==nums.size()){
        allsubsets.push_back(ans); // push the vector ans to the result
        return;
    }
    //include 
    ans.push_back(nums[i]);
    getallsubsets(nums,ans,i+1,allsubsets);
    //exclude
    ans.pop_back();
    getallsubsets(nums,ans,i+1,allsubsets);
}

vector<vector<int>> subsets(vector<int> &nums){
    vector<vector<int>> allsubsets;
    vector<int> ans;
    getallsubsets(nums,ans,0,allsubsets);
    return allsubsets;
}

int main(){
    vector<int> nums = {1,2,3};
    vector<vector<int>> result = subsets(nums);
    cout << "[";
    for(int i=0;i<result.size();i++){
        cout << "[";
        for(int j=0;j<result[i].size();j++){
            cout << result[i][j];
            if(j < result[i].size()-1) cout << ",";
        }
        cout << "]";
        if(i<result.size()-1) cout << ",";
    }
    cout << "]";
}