/*
Arr contains elements where each i depicts number of pages in a book. K = number of students
We need to find the minimum sequential order of pages that can be given to a student
So we do binary search on the range of total pages. 0-total pages.
lets say mid=allowed_pages .. and see if this number of pages can give valid allocation.
if it can give valid allcoation to all students --> its valid allocation.. now search on the left range -- to find even min allowed range.
else -- allocation is smaller so increase the range and search on the right

is valid logic.
loop around all the page counts in arr.. 
anytime if any count > allowed_pages(mid) -- return false -- cause this allocation is not possible.
add each page count to total page.. so if anytime it reaches greater than allowed_page count distribute to another student -- stu++
finally see if stu count < k -- if yes return true.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
    bool isvalid(vector<int> &arr, int n, int mid, int k){
        int stu=1,pages=0;
        
        for(int i=0;i<n;i++){
            if(arr[i]>mid) return false;

            if(pages+arr[i]<=mid){
                pages+=arr[i];
            }
            else{
                stu++;
                pages=arr[i];
            }
        }
        return stu>k ? false: true;
    }
public:
    int findPages(vector<int> &arr, int k){
        int n = arr.size();
        if(k>n) return -1;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        int st=0,end=sum;
        int res=-1;

        while(st<=end){
            int mid=st+(end-st)/2;
            if(isvalid(arr,n,mid,k)){
                res=mid;
                end=mid-1;
            }
            else{
                st=mid+1;
            }
        }
        return res;
    }
};

int main(){
    vector<int> arr = {12, 34, 67, 90};
    int k =2;
    Solution S;
    cout << "Min allocation: " << S.findPages(arr,k);
}