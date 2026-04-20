/*
s = "ADOBECODEBANC", t = "ABC" -- goal is to find out substr of s thats having t in any order,

Approach -- store the counts of els in t in a map.. these are greater than 0

Use 2 pointers i,j -- j moves right - increases the window size till all elements are found. Each time you increase -- m[ch]-- > why this el is found so decrease the count -- not required
once found i -- starts moving shrinking the window till the required elements go missing. -- m[ch]++ > why this el is removed -- so required -- thus increase the count.

anywhere if reqcount is ==0 then compare and consider the minwindow size. -- track the starting index of this minwindow

atlast return the minwindow size

*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

string minWindow(string s, string t){
    int n=s.size();
    unordered_map<char,int> m; // <char,count>

    if(t.size()>n) return "";

    // initialize m with counts of t -- which makes this els count>0
    for(char ch: t){
        m[ch]++;
    }
    int req_count=t.size();    
    int i=0,j=0;
    int start_i=0;
    int min_win_size=INT32_MAX;

    while(j<n){
        if(m[s[j]]>0){ // if the t el is found 
            req_count--;
        }
        m[s[j]]--; // for all els count --.. els which are not in t go ve--;

        while(req_count==0){ // shrink the size till reqcount==0
            int cur_win = j-i+1;
            if(min_win_size>cur_win){ // reqcount is 0 so check if you landed on minwinsize than earlier.
                min_win_size=cur_win;
                start_i=i;
            }
            m[s[i]]++; // since you are removing els they might be required -- so count ++

            if(m[s[i]]>0){ // anytime if count > 0 then you removed el from t's 
                req_count++;
            }
            i++;
        }
        j++;
    }
    return (min_win_size==INT32_MAX) ? "":s.substr(start_i,min_win_size);
}

int main(){
    string s = "ADOBECODEBANC", t = "ABC";
    string res = minWindow(s,t);
    cout << res;
}