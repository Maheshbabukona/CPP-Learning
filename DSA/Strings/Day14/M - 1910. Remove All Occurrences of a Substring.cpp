/*
s = "daabcbaabcbc", part = "abc" -- remove all occurances of part in s.  
1st occurance at index2 -- removed
s = "dabaabcbc" -- now at index 4 -- remove
s = "dababc" -- at index 3 -- remove
s = "dab" -- return this

*/

#include <iostream>
using namespace std;

string removeOccurrences(string s, string part){
    while(s.size()>0 && s.find(part)<s.size()){
        s.erase(s.find(part),part.size()); // erase(index,size)
    }
    return s;
}

int main(){
    string s = "daabcbaabcbc";
    string part = "abc";
    string res = removeOccurrences(s,part);
    cout << res;
}