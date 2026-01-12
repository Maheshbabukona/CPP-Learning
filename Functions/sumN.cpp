#include <iostream>
using namespace std;

int sumN(int n){
    if (n==1) return 0;
    return n+ sumN(n-1);
}
int main(){
    int n =10;
    int Res = sumN(n);
    cout << Res << endl;
}