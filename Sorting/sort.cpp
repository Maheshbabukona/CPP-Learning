#include <iostream>
#include <vector>
using namespace std;
void bubblesort(vector<int> &arr, int n){
    for(int i=0;i<n-1;i++){
        bool isSwap = false;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                isSwap = true;
            }
        }
        if(!isSwap){ // in any iteration if no swapping occured it means the array is already sorted.
            return;
        }
    }
}
void selectionsort(vector<int> &arr, int n){
    for(int i=0;i<n-1;i++){
        int smallIdx = i; // assume 1st index of unsorted is smallest
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[smallIdx]) smallIdx=j;
        }
        swap(arr[i],arr[smallIdx]);
    }
}

void printarr(vector <int> &arr,int n){
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertionsort(vector<int> &arr, int n){
    for(int i=1;i<n;i++){
        int cur =arr[i];
        int prev=i-1;
        while(prev>=0 && arr[prev]>cur){
            arr[prev+1]=arr[prev];
            prev--;
        }
        arr[prev+1]=cur;
    }
}

int main(){
    vector <int> arr = {4,1,5,2,3};
    int n = arr.size();
    // bubblesort(arr,n);
    //selectionsort(arr,n);
    insertionsort(arr,n);
    printarr(arr,n);
}