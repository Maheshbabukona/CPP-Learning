#include <iostream>
#include <vector>
using namespace std;

void mergesortedarrays(vector<int> &nums1, int m, vector<int> &nums2, int n){
    int i=m-1, j= n-1, cur = m+n-1;
    while(j>=0){
        if(i>=0 && nums1[i]>=nums2[j]){
            nums1[cur]=nums1[i];
            i--;
            cur--;
        }
        else{
            nums1[cur]=nums2[j];
            j--;
            cur--;
        }
    }
}

int main(){
    vector<int> nums1 = {1,2,3,0,0,0}, nums2 = {2,5,6};
    int m =3, n=3;
    mergesortedarrays(nums1,m,nums2,n);
    cout << "After merge:\n";
    for(int i=0;i<m+n;i++){
        cout<< nums1[i] << " ";
    }
    cout<< endl;
}