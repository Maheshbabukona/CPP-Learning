// Kadanes algorithm
#include <iostream>
using namespace std;

int max_subsum(int arr[], int n){ // brute force.
    int max_sum=0;
    for( int st=0;st<n;st++){
        int cursum=0;
        for (int end=st;end<n;end++){
            cursum+=arr[end];
            max_sum = max(cursum,max_sum);
        }
    }
    return max_sum;
}

int kadanes(int arr[], int n){
    int max_sum = INT8_MIN;
    int cursum=0;
    for( int i=0; i <n;i++){
        cursum+=arr[i];
        max_sum = max(cursum,max_sum);  // recording the max first before making cursum to zero.. there can be scenario where max_sum can be negative.
        if (cursum<0) cursum=0;
        
    }
    return max_sum;
}

int main(){
    int arr[] = {3,-4,5,4,-1,7,-8};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << max_subsum(arr, n)<< endl;
    cout << kadanes(arr,n)<< endl;
}
