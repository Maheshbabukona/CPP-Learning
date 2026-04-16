/*
Array stalls = [1, 2, 8, 4, 9] -- contains the indexes where stalls to keep cows. K = number of cows.
Goal is to maximize the distance between cows and return the maximum distance.
So here we follow binary search in the range st=1 -- min distance between 2 cows.. end = stalls[max]-stalls[min] -- the farthest 2 stalls can be -- eg: if there are only 2 cows.

to be valid:
we track lastpos of the cow. and if the currentpos-lastpos>=mid(allowed distance) -- you place cows and update the lastpos to placed cow pos.
and anytime while iterating if you see that the cows placed are more than present -- return true. -- which meant -- cows are placed at safe distance and even more space is avl.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
    bool isvalid(vector<int> &stalls, int n, int mid, int k){
        int cows=1, lastpos=stalls[0];
        for(int i=1;i<n;i++){
            if(stalls[i]-lastpos>=mid){
                cows++;
                lastpos=stalls[i];
            }
            if(cows>=k) return true;
        }
        return false;
    }
public:
    int aggressiveCows(vector<int> &stalls, int k){
        int n=stalls.size();
        sort(stalls.begin(),stalls.end());
        int st=1, end = stalls[n-1]-stalls[0];
        int res=-1;

        while(st<=end){
            int mid=st+(end-st)/2;
            if(isvalid(stalls,n,mid,k)){
                res=mid;
                st=mid+1; // search for even higher distance.
            }
            else end=mid-1;
        }
        return res;
    }
};

int main(){
    vector<int> stalls = {1, 2, 8, 4, 9};
    int k=3;
    Solution S;
    cout << "Maximum distance between cows: " << S.aggressiveCows(stalls,k);
}