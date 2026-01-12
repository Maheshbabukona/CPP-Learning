#include <iostream>
using namespace std;
int main(){
    int a;
    cout << "Enter the number";
    cin >> a;
    cout << ((a<1) ? "Not positive":(a%2==0) ? "Even":"Odd"); 
}