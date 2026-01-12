#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isvalid(vector<int> &arr, int n, int c, int mid){
    int cows =1,lastpos = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]-lastpos>=mid){
            cows+=1;
            lastpos = arr[i];
        }
        if(cows == c) return true;
    }
    return false;
}

int aggressivecows(vector <int> &arr, int c){
    int n = arr.size();
    sort(arr.begin(),arr.end());
    int st =1, end = arr[n-1]-arr[0], res = -1;
    while(st<=end){
        int mid = st+(end-st)/2;
        if(isvalid(arr,n,c,mid)){
            res=mid;
            st=mid+1; // aim is to maximize the distance -> so search right to find larger
        }
        else end=mid-1;
    }
    return res;
}

int main(){
    vector <int> arr = {1,2,8,4,9};
    int c =3;
    cout << "Max distance possible is: " << aggressivecows(arr,c)<< endl;
}