#include <iostream>
using namespace std;

int minoftwo(int a, int b){
    if (a<b){
        return a;
    }
    else if (b<a){
        return b;
    }
}
int main(){
    int a,b;
    cout << "Enter a"<< endl;
    cin >> a;
    cout << "Enter b" << endl;
    cin >> b;
    cout << "min of " << a << " & " << b << " = " << minoftwo(a,b) << endl;
}