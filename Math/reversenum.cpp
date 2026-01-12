#include <iostream>
using namespace std;

int reversenum(int n){
    int reverse_n=0;
    while(n!=0){
        reverse_n = reverse_n*10 + n%10;
        n/=10;
    }
    return reverse_n;
}

bool ispalindrome(int n){
    return (reversenum(n)==n) ? true : false;
}
int main(){
    int n = 7354;
    cout << "Reverse of " << n << " is: " << reversenum(n)<< endl;
    cout << ((ispalindrome(n)) ? true : false);
}