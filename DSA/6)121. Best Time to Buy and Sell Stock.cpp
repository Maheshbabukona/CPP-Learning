#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector <int> & prices){
    int MaxP = 0, bestBuy = prices[0];
    for(int i = 1; i<prices.size();i++){
        if (prices[i]>bestBuy){
            MaxP = max(MaxP, prices[i]-bestBuy);
        }
        bestBuy = min(bestBuy, prices[i]);
    }
    return MaxP;
}

int main(){
    vector <int> prices = {7,1,5,3,6,4};
    cout << "Maxprofit: " << maxProfit(prices) << endl;

}