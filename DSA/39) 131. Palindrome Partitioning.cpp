/*
Goal is to find the possible splits which are palindrome..

We are gonna have a loop running for splitting the string into 2 at each branch. we check if the first split is palindrome  - if yes we add and call the next substring.. 
so why add only first split.. at last.. the final is after the final element..so checking and adding first split will do.
to backtrack.. we are at the pos where the first split is added so we remove it and make the index pass -> to get to next index split.

*/

#include <iostream>
#include <vector>
using namespace std;

bool ispalindrome(string part){
    int i=0,j=part.size()-1;
    while(i<j){
        if(part[i]!=part[j]) return false;
        i++,j--;
    }
    return true;
}
void helper(string s, vector<string> &partitions, vector<vector<string>> &ans){
    if(s.size()==0){
        ans.push_back(partitions);
        return;
    }
    for(int i=0;i<s.size();i++){
        string part = s.substr(0,i+1); // first split
        if(ispalindrome(part)){
            partitions.push_back(part);
            helper(s.substr(i+1),partitions,ans); // for remaining substr
            partitions.pop_back(); // to come back and process for next split.. previously added first split -- part should be removed.
        }
    }
}
vector<vector<string>> partition(string s){
    vector<string> partitions;
    vector<vector<string>> ans;
    helper(s,partitions,ans);
    return ans;
}
int main(){
    string s = "aab";
    vector<vector<string>> result = partition(s);
    cout << "[";
    for(int i=0;i<result.size();i++){
        cout << "[";
        for(int j=0;j<result[i].size();j++){
            cout << result[i][j];
            if(j<result[i].size()-1) cout << ",";
        }
        if (i<result.size()-1) cout << ",";
        cout << "]";
    }
    cout << "]";
}