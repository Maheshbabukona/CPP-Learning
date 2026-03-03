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
        int idx = -1;
        return buildTree(preorder,idx);
    }
private:
    node* buildTree(vector<int> &preorder, int &idx){
        idx++;
        if(preorder[idx]==-1) return NULL;

        node* root = new node(preorder[idx]);
        root->left = buildTree(preorder, idx);
        root->right = buildTree(preorder,idx);
    }
};

/*
recursively travel for every node check if p and q exist in there left and right subtrees.
*/
class Solution{
public:
    node* lowestCommonAncestor(node* root, node* p, node* q){
        if(root==NULL) return NULL;
        if(root==p || root==q) return root;

        node* leftLCA = lowestCommonAncestor(root->left, p, q);
        node* rightLCA = lowestCommonAncestor(root->right, p, q);
        
        /*
        3 cases of returns
        1) if leftlca = p, and rightlca=q then this is the root we are searching for
        2) if leftlca = p and right lca = NULL then return leftlca -- to above parents
        3) if leftlca = NUll and rightlca =q then return rightlca -- to above parents
        */

        if(leftLCA && rightLCA) return root;
        else if(leftLCA!=NULL) return leftLCA;
        else return rightLCA;
        
    }
};

int main(){
    vector<int> preorder = {1,2,4,-1,-1,5,8,-1,-1,9,-1,-1,3,6,-1,-1,7,-1,-1};
    BTree T;
    node* root = T.build(preorder);

    node* p = root->left->left; // 4
    node* q = root->left->right->right; // 9

    Solution S;
    node* res = S.lowestCommonAncestor(root,p,q);

    cout << "LCA: " << res->data;
}