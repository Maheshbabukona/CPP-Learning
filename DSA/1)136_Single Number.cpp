#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int> & nums){ // & is used to pass vector nums as reference
    int res=0;
    for (int val : nums){
        res^=val;
    }
    return res;
}
int main(){
    vector<int> nums ={4,1,2,1,2};
    cout << "Unique number is " << singleNumber(nums);
}


/* explanation
        We use xor to find out the unique element, cause xor of same elements is 0, unique elements is 1...
        since there is only 1 unique element.. xor of all the other elements becomes 0 and 0 xor unique element is unqiue element.
*/
