// goal -> for any index finding the leftmax and rightmax. 
// and the boundary that defines the trappable water at that index is min(leftmax, rightmax). 
// so at that point water = min(leftmax,rightmax)-height[i]

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    // approach 1 - find lmax,rmax at each index store them in a array to access them at place
    int trap1(vector<int> height){
        int n=height.size();
        vector<int> lmax(n,0);
        vector<int> rmax(n,0);

        lmax[0]=height[0];
        rmax[n-1]=height[n-1];
        for(int i=1;i<n;i++){
            lmax[i]=max(lmax[i-1],height[i]);
        }
        for(int i=n-2;i>=0;i--){
            rmax[i]=max(rmax[i+1],height[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=min(lmax[i],rmax[i])-height[i];
        }
        return ans;
    }
// Two pointers. l and r.. find lmax, rmax at each iteration, the lesser one becomes the deciding factor.
    int trap2(vector<int> height){
        int n=height.size();
        int ans=0;
        int l=0,r=n-1;
        int lmax=0,rmax =0;

        while(l<r){
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);

            if(lmax<rmax){
                ans+=lmax-height[l];
                l++;
            }
            else{
                ans+=rmax-height[r];
                r--;
            }
        }
        return ans;
    }
};

int main(){
    vector<int> height ={4,2,0,3,2,5};
    Solution S;
    cout<< "Approach 1 - creating lmax,rmax arrays\n" << S.trap1(height)<< endl;
    cout << "Approach 2 - Two pointers\n"<< S.trap2(height)<< endl;
}
