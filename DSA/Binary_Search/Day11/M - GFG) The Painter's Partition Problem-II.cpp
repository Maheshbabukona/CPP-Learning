/*
Same as Allcotion problem .. the only change here can be..
The st -- here is the maxboard size present.. why -- for any painter the minimum board size can be max board size avl or else it would be greater..
so st = max(boards)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
    bool isValid(vector<int> &arr, int n, int mid, int k){
        int p=1, boards=0;
        for(int i=0;i<n;i++){
            if(arr[i]>mid) return false;

            if(boards+arr[i]<=mid){
                boards+=arr[i];
            }
            else{
                p++;
                boards=arr[i];
            }
        }
        return p>k ? false : true;
    }
public:
    int minTime(vector<int>& arr, int k){
        int n=arr.size();
        int sum=0, maxVal = INT32_MIN;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            maxVal = max(maxVal, arr[i]);
        }
        int st=maxVal, end = sum;
        int res=-1;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(isValid(arr,n,mid,k)){
                res=mid;
                end=mid-1;
            }
            else{
                st=mid+1;
            }
        }
        return res;
    }
};

int main(){
    vector<int> arr = {100, 200, 300, 400};
    int k=1;
    Solution S;
    cout << "MinTime to paint all the boards: " << S.minTime(arr,k);
}