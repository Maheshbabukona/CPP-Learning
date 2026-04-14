/*
Goal - to find the max lenght of substring with unique characters.
approach -- use map<char,index> to find the duplicates.
have 2 pointers l, r -- r iterates -- the right index of window.
l - is updated on finding/hitting the dup
maxlen - max(maxlen,r-l+1)

to update the l-- on occurance of dup. push it by 1 of last found index.
eg: abca -- here as we hit a second time.. update the l to 0(index of 1st a in map)+1 

also update l only if its more than previous updated l-- to not go backward..
eg: abba -- here first b is hit and l - 2
and then a is hit -- if we follow previous alg -- l becomes 1 -- moving backward..
So --- l = max(l, m[s[r]]+1)
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s){
    unordered_map<char,int> m;
    int l=0,maxlen=0;
    for(int r=0;r<s.size();r++){
        if(m.find(s[r])!=m.end()){
            l=max(l,m[s[r]]+1);
        }
        m[s[r]]=r;
        maxlen= max(maxlen,r-l+1);
    }
    return maxlen;
}

int main(){
    string s = "abcabcbb";
    cout << "Max unique substring length: " << lengthOfLongestSubstring(s);
}