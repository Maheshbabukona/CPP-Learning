/*
chars = ["a","a","b","b","c","c","c"] -- then output should be a2b2c3 
how do you do it. have idx which adds char and count.
have i which iterates and counts.
and since we can have count>10 multiple digits they should be counted 1 for each digit -- convert to string and add each digit,

and finally return the idx -- its the last changed and why not chars.size()
eg: above case a2b2c3[c] -- c is left behind even after change -- we updated cs first with char second wiht count -- third is left at -- desired to be ignored.
So return the len -- based on your changes.
*/

#include <iostream>
#include <vector>
using namespace std;

int compress(vector<char>& chars){
    int idx=0;
    int i=0,n = chars.size();
    while(i<n){
        char ch = chars[i];
        int count = 0;
        while(i<n && chars[i]==ch){
            count++;i++;
        }
        chars[idx++]=ch; // update the first index with ch
        if(count>1){
            string s_count = to_string(count);
            for(char dig : s_count){
                chars[idx++]=dig; // add digits one at a index
            }
        }
    }
    return idx; // last updated with dig
}

int main(){
    vector<char> chars = {'a','a','b','b','c','c','c'};
    cout << "Len after compression: " << compress(chars);
}