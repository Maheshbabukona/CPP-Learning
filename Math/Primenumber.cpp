#include <iostream>
#include <vector>
using namespace std;

bool isprime(int num){ // gives you TLE
    if (num==1) return false;
    for(int i=2;i*i<=num;i++){
        if (num%i==0) return false;
    }
    return true;
}
// Optimized alg for prime is sieve of eratosthenes 
void optprime(int n){
    vector<bool> prime(n+1,true);
    int ans=0;
    for(int i =2;i<n;i++){
        if(prime[i]){
            ans++;
            cout << i << " ";
        }
        for(int j=i*2;j<n;j+=i){
            prime[j]=false;
        }
    }
    cout << "\nFinal count is: "<< ans;
}
int main(){
    int n;
    cout << "Enter the range of numbers: ";
    cin >> n;
    // for(int i =0;i<n;i++){
    //     if(isprime(i)) cout << i<< " ";
    // }
    // cout << endl;
    optprime(n);
}