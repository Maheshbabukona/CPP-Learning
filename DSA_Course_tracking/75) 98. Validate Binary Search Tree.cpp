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

class BTree{
public:
    node* build(vector<int> &preorder){
        int idx =-1;
        return buildTree(preorder,idx);
    }
private:
    node* buildTree(vector<int> &preorder, int idx){
        idx++;
        if(preorder[idx]==-1) return NULL;
        node* root = new node(preorder[idx]);
        root->left = buildTree(preorder,idx);
        root->right = buildTree(preorder, idx);

        return root;
    }
};
/*
for a left child node, min val == -inf and max val == root val. and for a right child node, min val = root and max val can be +inf.

so we represent -inf and +inf with NULL which are the boundaries of root.. and then as we go down the boundaries depends on the parents.
*/
class Solution{
    bool helper(node* root, node* min, node* max){
        if(root==NULL) return true;

        if(min!=NULL && root->data <= min->data) return false;
        if(max!=NULL && root->data >= max->data) return false;

        return helper(root->left,min,root) && helper(root->right, root,max);
    }
public:
    bool isvalidBST(node* root){
        return helper(root,NULL,NULL);
    }
};

int main(){
    vector<int> preorder = {5,1,-1,-1,4,3,-1,-1,6,-1,-1};
    BTree T;
    node* root = T.build(preorder);
    Solution S;
    cout << "Is the given tree Valid: "<< S.isvalidBST(root);
}