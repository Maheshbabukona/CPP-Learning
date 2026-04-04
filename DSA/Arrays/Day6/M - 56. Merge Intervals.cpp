/*
Sort to make the intervals sequential
while iterating there are only 2 cases 
1) overlap --
when current.end >= next.start.
then replace the current.end to max(current.end,next.end)
2) no overlap -- else case
there doesnt exist any interval that overlap with current -- so push it as final to ans.
and go for next interval -- current = interval[i]
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals){
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    vector<int> current = intervals[0];
    for(int i=0;i<intervals.size();i++){
        if(intervals[i][0]<=current[1]){ // overlap -- update the end timing.
            current[1] = max(intervals[i][1],current[1]);
        }
        else{
            // no overlap -- push the current to ans;
            ans.push_back(current);
            current = intervals[i];
        }
    }
    ans.push_back(current);
    return ans;
}

int main(){
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> res = merge(intervals);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}