#include <iostream>
using namespace std;

void reverse(int arr[],int size){
    for (int i=0;i<size/2; i++){ // to replace the pairs.. we replace elements of first half to second half.. half the size to avoid going to second half and replacing it to original
        int temp = arr[i];
        arr[i]=arr[size-1-i];
        arr[size-i-1]=temp;
    }
}
void twopointerreverse(int arr[], int size){ // two pointer solution having pointers at start and end.. and utilizing swap
    int start = 0;
    int end = size-1;
    while(start< end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}
int main(){
    int arr[5] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    reverse(arr,size);
    for(int i=0; i< size;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    twopointerreverse(arr,size);
    for(int i=0; i< size;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
