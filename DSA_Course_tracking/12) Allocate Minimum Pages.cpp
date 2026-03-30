// Book allocation problem

#include <iostream>
#include <vector>
using namespace std;

bool isvalid(vector<int> arr,int n,int m,int mid){ // mid = max allowed pages
    int stu=1,pages =0;
    for(int i=0;i<n;i++){
        if(arr[i]>mid) return false; // if any pages is greater than max allowed pages -> cannot distribute to all.
        if (pages+arr[i]<=mid){
            pages+=arr[i];
        }
        else{
            stu+=1;
            pages=arr[i];
        }
    }
    return stu>m ? false : true;
}
int allocateBooks(vector<int> &arr, int n, int m){
    if(m>n) return -1;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int st=0, end = sum; // range of possible answers
    int res=-1;
    while (st<=end){
        int mid = st+(end-st)/2;
        if (isvalid(arr,n,m,mid)){
            res = mid;
            end = mid-1;
        }
        else{
            st=mid+1;
        }
    }
    return res;

}                     

int main(){
    vector<int> arr = {12, 34, 67, 90};
    int n = arr.size(), m = 2;
    cout << "sol: " << allocateBooks(arr,n,m)<<endl;
}