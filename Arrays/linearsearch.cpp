#include <iostream>
using namespace std;

int linearsearch(int arr[],int size, int k){
   for (int i=0; i< size; i++){
    if (arr[i]==k){
        return i;
    }
   }
   return -1;
}
int main(){
    int arr[5] = {1,2,3,4,5};
    int k = 4;
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << linearsearch(arr,size, k) << endl;
}