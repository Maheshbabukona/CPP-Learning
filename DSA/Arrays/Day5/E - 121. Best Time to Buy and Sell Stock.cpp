/*
For each price -- consider the min till now as bestbuy -- 
if curprice> bestbuy -- find the max profit
*/
#include<iostream>
#include<vector>
using namespace std;
int maxProfit(vector<int> &prices){
    int maxP=0, bestBuy = prices[0];
    for(int i=0;i<prices.size();i++){
        if(bestBuy<prices[i]){
            maxP = max(maxP, prices[i]-bestBuy);
        }
        bestBuy = min(bestBuy, prices[i]);
    }
    return maxP;
}

int main(){{
    vector<int> prices = {7,1,5,3,6,4};
    cout << "MaxProfit: " << maxProfit(prices);
}}