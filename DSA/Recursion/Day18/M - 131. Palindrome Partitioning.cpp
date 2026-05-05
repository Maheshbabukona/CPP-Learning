/*
given s = "aab", Output: [["a","a","b"],["aa","b"]] -- output all possible palindrome substrings.
Approach.

iterate through sizes from 0 to n.. split the array into 2 parts -- left - 0<>i and i<->n and check if the left one is palindrome -- add it to partitions.
and for right one -- pass it to recursion -- so recursively split the right again into substrings -- and then check every left --- add them to partitions. as soon as you hit 0 size string.
you have one combination of substrs.. add them to ans.. backtrack to use other size combis
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
    bool ispalindrome(string part){
        int i=0,j=part.size()-1;
        while(i<j){
            if(part[i]!=part[j]) return false;
            i++;j--;
        }
        return true;
    }
    void helper(string s, vector<string> &partitions, vector<vector<string>> &ans){
        if(s.size()==0){
            ans.push_back(partitions);
            return;
        }
        int n = s.size();
        for(int i=0;i<n;i++){
            string part = s.substr(0,i+1);
            if(ispalindrome(part)){
                partitions.push_back(part);
                helper(s.substr(i+1,n),partitions,ans);
                partitions.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s){
        vector<string> partitions;
        vector<vector<string>> ans;
        helper(s,partitions,ans);
        return ans;
    }
};

int main(){
    string s = "aab";
    Solution S;
    vector<vector<string>> res = S.partition(s);
    for(int i=0;i<res.size();i++){
        for(auto strs : res[i]){
            cout << strs << ",";
        }
        cout << endl;
    }
}