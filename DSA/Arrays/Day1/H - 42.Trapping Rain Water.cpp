/*
2 Pointer approach.
Iterate through left and right. find the leftmax, rightmax at each iteration. The min between leftmax and rightmax becomes the defining factor.
therefore. contained water gonna be -- lowermax - height[l/r]
*/
#include <iostream>
#include <vector>
using namespace std;
int trap(vector<int> &height){
    int n = height.size();
    int ans = 0;
    int l=0,r=n-1;
    int lmax=0,rmax =0;
    while(l<r){
        lmax = max(lmax,height[l]);
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

int main(){
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "Trappable water: " << trap(height);
}