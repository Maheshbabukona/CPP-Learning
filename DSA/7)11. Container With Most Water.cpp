#include <iostream>
#include <vector>
using namespace std;

int brutemaxArea(vector<int> &height){
    int maxArea = 0;
    for(int i =0;i<height.size();i++){
        for (int j=i+1;j<height.size();j++){
            maxArea = max(maxArea,(j-i)*min(height[i],height[j]));
        }
    }
    return maxArea;
}

int twopointerOPT(vector<int> &height){
    int maxArea =0;
    int l =0, r = height.size()-1;
    while (l<r){
        int cur = min(height[l],height[r]) * (r-l);
        maxArea = max(maxArea, cur);
        height[l]<height[r] ? l++ : r--;
    }
    return maxArea;
}
    


int main(){
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout <<  brutemaxArea(height) << endl;
    cout << twopointerOPT(height) << endl;
} 