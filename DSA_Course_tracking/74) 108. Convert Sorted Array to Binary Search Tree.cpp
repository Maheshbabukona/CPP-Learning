#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;

    node(int val){
        data = val;
        left = right = NULL;
    }
};
// Given -- a sorted array -- we build a BALANCED binary search tree... -- to keep it balanced on both sides at each step we build the mid node as root.
class Solution{
public:
    node* sortedArrayBST(vector<int> &nums){
        return helper(nums,0,nums.size());
    }
private:
    node* helper(vector<int> &nums, int st,int end){
        if(st>end) return NULL;
        int mid = st+(end-st)/2;
        node* root = new node(nums[mid]);
        root->left = helper(nums,st,mid-1);
        root->right = helper(nums,mid+1,end);

        return root;
    }
};

void LevelTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(q.size()>0){
        node* cur = q.front();
        q.pop();

        if(cur==NULL){
            if(!q.empty()){
                cout << endl;
                q.push(NULL);
                continue;
            }
            else break;
        }

        cout << cur->data << " ";
        if(cur->left!=NULL){
            q.push(cur->left);

        }
        if(cur->right!=NULL){
            q.push(cur->right);
        }
    }
}

int main(){
    vector<int> nums = {-10,-3,0,5,9};
    Solution S;
    node* root = S.sortedArrayBST(nums);
    LevelTraversal(root);
}