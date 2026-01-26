#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int st, int mid, int end){
    vector<int> temp;
    int i=st, j=mid+1;
    //comparing both left and right arrays
    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }

    }
    // one array will be left as the other array is arranged as sorted
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=end){
        temp.push_back(arr[j]);
        j++;
    }
    for(int idx=0;idx<temp.size();idx++){
        arr[st+idx]=temp[idx]; // temp contains elements from st-end in sorted from array.
    }

}

void divide(vector<int> &arr, int st, int end){ // recursion
    if(st<end){
        int mid = st+(end-st)/2;
        divide(arr,st,mid);// left half
        divide(arr,mid+1,end); // right half;
        merge(arr,st,mid,end);
    }

}

int main(){
    vector<int> arr = {12,31,35,8,17,32};
    int st=0,end=arr.size()-1;
    divide(arr,st,end);
    for(int val : arr){
        cout << val << " ";
    }
}

