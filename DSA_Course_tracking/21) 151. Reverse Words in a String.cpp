#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string revwords(string s){
    vector<string> words;
    int n = s.length();
    int idx =0;
    while(idx<n && s[idx]==' ')idx++; // removes spaces in the begining
    while(idx<n){
        int start = idx;
        while(idx<n && s[idx]!=' ')idx++;
        words.push_back(s.substr(start, idx-start)); // adds the substr to words vector
        while(idx<n && s[idx]==' ')idx++; //removes trailing spaces
    }
    // reverse the vector add spaces in between.
    reverse(words.begin(),words.end());
    string result;
    for(size_t i=0;i<words.size()-1;i++){ // why till i-1.. cause after last word we dont need space so we add separately
        result+=words[i]+ " ";
    }
    result+=words.back(); // add last string
    return result;
}
int main(){
    string s = "the sky is blue";
    cout << revwords(s)<< "\nits size is: "<< revwords(s).size()<<endl;
}