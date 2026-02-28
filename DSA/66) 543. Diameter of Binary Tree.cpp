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
        return buildTree(preorder, idx);
    }

private:
    node* buildTree(vector<int> &preorder, int &idx){
        idx++;
        if(preorder[idx]==-1) return NULL;

        node* root = new node(preorder[idx]);
        root->left = buildTree(preorder,idx);
        root->right = buildTree(preorder,idx);

        return root;
    }
};

/*
Diameter - the longest path between any two nodes. The longest path can be if nodes are leaf nodes.
diameter can be 
1) passing through root -> diameter = max height of left subtree + max height of right subtree
2) passing throght node of left subtree -> recursion passed to left subtree
3) passing through node of right subtree -> recursion passed to right subtree

Above approach - O(n2)

Instead -> we anyway trying to find diameter passing through root, left subtree, right subtree.

why not calculate it for every node. because we are trying to calculate leftheight, rightheight for every node using height function.
Just by including a global max comparing leftht+rightht and ans everytime can give us max global diameter.
*/
class Solution{
public:
    int ans=0;
    int height(node* root){
        if(root==NULL) return 0;

        int leftHt = height(root->left);
        int rightHt = height(root->right);
        ans = max(leftHt+rightHt,ans);
        return max(leftHt,rightHt)+1;
    }

    int diameterOfBinaryTree(node* root){

        // if(root==NULL) return 0;

        // int leftdiam = diameterOfBinaryTree(root->left);
        // int rightdiam = diameterOfBinaryTree(root->right);
        // int curdiam = height(root->left)+height(root->right);

        // return max(curdiam, max(leftdiam,rightdiam));

        height(root);
        return ans;
    }
};

int main(){

    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    BTree T;
    node* root = T.build(preorder);

    Solution S;
    cout << "height of the tree is: "<< S.diameterOfBinaryTree(root); 
}
