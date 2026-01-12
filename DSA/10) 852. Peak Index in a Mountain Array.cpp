#include <iostream>
#include <vector>
using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {

    int st =1, end = arr.size()-2; // why -> peak doesnt exist in edges - > also we are comparing peak with before and after elements which cannot exist on edges

    while(st<=end){ // st and end can be equal -> can be length 3 and mid = st = end = peak
        int mid = st+ (end-st)/2;
        if (arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]) return mid; // Peak will be greater than both left and right element. 
        else if (arr[mid-1]<arr[mid]) st=mid+1; // if mid exist in left side, search the right side
        else end = mid-1; // if mid exist on right side, search the left side.
    }
    return -1;
}     

int main(){
    vector<int> arr = {0,1,2,0};
    cout << "peak is at: " << peakIndexInMountainArray(arr) << endl;
}
