#include <iostream>
using namespace std;

int fact(int n){
    if (n==1) return 1;
    return n*fact(n-1);
}

int ncr(int n, int r){
    return (fact(n))/((fact(r))*(fact(n-r)));
}
int main(){
    int n=6, r=3;
    cout << ncr(n,r) << endl;   
}