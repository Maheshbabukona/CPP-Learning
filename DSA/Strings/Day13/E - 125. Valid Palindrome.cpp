/*
One - check if each character is alphanum. -- if it isnt move to the next char.
if it is compare lowercase of both.. if doesnt match return false
*/

#include <iostream>
using namespace std;

class Solution{
    bool isalphanum(char ch){
        if((ch>='0' && ch<='9') || (tolower(ch)>='a' && tolower(ch)<='z')) return true;
        return false;
    }
public:
    bool isPalindrome(string s){
        int st=0,end = s.size()-1;

        while(st<end){
            if(!isalphanum(s[st])) {st++;continue;}
            if(!isalphanum(s[end])) {end--;continue;}
            if(tolower(s[st])!=tolower(s[end])) return false;
            st++;end--;
        }
        return true;
    }
};

int main(){
    string s = "A man, a plan, a canal: Panama";
    Solution S;
    cout << "Is it a Palindrome? " << ((S.isPalindrome(s)) ? "Yes":"No");
}