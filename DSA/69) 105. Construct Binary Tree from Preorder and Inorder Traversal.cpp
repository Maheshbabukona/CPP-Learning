#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;

    node(int val){
        data = val;
        left=right = NULL;
    }
};

/*
Without -1s in preorder we are not sure where the leaf node is so.. we use inorder.

Preorder -- root->left->right, Inorder -- left->root->right

As we traverse preorder, create each node.. now for that node we know which all nodes should be on the left and right from inorder.
*/

class Solution{
public:
    unordered_map<int,int> inIdx_map;
    node* helper(vector<int> &preorder, vector<int> &inorder, int &preIdx, int left, int right){
        if(left>right) return NULL;

        node* root = new node(preorder[preIdx]);
        int inIdx = inIdx_map[preorder[preIdx]]; // find the nodes index in inorder vector.. so now all the new nodes in the left are as part of leftsubtree and all the new nodes in the right are as part of right subtree..
        preIdx++;

        root->left = helper(preorder,inorder,preIdx, left, inIdx-1);
        root->right = helper(preorder, inorder, preIdx, inIdx+1, right);

        return root;
    }
    node* buildTree(vector<int> &preorder, vector<int> &inorder){
        for(int i=0;i<inorder.size();i++){
            inIdx_map[inorder[i]]=i;
        }
        int preIdx = 0;
        return helper(preorder,inorder,preIdx, 0, inorder.size()-1);
    }

    void preorder_traversal(node* root){
        if(root==NULL){
            cout << "NULL ";
            return;
        }
        cout << root->data << " ";
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
};

int main(){
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    Solution S;
    node* res = S.buildTree(preorder,inorder);
    S.preorder_traversal(res);
}