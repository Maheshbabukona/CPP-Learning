/*
If an array has a peak -- then there exist a mid where arr[i-1]<=arr[i]>=arr[i+1]
Binary search for that peak -- if the peak exists in the mid -- return the mid
if the mid exist in left half of mountain -- arr[i-1]<=arr[i] -- try searching on the right side -- st = mid+1
else if the mid exist in the right half -- search on the left side.

and peak doesnt exist on the edges
*/

#include <iostream>
#include <vector>
using namespace std;

int peakIndexInMountainArray(vector<int>& arr){
    int st=1, end = arr.size()-2;
    while(st<=end){
        int mid = st+(end-st)/2;
        if(arr[mid-1]<=arr[mid] && arr[mid]>=arr[mid+1]) return mid;
        else if(arr[mid-1]<=arr[mid]) st=mid+1; // mids on left -- search on right
        else end = mid-1; 
    }
    return -1;
}

int main(){
    vector<int> arr = {0,10,5,2};
    cout << "The peak index is : " << peakIndexInMountainArray(arr);
}