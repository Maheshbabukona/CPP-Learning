#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector <int> &nums){
    int mid=0, high =nums.size()-1, low=0;
    while(mid<=high){
        if(nums[mid]==0){
            swap(nums[mid],nums[low]);
            mid++;
            low++;
        }
        else if(nums[mid]==1) mid++; // why ? -> 1s are in the range l to m -> let mid slide to next element
        else{
            swap(nums[mid],nums[high]);
            high--; // why not mid++ -> we are contracting from right.. so not needed. also swapped element is unknown, to be visisted.
        }
    }
}
int main(){
    vector<int> nums = {2,0,2,1,1,0};
    sortColors(nums);
    cout << "After sorting: ";
    for(int i=0;i<nums.size();i++){
        cout << nums[i] << " ";
    }
    cout << endl;

}