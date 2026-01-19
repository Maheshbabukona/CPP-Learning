#include <iostream>
#include <vector>
using namespace std;

// we follow include, exclude approach.. at each step for each value we follow both include and exclude way.. which builds the tree down and reaches to subsets

void printsubsets(vector<int> &arr, vector<int> &ans, int i){
    if(i==arr.size()){
        for(int val : ans){
            cout << val << " ";
        }
        cout << endl;
        return;
    }
    ans.push_back(arr[i]); // include case
    printsubsets(arr,ans,i+1);

    ans.pop_back(); // removing the added element -- exclusion case
    printsubsets(arr,ans,i+1);
}

int main(){
    vector<int> arr = {1,2,3};
    vector<int> ans;
    printsubsets(arr,ans,0);
}