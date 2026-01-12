#include <iostream>
using namespace std;
int main(){
    int size=5;
    int arr[size];
    for (int i =0;i<size;i++){
        cin >> arr[i];
    }
    int min = arr[0];
    int max = arr[0];
    for (int i : arr){
        if (i<min){
            min = i;
        }
        if (i>max){
            max = i;
        }  
    }
    cout << "min is " << min << endl;
    cout << "max is " << max << endl;
}