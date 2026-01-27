#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int st, int end){
    int idx = -1,pivot=arr[end];
    for(int j=0;j<end;j++){
        if(arr[j]<=pivot){
            idx++;
            swap(arr[idx],arr[j]);
        }
    }
    // finally as we have all lower elements to the left of idx.. swap the next place with pivot
    idx++;
    swap(arr[idx],arr[end]);
    return idx;
}
void quick_sort(vector<int> &arr, int st, int end){
    if(st<end){
        int pivIdx =  partition(arr,st,end);
        quick_sort(arr,st,pivIdx-1);
        quick_sort(arr,pivIdx+1,end);
    }
}

int main(){
    vector<int> arr = {12,31,35,17,32,8};
    int st =0, end = arr.size()-1;
    quick_sort(arr,st,end);
    for(int val: arr){
        cout << val << " ";
    }
}