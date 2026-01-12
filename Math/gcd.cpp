#include <iostream>
using namespace std;

int euclids(int a, int b){
    if(a==0) return b;
    else if(b==0) return a;
    else{
        if(a>b) return euclids(a%b,b);
        else return euclids(a,b%a);
    }
}
int lcm(int a, int b){
    return abs(a*b)/euclids(a,b);
}

int main(){
    int a, b;
    cin >> a >> b;
    cout << "gcd is: " << euclids(a,b) << endl;
    cout << "lcm is: " << lcm(a,b) << endl;
}