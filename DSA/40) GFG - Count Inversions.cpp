/*
Goal is to find the pairs where i<j and arr[i]>arr[j] it means left element is greater than right. 
So we follow merge sort approach.

as we have two sorted arrays left and right we compare i and j and anywhere if we find arr[i]>arr[j](else condition in mergesort)..
-> we are going to increase the count with invcount = mid-(i-1) // why every element after i is going to be >arr[j]..

This way we follow the same recursion process.. left array is further split and invcount is calculated -leftinvcount
right array is further split and invcount is calculated - right invcount
after both arrays are sorted..before we merge we are going to calculate the invcount 

and then return total invcount
*/
#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int> &arr, int st, int mid, int end){
    vector<int> temp;
    int i=st,j=mid+1;
    int invcount=0;
    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){ // here left elements are lower no invcount.. just add to temp
            temp.push_back(arr[i]);
            i++;
        }
        else{// here left elements are greater than right.. so invcount and add right elements.
            temp.push_back(arr[j]);
            j++;
            invcount+=mid-i+1;
        }
    }

    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=end){
        temp.push_back(arr[j]);
        j++;
    }

    for(int i=0;i<temp.size();i++){
        arr[st+i]=temp[i];
    }
    return invcount;
}

int mergesort(vector<int> &arr, int st, int end){
    if(st<end){
        int mid = st+(end-st)/2;
        int leftinvcount = mergesort(arr,st,mid); // inv count from left half before sorting
        int rightinvcount = mergesort(arr,mid+1,end); // inv count from right half before sorting
        int invcount = merge(arr, st,mid,end); // invcount as you merge both sorted arrays
        return leftinvcount+rightinvcount+invcount;
    }
    return 0;
}

int inversioncount(vector<int> &arr){
    return mergesort(arr,0,arr.size()-1);
}

int main(){
    vector<int> arr= {1,3,5,10,2,6,8,9};
    cout << inversioncount(arr);
}