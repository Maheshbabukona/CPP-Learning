#include <iostream>
using namespace std;

double myPow(double x, int n){
    long binForm = n;  // long is required.. n can be = 2pow(-31) which overflows 32bit int.
    // base case
    if(n==0) return 1.0; // anything power 0 = 1
    if(x==0) return 0.0; // 0 power anything =0
    if(x==1) return 1.0; // 1 power anything = 1
    if(x==-1 && n%2==0) return 1.0; // -1 power even number = 1
    if(x==-1 && n%2!=0) return -1.0; // -1 power odd number = -1

    // if the pow n is negative -> pow(x,-n) = pow(1/x,n)
    if(n<0){
        x=1/x;
        binForm=-binForm;
    }
    double ans = 1;
    while(binForm>0){
        if(binForm%2==1){ // you only calculate when bin digit is 1 if its 0 you skip
            ans*=x;
        }
        x*=x; // pow gets doubled..
        binForm/=2;
    }
    return ans;

}

int main(){
    double x =2.00000;
    int n = 10;
    cout << "Ans: " << myPow(x,n) << endl;
}