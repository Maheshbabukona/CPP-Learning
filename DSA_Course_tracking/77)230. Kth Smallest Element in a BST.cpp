#include <iostream>
#include <vector>
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

class BST{
    node* insert(node* root, int val){
        if(root==NULL) return new node(val);
        if(val<root->data){
            root->left = insert(root->left, val);
        }
        else{
            root->right = insert(root->right, val);
        }
        return root;
    }
public:
    node* buildBST(vector<int> &arr){
        node* root = NULL;
        for(int val : arr){
            root = insert(root,val);
        }
        return root;
    }
};
// BSt -> inorder -> sorted.. in sorted kth element is at idx-1 if idx starts from 0.. so find leftans, curans, right ans. 
// cur ans == if idx+1 == 0 return root->val --
// on left and right if leftans and rightans != -1 there exist a ans -- return that.
class Solution{
public:
    int idx =0;
    int kthSmallest(node* root, int k){
        if(root==NULL) return -1;
        if(root->left){
            int leftans = kthSmallest(root->left,k);
            if(leftans!=-1) return leftans;
        }
        if(idx+1==k) return root->data;
        if(root->right){
            int rightans = kthSmallest(root->right,k);
            if(rightans!=-1) return rightans;
        }

        return -1;
    }
};

int main(){
    vector<int> arr = {3,1,4,2};
    int k =1;
    BST bst;
    node* root = bst.buildBST(arr);
    Solution S;
    cout << "The "<< k << "st smallest element in BST is: "<< S.kthSmallest(root,k);
}
