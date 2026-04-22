/*
strs = ["flower","flow","flight"] --output - "fl" -- the longest common prefix.

consider strs[0] as prefix -- reduce one one char from last till it matches with prefix in next strs.. till last - if prefix.size=0 return ""
return prefix
*/

#include <iostream>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs){
    string prefix=strs[0];

    for(int i=1;i<strs.size();i++){
        while(strs[i].find(prefix)!=0){ // prefix not on index 0 -- so its not prefix
            prefix.pop_back();
        }
        if(prefix.empty()) return "";
    }
    return prefix;
}

int main(){
    vector<string> strs = {"flower","flow","flight"};
    string res = longestCommonPrefix(strs);
    cout << res;
}