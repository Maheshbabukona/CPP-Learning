/*
approach - at each height calculate max area formed including that height, so height is fixed , but width changes. 
for each index width goes either sides till the hrights are greater.. 
so we stop as we find prev smaller and next greater. so width becomes width = r-l-1
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution{
public:
    int largestRectangleArea(vector<int>& heights){
        int n=heights.size();
        vector<int> r(n,-1);
        vector<int> l(n,-1);
        stack<int> s;

        // calculate next smaller element to find the boundary at index towards right
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && heights[s.top()]>=heights[i]) s.pop();
            if(s.empty()) r[i]=n; // here if no smaller element exist.. boundary becomes n
            else r[i]=s.top();

            s.push(i);
        }

        // empty the stack to reuse
        while(!s.empty()) s.pop();
        // calculate prev smaller element to find the boundary at index towards left
        for(int i=0;i<n;i++){
            while(!s.empty() && heights[s.top()]>=heights[i]) s.pop();
            if(s.empty()) l[i]=-1; // if no prev smaller boundary becomes -1
            else l[i]=s.top();

            s.push(i);
        }            

        int ans =0;
        for(int i=0;i<n;i++){
            int width =r[i]-l[i]-1;
            int curArea = heights[i]*width;
            ans = max(curArea, ans);
        }
        return ans;
    }
};

int main(){
    vector<int> heights = {2,1,5,6,2,3};
    Solution S;
    int result = S.largestRectangleArea(heights);
    cout << "Max area: "<< result;

}