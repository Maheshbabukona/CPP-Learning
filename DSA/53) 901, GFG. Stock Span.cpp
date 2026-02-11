#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class GFG{
public:
    vector<int> calculateSpan(vector<int> price){
        stack<int> st1;
        vector<int> ans;

        for(int i=0;i<price.size();i++){
            while(st1.size()>0 && price[st1.top()]<=price[i]){
                st1.pop();
            }
            if(st1.size()==0) ans.push_back(i+1);
            else ans.push_back(i-st1.top());
            st1.push(i);
        }
        return ans;
    }
};

class Leetcode{
public:
    stack<pair<int,int>> st2; // {price, span}
    Leetcode(){

    }
    int next(int price){
        int span =1;

        while(st2.size()>0 && st2.top().first<=price){
            span+=st2.top().second;
            st2.pop();
        }
        st2.push({price,span});
        return span;
    }
};

int main(){
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};

    cout << "=== GFG Offline Version ===\n";
    GFG g;
    vector<int> res = g.calculateSpan(prices);
    for(int x : res){
        cout << x << " ";
    }
    cout << endl;

    cout << "\n=== LeetCode Online Version ===\n";
    Leetcode lc;
    for(int price : prices){
        cout << lc.next(price) << " ";
    }
    cout << endl;

    return 0;
}

