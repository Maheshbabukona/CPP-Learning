/*
s1 = "ab", s2 = "eidbaooo"
Return true - if s1(ab) or permutation of s1(ba) is in s2..

Approach
calculate freq1 - the char freq of s1
have a window running on s2 of len s1--window size.. on each window calculate the char freq -- compare it with freq1. if any hit -- return true
*/

#include <iostream>
using namespace std;

class Solution{
    bool issamefreq(int freq1[], int freq2[]){
        for(int i=0;i<26;i++){
            if(freq1[i]!=freq2[i]) return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2){
        int freq1[26]={0};
        for(int i=0;i<s1.size();i++){
            freq1[s1[i]-'a']++;
        }

        int winsize=s1.size();
        for(int i=0;i<s2.size();i++){
            int winidx = 0, idx=i;
            int winfreq[26]={0};
            while(winidx<winsize && idx<s2.size()){
                winfreq[s2[idx]-'a']++;
                winidx++;idx++;
            }

            if(issamefreq(freq1,winfreq)) return true;
        }
        return false;
    } 
};

int main(){
    string s1 = "ab", s2 = "eidbaooo";
    Solution S;
    cout << "Is S1/ perm(S1) a Substr of S2? : "<< ((S.checkInclusion(s1,s2)) ? "Yes":"No");
}