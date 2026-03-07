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
private:
    node* insert(node* root, int val){
        if(root==NULL){
            return new node(val);
        }
        if(val<root->data){
            root->left = insert(root->left,val);
        }
        else{
            root->right = insert(root->right, val);
        }
        return root;
    }
public:
    node* buildBST(vector<int> arr){
        node* root = NULL;
        for(int val: arr){
            root = insert(root, val);
        }
        return root;
    }
};
/* inorder traversal -- go left find the min distance, 
for the current node -- you get a prev val from the left subtree the last visited node --right most is stored in prev-- which is subtracted from root -- to get curmin distance.. 
For right go right and find out the min distance. 
*/
class Solution{
public:
    node* prev = NULL;
    int minDiffInBST(node* root){
        // base - 
        int ans = INT32_MAX;
        if(root==NULL) return INT32_MAX;


        if(root->left!=NULL){
            int leftmin = minDiffInBST(root->left);
            ans = min(ans, leftmin);
        }
        if(prev!=NULL){
            ans = min(ans, root->data - prev->data);
        }
        prev = root;

        if(root->right!=NULL){
            int rightmin = minDiffInBST(root->right);
            ans = min(ans, rightmin);
        }

        return ans;
    }
};

int main(){
    vector<int> arr = {4,2,6,1,3};
    BST bst;
    node* root = bst.buildBST(arr);
    Solution S;
    cout << "Min dis between any nodes in the tree is: "<< S.minDiffInBST(root);
}