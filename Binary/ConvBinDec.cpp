#include <iostream>
using namespace std;
int DectoBin(int DecN){
    int res=0,pow=1;
    while(DecN >0){
        int rem = DecN%2;
        DecN = DecN/2;
        res+=(rem*pow);
        pow*=10;
    }
    return res;
}
int BintoDec(int BinN){
    int ans=0,pow=1;
    while (BinN > 0){
        int rem = BinN%10;
        BinN = BinN/10;
        ans+=(rem*pow);
        pow*=2;
    }
    return ans;
}
int main(){
    int DecN = 6, BinN =110;
    cout << "Dec to Bin of " << DecN << " = " << DectoBin(DecN) << endl;
    cout << "Bin to Dec of " << BinN << " = " << BintoDec(BinN) << endl;
    return 0;
}