#include <iostream>
#include <stack>
using namespace std;

/*
Traverse over a loop. if its a opening case.. add it to stack.. if its closing compare its relavant opening existence in stack.
edge : More close less opening -> Stack is empty as you check return false
More open, less close -> loop ends and stack is not empty - return false
*/
class Solution{
public:
    bool isvalidparanthesis(string s){
        stack<char> st;
        for(int i=0;i<s.size();i++){ // opening case
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else{ // closing case
                if(st.size()==0) return false;
                if( (st.top()=='(' && s[i]==')') ||
                    (st.top()=='[' && s[i]==']') ||
                    (st.top()=='{' && s[i]=='}') ){
                        st.pop();
                    }
                else{
                    return false;
                }

            }
        }
        return (st.size()==0);
    }
};

int main(){
    string str="()[]{";
    Solution S;
    cout << S.isvalidparanthesis(str);

}