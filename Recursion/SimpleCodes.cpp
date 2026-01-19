#include <iostream>
#include <vector>
using namespace std;

int factorial(int n){
    if(n==1) return 1;
    return n*factorial(n-1);
}

int sumofn(int n){
    if(n==1) return 1;
    return n+sumofn(n-1);
}
int fibonacci(int n){
    if(n==0 || n==1) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

int issorted(vector<int> &nums, int n){
    if(n==0 || n==1) return true; // 1 element is already sorted.. no need to sort for 0 elements.
    return nums[n-1]>=nums[n-2] && issorted(nums, n-1);
}

int binarysearchrecursion(vector<int> &nums, int st, int end, int target){
    if (st>end) return -1;
    int mid = st+(end-st)/2;
    
    if (nums[mid]==target) return mid;
    return (nums[mid]>target) ? binarysearchrecursion(nums, st, mid-1,target) : binarysearchrecursion(nums,mid+1,end,target);
}

int main(){
    int n =5;
    vector<int> nums = {1,2,8,3,4,5};
    cout << "Factorial of "<< n << " is "<< factorial(n)<< endl;
    cout << "Sum of 10 numbers: " << sumofn(10)<< endl;
    cout << "Fibonacci till "<<n<< " is: "<< fibonacci(n)<< endl;
    cout << "Is nums sorted? " << ((issorted(nums, nums.size())) ? "Yes" : "No" )<< endl; 
    int target = 8;
    cout << "Target: "<< target << " is found at "<< binarysearchrecursion(nums,0,nums.size()-1,target)<<endl;
} 