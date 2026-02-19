/*
if arr[i][j]==1 => ith person knows jth person
there exist a celeb who is known to everyone but he knows none. That means for all i arr[i][celeb]=1 and arr[celeb][i]=0

So we store all indexes in a stack. pass in pairs.. find the potential celeb from the pair. if yes we push it again.
and compare with other elements as pairs.. and finally have one celeb.

Atlast - we iterate and see if arr[i][celeb]=1 and arr[celeb][i]=0 is true.. if yes we found celeb. else -1

*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution{
public:
    int celebrity(vector<vector<int>> mat){
        stack<int> s;
        int n=mat.size();
        for(int i=0;i<n;i++){ // add all indices to stack
            s.push(i);
        }
        // we choose pairs till there exist only 1 element.. - celeb
        while(s.size()>1){
            int i=s.top();
            s.pop();
            int j=s.top();
            s.pop();

            if(mat[i][j]==0){
                s.push(i); // i dont know j -> potential celeb -> push to stack
            }
            else s.push(j); // j is known to i -> potential celeb ->push to stack
        }
        // as output -- we have only 1 element. 
        int celeb = s.top();

        // find if celeb is really celeb by checking the conditions
        for(int i=0;i<n;i++){
            if((i!=celeb) && (mat[i][celeb]==0 || mat[celeb][i]==1)){ // Noone knowing celeb || celeb knowing someone
                return -1;
            }
        }
        return celeb;
    }
};

int main(){
    vector<vector<int>> mat = {{1, 1, 0},
                {0, 1, 0},
                {0, 1, 1}};
    Solution S;
    cout << "Celeb is: "<< S.celebrity(mat); 
}

