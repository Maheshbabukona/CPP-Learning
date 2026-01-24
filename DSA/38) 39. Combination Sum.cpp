/* goal is to find the combs that are equal to target

3 cases 
1) multiple times inclusion - same element is added multiple times till it equals to target
2) single time inclusion - a element is included.. it skips to next index and adds on until it either reaches end or equals/oversteps target
3) no inclusion at all - skips to next element. 

// here to optimize and decrease the number of branches

consider this 
1) recursion(adding the element and staying at the same index) -- mutliple inclusion
2) recursion(skipping the element and moving to next index) -- no inclusion
3) recursion(adding the element and staying) -> recursion(skipping the stayed element and moving ) --- single inclusion
*/

#include <iostream>
#include <vector>
using namespace std;

void combsum(vector<int> &cand, int i, vector<int> &comb, vector<vector<int>> &ans, int tar){// helper for below
    if(tar==0){
        ans.push_back(comb);
        return;
    }
    if(tar<0 || i==cand.size()) return;

    comb.push_back(cand[i]);
    combsum(cand,i,comb,ans,tar-cand[i]);
    comb.pop_back();
    combsum(cand, i+1, comb,ans, tar);
}

vector<vector<int>> combinationSum(vector<int> candidates, int target){
    vector<vector<int>> ans;
    vector<int> comb;
    combsum(candidates, 0, comb, ans, target);
    return ans;
}
int main(){
    vector<int> candidates={2,3,6,7};
    int target =7;
    vector<vector<int>> result = combinationSum(candidates, target);
    cout << "[";
    for(int i=0;i<result.size();i++){
        cout << "[";
        for(int j=0;j<result[i].size();j++){
            cout << result[i][j];
            if(j<result[i].size()-1) cout << ",";
        }
        cout << "]";
        if (i<result.size()-1) cout << ",";
    }
    cout << "]";
}