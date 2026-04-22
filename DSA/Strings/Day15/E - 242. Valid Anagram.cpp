/*
s = "anagram", t = "nagaram"
return true -- if its anagram.
anagram if -- the freq count of s and t are same.

approach 1 - sort both return true if same later
approach 2 - calculate freq for s -- increase the count for every char in it. for freq of t --decrease the count for every char in it --> so as to cancel out each other
             if at the end the freq >0 return false --> here instead of using 2 freq counters -- you are adding and decreasing for S and T --> to cancel out.
*/

#include <iostream>
#include <algorithm>
using namespace std;

class Solution{
public:
    bool isAnagram_sort(string s, string t){
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return (s==t);
    }

    bool isAnagram(string s, string t){
        if(s.size()!=t.size()) return false;
        int freq[26]={0};

        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }
        for(int j=0;j<t.size();j++){
            freq[s[j]-'a']--;
        }

        for(int i=0;i<26;i++){
            if(freq[i]>0) return false;
        }
        return true;
    }
};

int main(){
    string s = "anagram", t = "nagaram";
    Solution S;
    cout << "Using Sorting: Are S and T anagrams ? : " << ((S.isAnagram_sort(s,t)) ? "Yes" : "No") << endl;
    cout << "Using Freq couting: Are S and T anagrams ? : " << ((S.isAnagram(s,t)) ? "Yes" : "No");
}