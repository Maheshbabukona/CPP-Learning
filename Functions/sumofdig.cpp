#include <iostream>
using namespace std;

int sumofdig(int n){
    int res=0;
    while (n>1){
        res+=n%10;
        n/=10;
    }
    return res;
}

int main(){
    int n = 1234;
    cout << sumofdig(n) << endl;
}