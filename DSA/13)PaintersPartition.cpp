#include <iostream>
#include <vector>
using namespace std;

bool isvalid(vector <int> &arr, int n, int k, int mid){
    int p = 1, boards = 0;
    for(int i=0; i<n;i++){
        if(arr[i]>mid) return false;
        if(boards+arr[i]<=mid){
            boards+=arr[i];
        }
        else{
            p+=1;
            boards=arr[i];
        }

    }
    return p>k ? false: true;

}
int minTime(vector <int> &arr, int k){
    int n = arr.size();
    int sum =0, maxVal = INT16_MIN;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        maxVal=max(arr[i],maxVal);
    }
    int st=maxVal, end = sum;
    int res=-1;
    if (k>n) return -1;
    while(st<end){
        int mid = st+(end-st)/2;
        if (isvalid(arr,n,k,mid)){
            res=mid;
            end=mid-1;
        }
        else st=mid+1;
    }
    return res;
    
}

int main(){
    vector <int> arr = {5, 10, 30, 20, 15};
    int k=3;
    cout << "minTime to paint: "<< minTime(arr,k);
}