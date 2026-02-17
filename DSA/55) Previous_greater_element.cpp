#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class GFG{
public:
    vector<int> preGreaterEle(vector<int> nums){
        stack<int> st;
        vector<int> ans(nums.size(),-1);

        for(int i=0;i<nums.size();i++){
            while(!st.empty() && st.top()<=nums[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i]=st.top();
            }

            st.push(nums[i]);
        }

        return ans;
    }
};

int main(){
    vector<int> nums = {10, 4, 2, 20, 40, 12, 30};
    GFG sgfg;
    vector<int> ans = sgfg.preGreaterEle(nums);
    for(int val: ans){
        cout << val << " "; 
    }
    cout << endl;
}