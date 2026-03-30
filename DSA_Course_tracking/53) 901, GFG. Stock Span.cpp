#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
Offline - we have array of all prices of stocks.
traverse, as you go add the index of price into stack. and 
each time find the prev high thats exisiting in the stack.. remove that are lower. so.. 
span becomes i-st.top()( contains the index of prev high). 
*/
class GFG{
public:
    vector<int> calculateSpan(vector<int> price){
        stack<int> st1;
        vector<int> ans;

        for(int i=0;i<price.size();i++){
            while(st1.size()>0 && price[st1.top()]<=price[i]){
                st1.pop();
            } // after this there can only be 2 cases - stack is empty and stack is not empty
            if(st1.size()==0) ans.push_back(i+1); // here.. either its first element or all the previous elements are lower
            else ans.push_back(i-st1.top()); // span is calculated from this index to backwards.. till we are hit with anything higher
            st1.push(i);
        }
        return ans;
    }
};

/*
online.. Here you dont have the next prices.. only backwards.. for each price function is called.
so have a globally declared stack.. store both price and span at each index.. 
while current price > exisitng prices in the stack.. increase the span.. and 
update the stack with current price and span.  and return span.
*/
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

