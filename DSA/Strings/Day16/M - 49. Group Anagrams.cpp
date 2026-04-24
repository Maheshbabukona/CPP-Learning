/*
Input: strs = ["eat","tea","tan","ate","nat","bat"]

Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

So goal is to group the anagrams together. How do we say two words are anagrams -- either their sorts are equal or based on letter freq count.

APproach

For each word. store the letter freq count in the form of key -- for the same key -- keep adding its anagrams.
Finally add all the values to a res vector and return.

note -- while adding count to a string -- add # as a delimeter for each letters count.. why ? 1,11 counts == 111 and 11,1 counts ==111 this causes discreapancy -- so to separrate.
*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs){
    unordered_map<string,vector<string>> mp;
    for(auto&s : strs){
        vector<int> freq(26,0);

        for(char ch : s){
            freq[ch-'a']++;
        }
        //building key

        string key = "";
        for(int count: freq){
            key+=to_string(count)+"#";
        }

        mp[key].push_back(s);
    }

    vector<vector<string>> res;
    for(auto & it : mp){
        res.push_back(it.second);
    }
    return res;
}

int main(){
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> ans = groupAnagrams(strs);
    for(int i=0;i<ans.size();i++){
        for(string s: ans[i]){
            cout << s << ",";
        }
        cout << endl;
    }
}