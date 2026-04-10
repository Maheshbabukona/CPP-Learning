/*
Goal - In a array find the inversion pairs count.
inversion pairs are those where i<j but a[i]>a[j] -- eg: [2, 4, 1, 3, 5] has three pairs - (2, 1), (4, 1), (4, 3)

Approach -
Use merge sort.
Divide the array into left, right -- count the inv count sepearately.. using recursion. Add the counts.
To count. while merging if a[i]<a[j] -- add a[i] as usual. but if a[i]>a[j] add the a[j] into temp. also inv count here will a[i],a[i++] till a[mid] since those all will be greater than a[j]
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
    int merge(vector<int> &arr, int st,int mid,int end){
        vector<int> temp;
        int i=st,j=mid+1;
        int invcount=0;
        while(i<=mid && j<=end){
            if(arr[i]<=arr[j]){
                temp.push_back(arr[i]);
                i++;
            }
            else{
                temp.push_back(arr[j]);
                j++;
                invcount+=mid-i+1; // count is from arr[i] --- till arr[mid] since all are greater than arr[j]
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
        int leftinvcount = mergesort(arr,st,mid);
        int rightinvcount = mergesort(arr,mid+1,end);
        int invcount = merge(arr,st,mid,end);
        return leftinvcount+invcount+rightinvcount;
    }
    return 0;
    }
public:
    int inversioncount(vector<int> &arr){
        return mergesort(arr,0,arr.size()-1);
    }

};

int main(){
    vector<int> arr = {2, 4, 1, 3, 5};
    Solution S;
    cout << "The Inverse count: "<< S.inversioncount(arr);
}