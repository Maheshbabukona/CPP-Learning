#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int>& height){
    int area = 0, lp = 0, rp = height.size()-1;

    while(lp<rp){
        int cur_area = min(height[lp],height[rp]) * (rp-lp);
        area = max(area, cur_area);
        (height[lp]<height[rp]) ? lp++ : rp--;
    }
    return area;
}

int main(){
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << "Max Area possible: " << maxArea(height);
}