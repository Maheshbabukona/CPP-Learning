/*
using map to find unique.. storing char and count. using queue -> to keep track of order.. since we need first unique
*/

#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution{
public:
    int firstuniquechar(string s){
        queue<int> q;
        unordered_map<char,int> m; // char and count

        for(int i=0;i<s.size();i++){
            m[s[i]]++;
            if(m[s[i]]==1){
                q.push(i);
            }
            else{
                while(!q.empty() && m[s[q.front()]]>1){
                    q.pop();
                }
            }
        }
        return (!q.empty()) ? q.front() : -1;
    }
};

int main(){
    string s = "level";
    Solution S;
    cout << "Index of unique char is: "  << S.firstuniquechar(s);
}