/*
Goal -- reverse the words in the string 
Approach
1) remove the spaces in the beginning if any
2) start the index with words start- go till words end -- add this substring to vector
3) remove trailing spaces.
4) reverse this vector
5) add all this words in reverse order with spaces into a string
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string reverseWords(string s){
    vector<string> words;
    int n=s.size();
    int idx=0;
    while(idx<n && s[idx]==' ') idx++; // remove spaces in the beginning
    while(idx<n){
        int start=idx;
        while(idx<n && s[idx]!=' ') idx++; // go till last index of word.
        words.push_back(s.substr(start,idx-start));
        while(idx<n && s[idx]==' ') idx++; // remove trailing spaces.
    }

    reverse(words.begin(),words.end());

    string result;
    for(int i=0;i<words.size()-1;i++){ // go till lastbutone word -- lastword does not need space after..
        result+=words[i]+" ";
    }
    result+=words.back();
    return result;
}

int main(){
    string s = "The Sky is Blue";
    string result = reverseWords(s);
    cout << result;
}