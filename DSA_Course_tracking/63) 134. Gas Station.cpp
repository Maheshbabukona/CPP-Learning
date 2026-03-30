/*
known 

if total gas< total cost -> no ans exist return -1; --> for every other we know there exist a unique ans

goal - to find the viable starting index.. from where it is possible to complete round trip.

fact -> there cant be a case where gas and cost arrays are exactly same.. why -> then there can exist multiple starting points.

so few smaller and few larger.. So we need to start only from surplus gas nodes.

Approach - traverse.. store the curgas = gas[i]-cost[i] in a var. and start index in a var..
           if the cur gas <0  then that index cant be ans... so start= i+1, and curgas =0. and finally we get the index which remains at last.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int cancompletecircle(vector<int> &gas, vector<int> &cost){
        int total_gas=0, total_cost=0;
        for(int val: gas){
            total_gas+=val;
        }
        for(int val: cost){
            total_cost+=val;
        }

        if (total_gas<total_cost) return -1;
        int curGas =0;
        int start =0;
        for(int i=0;i<gas.size();i++){
            curGas+=gas[i]-cost[i];
            if(curGas<0){
                start=i+1;
                curGas=0;
            }
        }
        return start;
    }
};

int main(){
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};

    Solution S;
    cout << "Possible starting point is: " << S.cancompletecircle(gas, cost);
}