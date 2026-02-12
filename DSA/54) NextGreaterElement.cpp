#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;

class Conceptual{
/*
eg: arr = [6,8,0,1,3] for this array.. at each index. find the next closest greater element. 
eg: for o at index 2 -> 1 at index 3 is the closest greater element.
so output = [8,-1,1,3,-1] --> if no element greater to right.. its -1
*/
public:
    vector<int> NextGreaterElement(vector<int> nums){
        stack<int> st;
        vector<int> ans(nums.size());
        // traverse from right to left... so the search space is easier
        for(int i=nums.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums[i]){
                st.pop();
            }
            if(st.size()==0) ans[i]=-1;
            else ans[i]=st.top();

            st.push(nums[i]);
        }
        return ans;
    }

    void printresult(vector<int> result){
        for(int val : result){
            cout << val << " ";
        }
        cout << endl;
    }
};

class Leetcode{

/*
Here there are 2 arrays nums1 = [4,1,2], nums2 = [1,3,4,2] given nums1 is subarray of nums2.

For every element of nums1 we need to find its next greater element for its existence in nums2. 

// key - find next greater element for each element for nums2 - have the mapping of each element and its next greater element
stored in a unordered map.. for each element of nums1 retrieve their relavant next greater element from the map and produce the output.
*/
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2){
        vector<int> ans;
        unordered_map<int,int> map;

        Conceptual objconc;
        vector<int> nums2nge = objconc.NextGreaterElement(nums2);

        for(int i=0;i<nums2.size();i++){
            map[nums2[i]]=nums2nge[i];
        }

        for(int val : nums1){
            ans.push_back(map[val]);
        }
        return ans; 
    }
// here.. we see in both directions right and left.. so we consider it as circular.. and traverse the entire array again.
// eg: arr=[1,2,1] output = [2,-1,2] for this we consider traversing.. in [1,2,1,1,2,1] and then we add them accordingly into stack.. but calculate the result only for first 3.

    vector<int> nextGreaterElement_circular(vector<int> nums3){
        int n=nums3.size();
        vector<int> ans_circular(n,-1);
        stack<int> st_circular;

        for(int i=2*n-1;i>=0;i--){
            int num=nums3[i%n];
            while(!st_circular.empty() && st_circular.top()<=num){
                st_circular.pop();
            }
            // calculate next greater from repeated elements stored stack.
            if(i<n){
                if(!st_circular.empty()) ans_circular[i]=st_circular.top();
            }
            st_circular.push(num); // this way you push the elements twice.
        }
        return ans_circular;
    }
};

int main(){
    Conceptual CS;
    vector<int> nums = {6,8,0,1,3};
    vector<int> result1 = CS.NextGreaterElement(nums);

    cout << "Conceptual Question\n";
    CS.printresult(result1);
    

    Leetcode ls1;
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};
    vector<int> result2 = ls1.nextGreaterElement(nums1,nums2);
    cout << "Leetcode 1\n";
    CS.printresult(result2);

    Leetcode ls2;
    vector<int> nums3 = {1,2,1};
    vector<int> result3 = ls2.nextGreaterElement_circular(nums3);
    cout << "Leetcode circular greater element\n";
    CS.printresult(result3);
}